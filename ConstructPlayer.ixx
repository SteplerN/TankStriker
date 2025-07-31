export module ConstructPlayer;

import std;
import sfml;

import Entity;
import Enums;
import HitBox;
import Player;
import Usings;

import NormalTextureLoader;

sf::Texture t_blue_tank_forward;
auto blue_tank_forward = std::make_shared<sf::Sprite>(
	normalTextureLoading(t_blue_tank_forward, "assets/statics/blue_tank/blue_tank_forward.png"));

sf::Texture t_blue_tank_backward;
auto blue_tank_backward = std::make_shared<sf::Sprite>(
	normalTextureLoading(t_blue_tank_backward, "assets/statics/blue_tank/blue_tank_backward.png"));

sf::Texture t_blue_tank_left;
auto blue_tank_left = std::make_shared<sf::Sprite>(
	normalTextureLoading(t_blue_tank_left, "assets/statics/blue_tank/blue_tank_left.png"));

sf::Texture t_blue_tank_right;
auto blue_tank_right = std::make_shared<sf::Sprite>(
	normalTextureLoading(t_blue_tank_right, "assets/statics/blue_tank/blue_tank_right.png"));

export FrameListCollection g_BlueTankFrameList =
{
	blue_tank_forward,
	blue_tank_backward,
	blue_tank_left,
	blue_tank_right
};

export HitBoxCollection g_BlueTankHitboxList =
{
	std::vector<std::shared_ptr<HitBox>>
	{
		std::make_shared<HitBox>(HitBoxType::Collision, 60.f, 60.f)
	},
	std::vector<std::shared_ptr<HitBox>>
	{
		std::make_shared<HitBox>(HitBoxType::Collision, 60.f, 60.f)
	},
	std::vector<std::shared_ptr<HitBox>>
	{
		std::make_shared<HitBox>(HitBoxType::Collision, 60.f, 60.f)
	},
	std::vector<std::shared_ptr<HitBox>>
	{
		std::make_shared<HitBox>(HitBoxType::Collision, 60.f, 60.f),
	}
};


export std::shared_ptr<Entity> constructPlayer(std::vector<void*>& p_Arguments)
{
	return std::make_shared<Player>
	(
		*(static_cast<float*>((p_Arguments[0]))),
		*(static_cast<float*>(p_Arguments[1])),
		*(static_cast<FrameListCollection*>(p_Arguments[2])),
		*(static_cast<HitBoxCollection*>(p_Arguments[3])),
		*(static_cast<int32_t*>(p_Arguments[4]))
	);
}