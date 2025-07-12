import stl;
import sfml;

import Usings;
import Entity;
import Core;
import Scene;
import Player;
import IronWall;
import FinishedAnimation;

using SceneCollection = std::vector<std::shared_ptr<Entity>>;

int main()
{
	Core core;

	/////////////////////////// Sprite Initialization Block Start ///////////////////////////

	// Blue Tank start
	sf::Texture t_blue_tank_forward;
	t_blue_tank_forward.loadFromFile("assets/statics/blue_tank/blue_tank_forward.png");
	auto blue_tank_forward = std::make_shared<sf::Sprite>(t_blue_tank_forward);

	sf::Texture t_blue_tank_backward;
	t_blue_tank_backward.loadFromFile("assets/statics/blue_tank/blue_tank_backward.png");
	auto blue_tank_backward = std::make_shared<sf::Sprite>(t_blue_tank_backward);

	sf::Texture t_blue_tank_left;
	t_blue_tank_left.loadFromFile("assets/statics/blue_tank/blue_tank_left.png");
	auto blue_tank_left = std::make_shared<sf::Sprite>(t_blue_tank_left);

	sf::Texture t_blue_tank_right;
	t_blue_tank_right.loadFromFile("assets/statics/blue_tank/blue_tank_right.png");
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
	t_iron_wall_sp.loadFromFile("assets/statics/iron_wall/iron_wall.png");
	auto iron_wall_sp = std::make_shared<sf::Sprite>(t_iron_wall_sp);

	FrameListCollection iron_wall_frame_list =
	{
		iron_wall_sp
	};

	// Iron Wall End

	// Blue Square Start
	
	sf::Texture t_blue_square_01;
	t_blue_square_01.loadFromFile("assets/animations/blue_square/blue_square_01.png");
	auto blue_square_01 = std::make_shared<sf::Sprite>(t_blue_square_01);

	sf::Texture t_blue_square_02;
	t_blue_square_02.loadFromFile("assets/animations/blue_square/blue_square_02.png");
	auto blue_square_02 = std::make_shared<sf::Sprite>(t_blue_square_02);

	sf::Texture t_blue_square_03;
	t_blue_square_03.loadFromFile("assets/animations/blue_square/blue_square_03.png");
	auto blue_square_03 = std::make_shared<sf::Sprite>(t_blue_square_03);

	FrameListCollection blue_square_frame_list
	{
		blue_square_01,
		blue_square_02,
		blue_square_03
	};

	TimeListCollection blue_square_time_list
	{
		std::make_shared<sf::Time>(sf::seconds(1)),
		std::make_shared<sf::Time>(sf::seconds(1)),
		std::make_shared<sf::Time>(sf::seconds(1))
	};

	// Blue Square End

	/////////////////////////// Sprite Initialization Block End ///////////////////////////

	const auto sp_x  = static_cast<float>(sf::VideoMode::getDesktopMode().width / 2);
	const auto sp_y = static_cast<float>(sf::VideoMode::getDesktopMode().height / 2);

	auto player = std::make_shared<Player>(sp_x, sp_y, blue_tank_frame_list, int16_t(1));
	auto iron_wall_001 = std::make_shared<IronWall>(500.f, 500.f, iron_wall_frame_list, int16_t(2));
	auto blue_square = std::make_shared<FinishedAnimation>(600.f, 600.f, blue_square_frame_list, blue_square_time_list, int16_t(15), false);

	auto entity_list = std::make_shared<SceneCollection>();
	auto scene = std::make_shared<Scene>(entity_list);

	scene->addToTheScene(blue_square);
	scene->addToTheScene(player);
	//scene->addToTheScene(iron_wall_001);

	core.addTheScene(scene);
	core.runTheGame();

	return 0;
}