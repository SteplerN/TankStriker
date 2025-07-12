export module Scene;

import stl;
import sfml;

import Usings;
import Entity;
import Player;

using SceneCollection = std::shared_ptr<std::vector<std::shared_ptr<Entity>>>;

export class Scene
{

	SceneCollection& m_EntityList;

public:

	Scene(SceneCollection& p_EntityList) : m_EntityList(p_EntityList) {}

	void addToTheScene(std::shared_ptr<Entity> p_Entity)
	{
		m_EntityList->push_back(p_Entity);
	}

	const SceneCollection& seeTheSceneList() const
	{
		return m_EntityList;
	}

	SceneCollection copyTheSceneList() const
	{
		return m_EntityList;
	}

	void drawTheScene(sf::RenderWindow& p_Window)
	{
		for (auto& current_object : *m_EntityList)
		{
			p_Window.draw(*(current_object->seeCurrentFrame()));
		}
	}

};