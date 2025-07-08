#pragma once

#include <vector>
#include <memory>

#include "Entity.hpp"

using SceneCollection = std::vector<std::shared_ptr<Entity>>;

class Scene
{

	SceneCollection m_EntityList;

public:

	Scene(SceneCollection p_EntityList);

	void addToTheScene(std::shared_ptr<Entity>& p_Entity);

	const SceneCollection& seeTheSceneList() const;

	SceneCollection copyTheSceneList() const;

	void drawTheScene(sf::RenderWindow& p_Window);

};