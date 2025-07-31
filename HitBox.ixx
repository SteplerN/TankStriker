export module HitBox;

import sfml;

import Enums;

export class HitBox : public sf::RectangleShape
{

protected:

	HitBoxType m_Type;

public:

	HitBox(HitBoxType p_Type, float p_XSize, float p_YSize) noexcept
	{
		m_Type = p_Type;
		setSize(sf::Vector2f(p_XSize, p_YSize));

		if (m_Type == HitBoxType::Collision) setFillColor(sf::Color(27, 100, 0, 100));
		else if (m_Type == HitBoxType::Damagable) setFillColor(sf::Color(255, 0, 0, 100));
	}

	const auto& getType() const noexcept
	{
		return m_Type;
	}

};