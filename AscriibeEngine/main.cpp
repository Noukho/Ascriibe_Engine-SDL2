#include "main.h"

#define SDL_MAIN_HANDLED
#include "GraphicManager.h"
#include "FontManager.h"

const int CHAR_WIDTH  = 16;   // taille d'un caractère
const int CHAR_HEIGHT = 16;
const int GRID_COLS   = 40;   // largeur grille curses
const int GRID_ROWS   = 25;	  // hauteur grille curses

int main(int argc, char* argv[])
{

	GraphicManager* graphicManager;
	graphicManager = new GraphicManager;

	//
	mvprintw(1, 2, "Hello from PDCurses!");
	mvaddch(3, 2, '@');
	mvaddch(4, 5, '#');
	mvprintw(6, 10, "ASCII !");
	refresh();

	bool running = true;
	SDL_Event e;
	Scene *scene;
	scene = new Scene;

	while (running)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				running = false;
			}
		}
		graphicManager->DrawScene(scene);
		//graphicManager->setRender();
	}

	//TTF_Quit();
	graphicManager->~GraphicManager();

	return 0;
}