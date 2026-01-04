#pragma once
#include "Component.h"
#include "SDL.h"
#include "curses.h"

class VisualComponent : public Component
{
	private:
		chtype visualChar;
		SDL_Color charColor;
		int zOrder;


	public:
		char GetVisual() { return visualChar; };
		void SetVisual(char ch, SDL_Color color);
		void SetVisual(char ch, SDL_Color color, int zOrd);
};