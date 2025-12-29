#include "FontManager.h"
#include <curses.h>

FontManager::FontManager()
{
	if (TTF_Init() == -1) {
		printf("SDL error %s\n", SDL_GetError());
		//return 1;
	}
	//police:
	//DejaVu Sans Mono
	//Noto Sans Mono
	//Liberation Mono

}

FontManager::~FontManager()
{
}

void FontManager::LoadFont(std::string fontString, int size, SDL_Color color)
{

	font = TTF_OpenFont(fontString.data(), size);
	if (!font) {
		printf("Font error: %s\n", TTF_GetError());
	}

	color = { 255, 255, 255, 255 };



}

SDL_Surface* FontManager::getTextSurface(std::string text)
{
	SDL_Surface* surface = TTF_RenderUTF8_Blended(font, "╔═╗ UTF-8 █▓▒", color);

	if (!surface) {
		printf("Render error: %s\n", TTF_GetError());
	}
	return surface;	
}
