export module FinishedAnimation;

import stl;
import sfml;
import Usings;

import Animation;
import Enums;

export class FinishedAnimation : public Animation
{

protected:

public:

	FinishedAnimation(float p_X, float p_Y, FrameListCollection& p_FrameList,
		TimeListCollection& p_TimeList, int16_t p_RenderPriority, bool p_IsDisappearing)
	{

		if (p_IsDisappearing)
		{
			sf::Texture nullptr_texture;
			nullptr_texture.loadFromFile("assets/nullptr_sprite");
			auto nullptr_sprite = std::make_shared<sf::Sprite>(nullptr_texture);
			p_FrameList.push_back(nullptr_sprite);
		}

		m_FrameList = p_FrameList;
		m_TimeList = p_TimeList;
		m_IsDisappearing = p_IsDisappearing;
		m_RenderPriority = p_RenderPriority;
		setPositionOfEntity(p_X, p_Y);
		playAnimation();
	}

	void finishIterationOfAnimation() override
	{
		m_IsAnimationPlaying = false;
		++m_HowManyTimesPlayed;

		if (m_IsDisappearing)
		{
			m_CurrentFrameNumber = static_cast<int16_t>(m_FrameList.size()) - 1;
		}
	}

	void doAnimationRoutine() override
	{

		if (m_IsAnimationPlaying)
		{
			bool isAfterLastFrame = false;
			if (m_TimeFromCurrentFrameStartedPlaying.getElapsedTime().asMicroseconds()
			>= m_TimeList[m_CurrentFrameNumber]->asMicroseconds())
			{
				int k = static_cast<int>(m_IsDisappearing) + 1;
				m_TimeFromCurrentFrameStartedPlaying.restart();
				if (m_CurrentFrameNumber != (m_FrameList.size() - k))
				{
					++m_CurrentFrameNumber;
				}
				else
				{
					isAfterLastFrame = true;
				}
			}

			if (!isAfterLastFrame) return;

			finishIterationOfAnimation();

		}

	}

};