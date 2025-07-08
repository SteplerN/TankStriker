#include "Player.hpp"

using FrameListCollection = std::vector<std::shared_ptr<sf::Sprite>>;

Player::Player(float p_X, float p_Y, FrameListCollection& p_FrameList, int16_t p_RenderPriority)
{
	m_RenderPriority = p_RenderPriority;
	m_FrameList = p_FrameList;
	setPositionOfEntity(p_X, p_Y);

	m_FrameList[1]->move(0, 70);
	m_FrameList[3]->move(70, 0);

	m_FrameList[2]->move(-70, 70);
	m_FrameList[3]->move(-70, 70);

}

void Player::doAnimationRoutine()
{
	m_CurrentFrameNumber = m_Direction;
}

void Player::doRoutine()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		moveEntity(0.f, -1.f);
		m_Direction = Direction::Forward;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		moveEntity(0.f, 1.f);
		m_Direction = Direction::Backward;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		moveEntity(-1.f, 0.f);
		m_Direction = Direction::Left;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		moveEntity(1.f, 0.f);
		m_Direction = Direction::Right;
	}

	doAnimationRoutine();
}