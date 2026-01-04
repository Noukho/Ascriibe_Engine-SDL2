#pragma once
#include <SDL.h>
#include "FontManager.h"
#include<string>
#include <Windows.h>
#include "gameType.h"

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

class GraphicManager
{
public:


	GraphicManager();
	~GraphicManager();

	
	void DrawScene(Scene* scene);
	SDL_Texture* CreateCharTexture(const char* character);
	

	std::string wchar_to_utf8(const std::wstring& wstr);
	std::wstring utf8_to_wchar(const std::string& str);

	FontManager* fontManager;
	//ScreenManager* screenManager;
	
	//SDL_Texture CreateTextureWithSurface(SDL_Surface* surface);
	
private:
	SDL_Window* win;
	SDL_Renderer* renderer;


	const int CHAR_WIDTH = 16;   // taille d'un caractère
	const int CHAR_HEIGHT = 16;
	const int GRID_COLS = 40;   // largeur grille curses
	const int GRID_ROWS = 25;	  // hauteur grille curses

};

