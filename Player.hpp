#pragma once

#include <vector>
#include <memory>
#include <cstdint>

#include "Entity.hpp"
#include "Enums.hpp"

using FrameListCollection = std::vector<std::shared_ptr<sf::Sprite>>;

class Player : public Entity
{

	Direction m_Direction = Direction::Forward;

public:

	Player(float p_X, float p_Y, FrameListCollection& p_FrameList, int16_t p_RenderPriority);

	void doAnimationRoutine() override;

	void doRoutine() override;

	~Player() override = default;

};