export module Core;

import std;
import sfml;

import Scene;
import Globals;
import Entity;
import KillProgram;
import Globals;
import InitList;

using CoreCollection = std::vector<std::shared_ptr<Scene>>;

export class Core
{

protected:

	CoreCollection m_Scenes;
	int32_t m_CurrentSceneNumber = 0;

	sf::Clock s_Time;
	sf::Clock s_DeltaTime;

	static bool compareEntityRenderPriorities(std::shared_ptr<Entity>& p1, std::shared_ptr<Entity>& p2)
	{
		return p1->seeRenderPriority() < p2->seeRenderPriority();
	}

public:

	void initilaize()
	{
		for (auto& current_scene_and_objects : g_InitList)
		{
			for (auto& current_object : current_scene_and_objects.second)
			{
				current_scene_and_objects.first->getTheSceneList()->push_back(std::move(current_object.first(current_object.second)));
			}
		}
		for (auto& current_pair : g_InitList)
		{
			m_Scenes.push_back((current_pair.first));
		}
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

			auto t = static_cast<float>(s_Time.getElapsedTime().asMicroseconds());
			auto dt = static_cast<float>(s_DeltaTime.restart().asMicroseconds());

			auto& scene_list = (m_Scenes[m_CurrentSceneNumber])->seeTheSceneList();
			std::sort(scene_list->begin(), scene_list->end(), compareEntityRenderPriorities);

			for (auto& current_entity : *scene_list)
			{
				current_entity->doRoutine(t, dt);
			}

			g_MainWindow.clear(sf::Color::Black);
			m_Scenes[m_CurrentSceneNumber]->drawTheScene(g_MainWindow);
			g_MainWindow.display();

		}
	}

};