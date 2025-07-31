import Core;

int main()
{/*
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
	
	HitBoxCollection blue_tank_hitbox_list =
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
	
	
	auto player = std::make_shared<Player>
		(700.f, 700.f, std::move(blue_tank_frame_list), std::move(blue_tank_hitbox_list), 1);
	
	auto iron_wall_001 = std::make_shared<IronWall>
		(500.f, 500.f, std::move(iron_wall_frame_list), int16_t(2));
	auto blue_square = std::make_shared<FinishedAnimation>
		(600.f, 600.f, std::move(blue_square_frame_list), std::move(blue_square_time_list), 15, false);
	
	
	auto entity_list = std::make_shared<SceneCollection>();
	auto scene = std::make_shared<Scene>(std::move(entity_list));

	//scene->addToTheScene(std::move(blue_square));
	//scene->addToTheScene(std::move(player));
	//scene->addToTheScene(std::move(iron_wall_001));

	CoreCollection scenes = { scene };

	Core core(std::move(scenes));
	core.runTheGame();

	return 0;*/

	Core core;
	core.initilaize();
	core.runTheGame();
	return 0;

}