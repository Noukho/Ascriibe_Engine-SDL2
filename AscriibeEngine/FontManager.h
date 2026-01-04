#pragma once
#include<SDL.h>
#include<SDL_ttf.h>
#include <string>
#define TTF_SHOWFONT_USAGE \
"Usage: %s [--textengine surface|renderer] [--solid] [--shaded] [--blended] [-b] [-i] [-u] [-s] [--outline size] [--hintlight|--hintmono|--hintnone] [--nokerning] [--wrap] [--align left|center|right] [--fgcol r,g,b,a] [--bgcol r,g,b,a] [--disable-editbox] [--fallback <font>.ttf>] <font>.ttf [ptsize] [text]\n"

typedef struct {
	int w;
	int h;
}CharSize;

class FontManager
{
public:
	FontManager();
	~FontManager();
	//static void adjustTextOffset(TTF_Text* text, int xoffset, int yoffset);
	void LoadFont(const char* fontName, int size, SDL_Color color);
	SDL_Surface* getTextSurface(const char* text);
	CharSize getCharacterSize() { return *charSize; };


private:
	TTF_Font* font;
	SDL_Color color;
	CharSize* charSize;

};

