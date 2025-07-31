export module Scene;

import std;
import sfml;

import Globals;
import Usings;
import Entity;
import Player;
import Enums;

using SceneCollection = std::shared_ptr<std::vector<std::shared_ptr<Entity>>>;
using SceneValue =std::vector<std::shared_ptr<Entity>>;

export class Scene final
{

	SceneCollection m_EntityList;

public:

	Scene() : m_EntityList(std::make_shared<SceneValue>()) {}

	const SceneCollection& seeTheSceneList() const
	{
		return m_EntityList;
	}

	SceneCollection& getTheSceneList()
	{
		return m_EntityList;
	}

	void drawTheScene(sf::RenderWindow& p_Window)
	{

		for (auto& current_object : *m_EntityList)
		{

			p_Window.draw(*(current_object->seeCurrentFrame()));

			if constexpr (isDebugModeEnabled && current_object->getCurrentHitBoxList().has_value())
			{

				for (auto& current_hitbox : current_object->getCurrentHitBoxList().value())
				{
					p_Window.draw(*current_hitbox);
				}

			}

		}

	}

};