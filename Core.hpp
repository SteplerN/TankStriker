#pragma once

#include <algorithm>
#include <memory>

#include <SFML/Graphics.hpp>

#include "Enums.hpp"
#include "Scene.hpp"
#include "MainWindow.hpp"
#include "Entity.hpp"

class Core
{

    Scene& m_Scene;

	static bool compareEntityRenderPriorities(std::shared_ptr<Entity>& p1, std::shared_ptr<Entity>& p2)
	{
		return p1->seeRenderPriority() < p2->seeRenderPriority();
	}

	static void drawCopyScene(std::vector<std::shared_ptr<Entity>>& p_EntityList, sf::RenderWindow& p_Window)
	{
		for (auto& current_object : p_EntityList)
		{
			p_Window.draw(*(current_object->seeCurrentFrame()));
		}
	}

public:

	Core(Scene& p_Scene);

	void runTheGame();
};