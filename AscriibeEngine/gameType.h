#pragma once
#include <vector>
#include "Actor.h"
#include "curses.h"

class gameType
{
};

typedef struct {
	bool isPaceable;
	Vector2D position;
	chtype visual;
}Tile;

typedef struct {
	bool done;
	const char* fontPath;
	Vector2D maxPos;
	std::vector<Tile*> tile;
	std::vector<Actor*> actor;
}Scene;