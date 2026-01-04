#pragma once
//#include <curses.h>
#include "SceneManager.h"
#include <iostream>
#include "GraphicManager.h"




class Game
{
public:
	Game();
	~Game() = default;
	void GameLoop();
	void CloseGame();

private:
	bool running = true;
	SDL_Event e;
	SceneManager* sceneManager;
	GraphicManager* graphicManager;
	
};

