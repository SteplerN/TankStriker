export module InitList;

import std;
import sfml;

import Scene;
import Entity;
import Construct;

using SceneCollection = std::vector<std::shared_ptr<Entity>>;
using EntityConstruct = std::function<std::shared_ptr<Entity>(std::vector<void*>&)>;
using EntityConstructorArguments = std::vector<void*>;
using EntityDescription = std::pair<EntityConstruct, EntityConstructorArguments>;
using InitListType = std::vector<std::pair<std::shared_ptr<Scene>, std::vector<std::pair<EntityConstruct, EntityConstructorArguments>>>>;
using CoreCollection = std::vector<std::shared_ptr<Scene>>;

auto scene = std::make_shared<Scene>();

export InitListType g_InitList
{
	std::pair<std::shared_ptr<Scene>, std::vector<std::pair<EntityConstruct, EntityConstructorArguments>>>
	(
		scene,
		{
			{constructPlayer, {(new float(700.f)), (new float(700.f)), &g_BlueTankFrameList, &g_BlueTankHitboxList, new int(1)}}
		}
	)
};