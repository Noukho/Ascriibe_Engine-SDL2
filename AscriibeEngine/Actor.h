#pragma once
#include "TransformComponent.h"
#include "VisualComponent.h"

class Actor
{
public:
	Actor() = default;
	~Actor() = default;

	TransformComponent transform;
	VisualComponent visual;

};

