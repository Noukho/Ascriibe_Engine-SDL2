#include "main.h"

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_ttf.h>
#include <curses.h>

const int CHAR_WIDTH  = 16;   // taille d'un caractère
const int CHAR_HEIGHT = 16;
const int GRID_COLS   = 40;   // largeur grille curses
const int GRID_ROWS   = 25;	  // hauteur grille curses

int main(int argc, char* argv[])
{
	// init SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("SDL_Init Error: %s\n", SDL_GetError());
		return 1;
	}


	//Création fenêtre SDL    
	SDL_Window* win = SDL_CreateWindow("Test SDL2 + PDCurses", 100, 100, 640, 480, SDL_WINDOW_SHOWN);

	if (!win)
	{
		printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, GRID_COLS * CHAR_WIDTH, GRID_ROWS * CHAR_HEIGHT);

	//TTF_Init();



	initscr();
	noecho();
	curs_set(0); 
	mvprintw(1, 2, "Hello from PDCurses!");
	mvaddch(3, 2, '@');
	mvaddch(4, 5, '#');
	mvprintw(6, 10, "ASCII !");
	refresh();

	//printw("Hello PDCurses!\nPress any key to quit...");
	bool running = true;
	SDL_Event e;

	while (running)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				running = false;
			}
		}

		SDL_SetRenderTarget(renderer, texture);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		for (int y = 0; y < GRID_ROWS; y++)
		{
			for (int x = 0; x < GRID_COLS; x++)
			{
				chtype ch = mvinch(y, x) & A_CHARTEXT;

				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

				SDL_Rect rect = { x * CHAR_WIDTH, y * CHAR_HEIGHT, CHAR_WIDTH - 1, CHAR_HEIGHT - 1 };

				if (ch == '@') SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
				if (ch == '#') SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

				SDL_RenderDrawRect(renderer, &rect);
			}
		}

		SDL_SetRenderTarget(renderer, nullptr);
		SDL_RenderCopy(renderer, texture, nullptr, nullptr);
		SDL_RenderPresent(renderer);

		SDL_Delay(16);
	}

	endwin();
	//TTF_Quit();
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
	SDL_Quit();

	return 0;
}