export module ConstructIronWall;

import std;
import sfml;

import Entity;
import IronWall;
import Usings;

import NormalTextureLoader;

sf::Texture t_iron_wall;
auto iron_wall = std::make_shared<sf::Sprite>(
	normalTextureLoading(t_iron_wall, "assets/statics/iron_wall/iron_wall.png"));

export FrameListCollection g_BlueTankFrameList =
{
	iron_wall
};

export HitBoxCollection g_BlueTankHitboxList =
{
};

export std::shared_ptr<Entity> constructIronWall(std::vector<void*>& p_Arguments)
{
	return std::make_shared<IronWall>
		(
			*(static_cast<float*>((p_Arguments[0]))),
			*(static_cast<float*>(p_Arguments[1])),
			*(static_cast<FrameListCollection*>(p_Arguments[2])),
			*(static_cast<HitBoxCollection*>(p_Arguments[3])),
			*(static_cast<int32_t*>(p_Arguments[4]))
		);
}