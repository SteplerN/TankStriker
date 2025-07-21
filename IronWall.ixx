export module IronWall;

import std;
import sfml;
import Usings;

import Entity;
import Enums;

export class IronWall : public Entity
{

	void doAnimationRoutine() override {}

public:

	IronWall(float p_X, float p_Y, FrameListCollection&& p_FrameList, int16_t p_RenderPriority)
	{
		m_RenderPriority = p_RenderPriority;
		m_FrameList = p_FrameList;
		setPositionOfEntity(p_X, p_Y);
	}

	void doRoutine([[maybe_unused]] float p_Time, [[maybe_unused]] float p_DeltaTime) override {}

	~IronWall() override = default;

};