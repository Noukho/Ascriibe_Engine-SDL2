#pragma once
//#include "GraphicManager.h"
#include "gameType.h"
#include "ScreenManager.h"
#include <curses.h>
#include <list>


class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	//Scene* CreateScene();
	void SetSceneSize(int maxX, int maxY);

	void AddTileToScene(Tile* TileToAdd);
	void AddMultTileToScene(std::vector<Tile*> arrOfTileToDraw);

	void AddActorToScene(Actor* ActorToAdd);
	void AddMultActorToScene(std::vector<Actor*> arrOfActorToAdd);

	void buildScene();

	Scene* GetScene() { return actualScene; };
	ScreenManager* GetScreenManager() { return screenManager; };

private:
	ScreenManager* screenManager;
	Scene* actualScene;


};

