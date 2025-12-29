#include "GraphicManager.h"

GraphicManager::GraphicManager()
{
	// init SDL
	fontManager = new FontManager;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("SDL_Init Error: %s\n", SDL_GetError());
	}

	//Création fenêtre SDL    
	win = SDL_CreateWindow("Test SDL2 + PDCurses", 100, 100, 640, 480, SDL_WINDOW_SHOWN);

	if (!win)
	{
		printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
		SDL_Quit();
	}
	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

	fontManager->LoadFont("DejaVuSansMono.ttf", 16, { 255, 255, 255, 255 });
	SDL_Surface* surface = fontManager->getTextSurface("╔═╗ UTF-8 █▓▒");
	texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface);

	//texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, GRID_COLS * CHAR_WIDTH, GRID_ROWS * CHAR_HEIGHT);
	initscr();
	noecho();
	curs_set(0);
}

GraphicManager::~GraphicManager()
{
	endwin();
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
	SDL_Quit();
}



void GraphicManager::DrawScene(Scene* scene)
{
	//
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
	//SDL_RenderTexture(renderer, scene->message, NULL, &scene->messageRect);

	SDL_RenderCopy(renderer, texture, nullptr, nullptr);
	SDL_RenderPresent(renderer);

	SDL_Delay(16);
}
