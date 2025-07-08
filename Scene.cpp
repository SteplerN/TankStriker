#include "Scene.hpp"

//using SceneCollection = std::vector<std::shared_ptr<Entity>>;

Scene::Scene(SceneCollection p_EntityList) : m_EntityList(p_EntityList) {}

void Scene::addToTheScene(std::shared_ptr<Entity>& p_Entity)
{
	m_EntityList.push_back(p_Entity);
}

const SceneCollection& Scene::seeTheSceneList() const
{
	return m_EntityList;
}

SceneCollection Scene::copyTheSceneList() const
{
	return m_EntityList;
}

void Scene::drawTheScene(sf::RenderWindow& p_Window)
{
	for (auto& current_object : m_EntityList)
	{
		p_Window.draw(*(current_object->seeCurrentFrame()));
	}
}