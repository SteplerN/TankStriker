export module IronWall;

import std;
import sfml;
import Usings;

import Entity;
import Enums;

export class IronWall : public Entity
{

public:

	IronWall(float p_X, float p_Y, FrameListCollection& p_FrameList, HitBoxCollection& p_HitBoxList, int32_t p_RenderPriority)
	{
		m_RenderPriority = std::move(p_RenderPriority);
		m_FrameList = std::move(p_FrameList);
		m_HitBoxList = std::move(p_HitBoxList);
		setPositionOfEntity(p_X, p_Y);
	}

	void doRoutine([[maybe_unused]] float p_Time, [[maybe_unused]] float p_DeltaTime) override {}

	~IronWall() override = default;

};