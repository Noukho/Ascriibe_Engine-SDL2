#pragma once
//#include <curses.h>
#include "SceneManager.h"
#include <iostream>
#include "GraphicManager.h"


const int CHAR_WIDTH = 16;   // taille d'un caractère
const int CHAR_HEIGHT = 16;
const int GRID_COLS = 40;   // largeur grille curses
const int GRID_ROWS = 25;	  // hauteur grille curses

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

