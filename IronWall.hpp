#pragma once

#include "Entity.hpp"

class IronWall : public Entity
{

public:

	IronWall(float p_X, float p_Y, FrameListCollection& p_FrameList, int16_t p_RenderPriority = 0)
	{
		m_RenderPriority = p_RenderPriority;
		m_FrameList = p_FrameList;
		setPositionOfEntity(p_X, p_Y);
	}

	void doRoutine() override
	{

	}

	void doAnimationRoutine() override 
	{

	}

};