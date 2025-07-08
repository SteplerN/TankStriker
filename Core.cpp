#include "Core.hpp"

Core::Core(Scene& p_Scene) : m_Scene(p_Scene) {}

void Core::runTheGame()
{
	while (g_MainWindow.isOpen())
	{

		sf::Event event;
		while (g_MainWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				g_MainWindow.close();
			}
		}

		auto copy = m_Scene.seeTheSceneList();
		std::sort(copy.begin(), copy.end(), compareEntityRenderPriorities);

		for (auto& current_entity : m_Scene.seeTheSceneList())
		{
			current_entity->doRoutine();
		}

		g_MainWindow.clear(sf::Color::White);
		drawCopyScene(copy, g_MainWindow);
		g_MainWindow.display();

	}
}