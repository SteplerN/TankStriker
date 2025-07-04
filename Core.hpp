#pragma once

#include <algorithm>
#include <memory>

#include <SFML/Graphics.hpp>

#include "Enums.hpp"
#include "Scene.hpp"
#include "MainWindow.hpp"

auto compareEntityRenderPriorities(std::shared_ptr<Entity>& p1, std::shared_ptr<Entity>& p2)
{
	return p1->seeRenderPriority() < p2->seeRenderPriority();
}


void drawCopyScene(std::vector<std::shared_ptr<Entity>>& p_EntityList, sf::RenderWindow& p_Window)
{
	for (auto& current_object : p_EntityList)
	{
		p_Window.draw(*(current_object->seeCurrentFrame()));
	}
}

class Core
{

    Scene& m_Scene;

public:

	Core(Scene& p_Scene) : m_Scene(p_Scene) {}

	void runTheGame()
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

};