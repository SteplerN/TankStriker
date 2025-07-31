export module Player;

import std;
import sfml;

import Usings;
import Entity;
import Enums;
import Globals;

export class Player : public Entity
{

protected:

	int32_t m_MovementSpeed = 10;
	Direction m_Direction = Direction::Forward;

public:

	Player(float p_X, float p_Y, FrameListCollection& p_FrameList, 
		HitBoxCollection& p_HitBoxList, int32_t p_RenderPriority)
	{
		m_RenderPriority = std::move(p_RenderPriority);
		m_FrameList = std::move(p_FrameList);
		m_HitBoxList = std::move(p_HitBoxList);
		setPositionOfEntity(p_X, p_Y);

		m_FrameList[1]->move(0, 60);
		m_FrameList[3]->move(45, 0);
		m_FrameList[2]->move(-47, 60);
		m_FrameList[3]->move(-45, 60);

		m_HitBoxList[0][0]->move(0, 60);
		m_HitBoxList[1][0]->move(0, 60);
		m_HitBoxList[2][0]->move(0, 60);
		m_HitBoxList[3][0]->move(0, 60);
	}

	void doAnimationRoutine()
	{
		m_CurrentFrameNumber = static_cast<int32_t>(m_Direction);
	}

	void doRoutine([[maybe_unused]] float p_Time, [[maybe_unused]] float p_DeltaTime) override
	{
		sf::Vector2f movement(0.f, 0.f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			movement.y -= m_MovementSpeed * p_DeltaTime / g_MillisecondsInSeconds;
			m_Direction = Direction::Forward;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			movement.y += m_MovementSpeed * p_DeltaTime / g_MillisecondsInSeconds;
			m_Direction = Direction::Backward;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			movement.x -= m_MovementSpeed * p_DeltaTime / g_MillisecondsInSeconds;
			m_Direction = Direction::Left;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			movement.x += m_MovementSpeed * p_DeltaTime / g_MillisecondsInSeconds;
			m_Direction = Direction::Right;
		}
		moveEntity(movement.x, movement.y);
		doAnimationRoutine();
	}

	void changeMovementSpeed(int32_t p_MovementSpeed)
	{
		m_MovementSpeed = p_MovementSpeed;
	}

	~Player() override = default;

};