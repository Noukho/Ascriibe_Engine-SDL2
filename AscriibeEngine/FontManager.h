#pragma once
#include<SDL.h>
#include<SDL_ttf.h>
#define TTF_SHOWFONT_USAGE \
"Usage: %s [--textengine surface|renderer] [--solid] [--shaded] [--blended] [-b] [-i] [-u] [-s] [--outline size] [--hintlight|--hintmono|--hintnone] [--nokerning] [--wrap] [--align left|center|right] [--fgcol r,g,b,a] [--bgcol r,g,b,a] [--disable-editbox] [--fallback <font>.ttf>] <font>.ttf [ptsize] [text]\n"


class FontManager
{
public:
	FontManager();
	~FontManager();
	//static void adjustTextOffset(TTF_Text* text, int xoffset, int yoffset);


private:
	TTF_Font* font;
	SDL_Color color;

};

