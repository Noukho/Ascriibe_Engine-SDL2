#pragma once
#include <curses.h>
#include "GameType.h"


class ScreenManager
{
public:
	ScreenManager(); 
	~ScreenManager();// = default;

	
	WINDOW* DrawViewport(Scene* scene);

	//WINDOW* GetViewport() { return viewport; };

private:

	WINDOW* viewport;
	Vector2D screenSize;

};

