#include "FontManager.h"
#include <curses.h>

FontManager::FontManager()
{
	if (TTF_Init() == -1) {
		printf("SDL error %s\n", SDL_GetError());
		//return 1;
	}
	charSize = new CharSize;
	charSize->h = 0;
	charSize->w = 0;
	//police:
	//DejaVu Sans Mono
	//Noto Sans Mono
	//Liberation Mono

}

FontManager::~FontManager()
{
	//charSize
	TTF_CloseFont(font);
	TTF_Quit();
}

void FontManager::LoadFont(const char* fontName, int size, SDL_Color color)
{
	font = TTF_OpenFont(fontName, size);
	if (!font) {
		printf("TTF_OpenFont error (%s): %s\n", fontName,TTF_GetError());
	}
	TTF_SizeText(font, "W", &charSize->w, &charSize->h);
	//color = { 255, 255, 255, 255 };
}

SDL_Surface* FontManager::getTextSurface(const char* text)
{
	//TTF_RenderUTF8_Blended
	SDL_Surface* surface = TTF_RenderUTF8_Blended(font, text, color);//"╔═╗ UTF-8 █▓▒", color);

	if (!surface) {
		printf("Render error: %s\n", TTF_GetError());
	}
	return surface;	
}
