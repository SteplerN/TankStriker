export module Core;

import stl;
import sfml;

import Scene;
import Globals;
import Entity;

using CoreCollection = std::vector<std::shared_ptr<Scene>>;

export class Core
{
	
	CoreCollection m_Scenes;
	int16_t m_CurrentSceneNumber = 0;

	static bool compareEntityRenderPriorities(std::shared_ptr<Entity>& p1, std::shared_ptr<Entity>& p2)
	{
		return p1->seeRenderPriority() < p2->seeRenderPriority();
	}

	static void drawTheScene(std::vector<std::shared_ptr<Entity>>& p_EntityList, sf::RenderWindow& p_Window)
	{
		for (auto& current_object : p_EntityList)
		{
			p_Window.draw(*(current_object->seeCurrentFrame()));
		}
	}

public:

	void addTheScene(std::shared_ptr<Scene> p_Scene)
	{
		m_Scenes.push_back(p_Scene);
	}

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

			auto& scene_list = (m_Scenes[m_CurrentSceneNumber])->seeTheSceneList();
			std::sort((*scene_list).begin(), (*scene_list).end(), compareEntityRenderPriorities);

			for (auto& current_entity : *(m_Scenes[m_CurrentSceneNumber])->seeTheSceneList())
			{
				current_entity->doRoutine();
			}

			g_MainWindow.clear(sf::Color::White);
			m_Scenes[m_CurrentSceneNumber]->drawTheScene(g_MainWindow);
			g_MainWindow.display();

		}
	}

};