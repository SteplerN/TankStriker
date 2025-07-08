#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <cstdint>
#include <memory>

#include "Entity.hpp"

class IronWall : public Entity
{

public:

	IronWall(float p_X, float p_Y, FrameListCollection& p_FrameList, int16_t p_RenderPriority);

	void doRoutine() override;

	void doAnimationRoutine() override;

	~IronWall() override = default;

};