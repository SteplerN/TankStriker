#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>

#include "Entity.hpp"
#include "Core.hpp"
#include "Scene.hpp"
#include "Player.hpp"
#include "IronWall.hpp"

using FrameListCollection = std::vector<std::shared_ptr<sf::Sprite>>;
using SceneCollection = std::vector<std::shared_ptr<Entity>>;

int main()
{
	/////////////////////////// Sprite Initialization Block Start ///////////////////////////

	// Blue Tank start
	sf::Texture t_blue_tank_forward;
	t_blue_tank_forward.loadFromFile("assets/blue_tank/blue_tank_forward.png");
	auto blue_tank_forward = std::make_shared<sf::Sprite>(t_blue_tank_forward);

	sf::Texture t_blue_tank_backward;
	t_blue_tank_backward.loadFromFile("assets/blue_tank/blue_tank_backward.png");
	auto blue_tank_backward = std::make_shared<sf::Sprite>(t_blue_tank_backward);

	sf::Texture t_blue_tank_left;
	t_blue_tank_left.loadFromFile("assets/blue_tank/blue_tank_left.png");
	auto blue_tank_left = std::make_shared<sf::Sprite>(t_blue_tank_left);

	sf::Texture t_blue_tank_right;
	t_blue_tank_right.loadFromFile("assets/blue_tank/blue_tank_right.png");
	auto blue_tank_right = std::make_shared<sf::Sprite>(t_blue_tank_right);

	FrameListCollection blue_tank_frame_list = 
	{
		blue_tank_forward,
		blue_tank_backward,
		blue_tank_left,
		blue_tank_right
	};
	// Blue Tank End

	// Iron Wall Start
	
	sf::Texture t_iron_wall_sp;
	t_iron_wall_sp.loadFromFile("assets/iron_wall/iron_wall.png");
	auto iron_wall_sp = std::make_shared<sf::Sprite>(t_iron_wall_sp);

	FrameListCollection iron_wall_frame_list =
	{
		iron_wall_sp
	};

	// Iron Wall End

	/////////////////////////// Sprite Initialization Block End ///////////////////////////

	const auto sp_x  = static_cast<float>(sf::VideoMode::getDesktopMode().width / 2);
	const auto sp_y = static_cast<float>(sf::VideoMode::getDesktopMode().height / 2);

	auto player = std::make_shared<Player>(sp_x, sp_y, blue_tank_frame_list, 1);

	auto iron_wall_001 = std::make_shared<IronWall>(sp_x + 100, sp_y + 100, iron_wall_frame_list, 0);

	SceneCollection entity_list;
	entity_list.push_back(player);
	entity_list.push_back(iron_wall_001);


	Scene scene(entity_list);

	Core core(scene);
	core.runTheGame();
}