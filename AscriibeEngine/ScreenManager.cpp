#include "ScreenManager.h"

ScreenManager::ScreenManager()
{
	viewport = initscr();
	noecho();
	curs_set(0);

	printw("Init...");
	refresh();
}

ScreenManager::~ScreenManager()
{
	endwin();
}


void ScreenManager::DrawViewport(Scene* scene)
{
	resize_term(scene->maxPos.x, scene->maxPos.y);
	clear();

	//draw Tile 
	for (int I = 0; I < scene->tile.size(); I++)
	{
		mvaddch(scene->tile[I]->position.y, scene->tile[I]->position.x, scene->tile[I]->visual);
	}

	//draw Actor
	for (int I = 0; I < scene->actor.size(); I++)
	{
		mvaddch(scene->actor[I]->transform.GetPosition().y, scene->actor[I]->transform.GetPosition().x, scene->actor[I]->visual.GetVisual());
	}
}
