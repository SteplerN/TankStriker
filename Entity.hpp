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

	const int16_t seeRenderPriority() const;

	void setFrameList(FrameListCollection& p_FrameList);

	int16_t getCurrentFrameNumber() const;

	const FrameListCollection& getFrameList() const;

	void setPositionOfEntity(float p_X, float p_Y);

	void moveEntity(float p_X, float p_Y);

	const std::shared_ptr<sf::Sprite>& seeCurrentFrame();

	virtual ~Entity() = default;

};