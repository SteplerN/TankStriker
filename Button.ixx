export module Button;

import std;
import sfml;

import Entity;
import Enums;
import Usings;
import Globals;

export class Button : public Entity
{

protected:

	bool m_IsButtonHolding = false;
	bool m_IsButtonActivated;
	bool m_IsButtonDisActivated;
	int32_t m_HowManyTimesPressed = 0;
	sf::Mouse::Button m_Activator;

	void updateStatement()
	{
		sf::RectangleShape where_pressed{};
		where_pressed.setSize(sf::Vector2f(0, 0));
		where_pressed.setPosition(
			sf::Vector2f(static_cast<float>(sf::Mouse::getPosition(g_MainWindow).x), 
			static_cast<float>(sf::Mouse::getPosition(g_MainWindow).y)));

		bool is_now_pressed = false;

		if (sf::Mouse::isButtonPressed(m_Activator))
		{
			for (auto& current_hitbox : m_HitBoxList[m_CurrentFrameNumber])
			{
				if (current_hitbox->getType() == HitBoxType::Clickable
				&& current_hitbox->getGlobalBounds().intersects(where_pressed.getGlobalBounds()))
				{
					is_now_pressed = true;
					break;
				}
			}

			if (m_IsButtonHolding == false && is_now_pressed == true && (++m_HowManyTimesPressed))
			{
				m_IsButtonHolding = true;
				m_IsButtonActivated = true;
				m_IsButtonDisActivated = false;
			}
			else if (m_IsButtonHolding == true && is_now_pressed == false)
			{
				m_IsButtonHolding = false;
				m_IsButtonActivated = false;
				m_IsButtonDisActivated = true;
			}
			else if (m_IsButtonHolding == true && is_now_pressed == true)
			{
				m_IsButtonHolding = true;
				m_IsButtonActivated = false;
				m_IsButtonDisActivated = false;
			}
			else if (m_IsButtonHolding == false && is_now_pressed == false)
			{
				m_IsButtonHolding = false;
				m_IsButtonActivated = false;
				m_IsButtonDisActivated = false;
			}
		}	
	}

public:

	Button(float p_X, float p_Y, FrameListCollection&& p_FrameList,
		HitBoxCollection&& p_HitBoxList, sf::Mouse::Button p_Activator, int32_t p_RenderPriority)
	{
		m_RenderPriority = p_RenderPriority;
		m_FrameList = p_FrameList;
		m_HitBoxList = p_HitBoxList;
		m_Activator = p_Activator;
		setPositionOfEntity(p_X, p_Y);
	}

	void doRoutine([[maybe_unused]] float p_Time, [[maybe_unused]] float p_DeltaTime) override
	{
		updateStatement();
	}

	bool isButtonPressed()
	{
		return m_IsButtonHolding;
	}

	~Button() override = default;

};