#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "main.h"
#include "Game.h"


int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("SDL_Init Error: %s\n", SDL_GetError());
		return 1;
	}
	

	Game* game = new Game;

	game->GameLoop();

	delete game;
	SDL_Quit();
	return 0;
}