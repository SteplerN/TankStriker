export module Entity;

import std;
import sfml;

import Usings;
import Enums;

export class Entity
{

protected:

	FrameListCollection m_FrameList;
	HitBoxCollection m_HitBoxList;

	int32_t m_CurrentFrameNumber = 0;
	int32_t m_RenderPriority = 0;

public:

	virtual void doRoutine(float p_Time, float p_DeltaTime) = 0;

	const int32_t seeRenderPriority() const
	{
		return m_RenderPriority;
	}

	void setFrameList(FrameListCollection& p_FrameList)
	{
		m_FrameList = p_FrameList;
	}

	int32_t getCurrentFrameNumber() const noexcept
	{
		return m_CurrentFrameNumber;
	}

	const FrameListCollection& getFrameList() const
	{
		return m_FrameList;
	}

	std::optional<std::vector<std::shared_ptr<HitBox>>> getCurrentHitBoxList() const
	{
		if (!m_HitBoxList.empty())
			return m_HitBoxList[m_CurrentFrameNumber];
		else
			return std::nullopt;
	}

	void setPositionOfEntity(float p_X, float p_Y)
	{
		for (auto& current_frame : m_FrameList)
		{
			current_frame->setPosition(p_X, p_Y);
		}

		if (!m_HitBoxList.empty())
		{
			for (auto& current_list : m_HitBoxList)
			{
				for (auto& current_hitbox : current_list)
				{
					current_hitbox->setPosition(p_X, p_Y);
				}
			}
		}
	}

	auto getPositionOfEntity() noexcept
	{
		return m_FrameList[m_CurrentFrameNumber]->getGlobalBounds();
	}

	void moveEntity(float p_X, float p_Y)
	{
		for (auto& current_frame : m_FrameList)
		{
			current_frame->move(p_X, p_Y);
		}

		if (!m_HitBoxList.empty())
		{
			for (auto& current_list : m_HitBoxList)
			{
				for (auto& current_hitbox : current_list)
				{
					current_hitbox->move(p_X, p_Y);
				}
			}
		}
	}

	const std::shared_ptr<sf::Sprite>& seeCurrentFrame()
	{
		return m_FrameList[m_CurrentFrameNumber];
	}

	virtual ~Entity() = default;

};