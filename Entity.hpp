#pragma once

#include <vector>
#include <cstdint>
#include <memory>

#include <SFML/Graphics.hpp>

using FrameListCollection = std::vector<std::shared_ptr<sf::Sprite>>;

class Entity
{

protected:

	FrameListCollection m_FrameList;
	int16_t m_CurrentFrameNumber = 0;
	int16_t m_RenderPriority = 0;

public:

	virtual void doRoutine() = 0;
	virtual void doAnimationRoutine() = 0;

	const auto& seeRenderPriority()
	{
		return m_RenderPriority;
	}

	void setFrameList(FrameListCollection& p_FrameList)
	{
		m_FrameList = p_FrameList;
	}

	int16_t getCurrentFrameNumber() const
	{
		return m_CurrentFrameNumber;
	}

	const auto& getFrameList()
	{
		return m_FrameList;
	}

	void setPositionOfEntity(float p_X, float p_Y)
	{
		for (auto& current_frame : m_FrameList)
		{
			current_frame->setPosition(p_X, p_Y);
		}
	}

	void moveEntity(float p_X, float p_Y)
	{
		for (auto& current_frame : m_FrameList)
		{
			current_frame->move(p_X, p_Y);
		}
	}

	const auto& seeCurrentFrame()
	{
		return m_FrameList[m_CurrentFrameNumber];
	}

};