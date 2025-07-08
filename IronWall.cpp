#include "IronWall.hpp"

IronWall::IronWall(float p_X, float p_Y, FrameListCollection& p_FrameList, int16_t p_RenderPriority)
{
	m_RenderPriority = p_RenderPriority;
	m_FrameList = p_FrameList;
	setPositionOfEntity(p_X, p_Y);
}

void IronWall::doRoutine() {}

void IronWall::doAnimationRoutine() {}