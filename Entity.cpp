#include "Entity.hpp"

using FrameListCollection = std::vector<std::shared_ptr<sf::Sprite>>;

const int16_t Entity::seeRenderPriority() const
{
	return m_RenderPriority;
}

void Entity::setFrameList(FrameListCollection& p_FrameList)
{
	m_FrameList = p_FrameList;
}

int16_t Entity::getCurrentFrameNumber() const
{
	return m_CurrentFrameNumber;
}

const FrameListCollection& Entity::getFrameList() const
{
	return m_FrameList;
}

void Entity::setPositionOfEntity(float p_X, float p_Y)
{
	for (auto& current_frame : m_FrameList)
	{
		current_frame->setPosition(p_X, p_Y);
	}
}

void Entity::moveEntity(float p_X, float p_Y)
{
	for (auto& current_frame : m_FrameList)
	{
		current_frame->move(p_X, p_Y);
	}
}

const std::shared_ptr<sf::Sprite>& Entity::seeCurrentFrame()
{
	return m_FrameList[m_CurrentFrameNumber];
}