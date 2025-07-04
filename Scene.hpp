#pragma once

#include <vector>
#include <memory>

#include "Entity.hpp"

using SceneCollection = std::vector<std::shared_ptr<Entity>>;

class Scene
{

	SceneCollection m_EntityList;

public:

	Scene(SceneCollection p_EntityArray) : m_EntityList(p_EntityArray) {}

	void addToTheScene(std::shared_ptr<Entity>& p_Entity)
	{
		m_EntityList.push_back(p_Entity);
	}

	const auto& seeTheSceneList() const
	{
		return m_EntityList;
	}

	auto copyTheSceneList() const
	{
		return m_EntityList;
	}

	void drawTheScene(sf::RenderWindow& p_Window)
	{
		for (auto& current_object : m_EntityList)
		{
			p_Window.draw(*(current_object->seeCurrentFrame()));
		}
	}

};