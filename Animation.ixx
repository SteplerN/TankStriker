export module Animation;

import stl;
import sfml;

import Usings;
import Entity;
import Enums;

export class Animation : public Entity
{

protected:

	TimeListCollection m_TimeList;

	sf::Clock m_TimeFromStart;
	sf::Clock m_TimeFromCurrentFrameStartedPlaying;

	int16_t m_HowManyTimesPlayed = 0;

	bool m_IsAnimationPlaying = false;
	bool m_IsDisappearing = false;

public:

	virtual void finishIterationOfAnimation() = 0;

	Animation() = default;

	void doAnimationRoutine() override {}

	void doRoutine() override
	{
		doAnimationRoutine();
	}

	void playAnimation()
	{
		m_CurrentFrameNumber = 0;
		m_IsAnimationPlaying = true;
		m_TimeFromStart.restart();
		m_TimeFromCurrentFrameStartedPlaying.restart();
	}

	~Animation() override = default;
};