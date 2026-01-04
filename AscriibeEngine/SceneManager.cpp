#include "SceneManager.h"

SceneManager::SceneManager()
{
	screenManager = new ScreenManager;
	actualScene = new Scene;

	actualScene->fontPath = "";
	actualScene->maxPos.x = 200;
	actualScene->maxPos.y = 150;
	actualScene->tile;
	actualScene->actor;
}

SceneManager::~SceneManager()
{
	screenManager->~ScreenManager();
}

void SceneManager::SetSceneSize(int maxX, int maxY)
{
	actualScene->maxPos.x = maxX;
	actualScene->maxPos.y = maxY;
}

void SceneManager::AddTileToScene(Tile* TileToAdd)
{
	if (TileToAdd != nullptr)
	{
		actualScene->tile.push_back(TileToAdd);
	}
}

void SceneManager::AddMultTileToScene(std::vector<Tile*> arrOfTileToDraw)
{
	for (int i = 0; i <= arrOfTileToDraw.size() - 1; i++)
	{
		AddTileToScene(arrOfTileToDraw[i]);
	}
}



void SceneManager::AddActorToScene(Actor* ActorToAdd)
{
	if (ActorToAdd != nullptr)
	{
		actualScene->actor.push_back(ActorToAdd);
	}
}

void SceneManager::AddMultActorToScene(std::vector<Actor*> arrOfActorToAdd)
{
	for (int i = 0; i <= arrOfActorToAdd.size() - 1; i++)
	{
		AddActorToScene(arrOfActorToAdd[i]);
	}
}




void SceneManager::buildScene()
{
	screenManager->DrawViewport(actualScene);
}




