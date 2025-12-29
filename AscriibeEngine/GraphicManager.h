#pragma once
#include <SDL.h>
#include "FontManager.h"
#include <curses.h>
#include<string>
//#include "editbox.h"

typedef enum
{
	TextEngineNone,
	TextEngineSurface,
	TextEngineRenderer
} TextEngine;

typedef enum
{
	TextRenderSolid,
	TextRenderShaded,
	TextRenderBlended
} TextRenderMethod;

typedef struct {
	bool done;
	SDL_Window* window;
	SDL_Surface* window_surface;
	SDL_Renderer* renderer;
	TTF_Font* font;
	//TTF_Text* caption;
	SDL_Rect captionRect;
	SDL_Texture* message;
	SDL_FRect messageRect;
	TextEngine textEngine;
	SDL_FRect textRect;
	//EditBox* edit;
}Scene;

class GraphicManager
{
public:


	GraphicManager();
	~GraphicManager();

	
	void DrawScene(Scene* scene);
	
	//SDL_Texture CreateTextureWithSurface(SDL_Surface* surface);

private:
	SDL_Window* win;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	FontManager* fontManager;
	const int CHAR_WIDTH = 16;   // taille d'un caractère
	const int CHAR_HEIGHT = 16;
	const int GRID_COLS = 40;   // largeur grille curses
	const int GRID_ROWS = 25;	  // hauteur grille curses



};

