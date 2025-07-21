export module Scene;

import std;
import sfml;

import Globals;
import Usings;
import Entity;
import Player;
import Enums;

using SceneCollection = std::shared_ptr<std::vector<std::shared_ptr<Entity>>>;

export class Scene
{

	SceneCollection m_EntityList;

public:

	Scene(SceneCollection&& p_EntityList) : m_EntityList(std::move(p_EntityList)) {}

	void addToTheScene(std::shared_ptr<Entity>&& p_Entity)
	{
		m_EntityList->push_back(std::move(p_Entity));
	}

	const auto& seeTheSceneList() const
	{
		return m_EntityList;
	}

	void drawTheScene(sf::RenderWindow& p_Window)
	{

		for (auto& current_object : *m_EntityList)
		{

			p_Window.draw(*(current_object->seeCurrentFrame()));

			if (isDebugModeEnabled && current_object->getCurrentHitBoxList().has_value())
			{

				for (auto& current_hitbox : current_object->getCurrentHitBoxList().value())
				{
					p_Window.draw(*(current_hitbox));
				}

			}

		}

	}

};