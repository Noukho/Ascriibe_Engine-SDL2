#include "TransformComponent.h"
//#include "Type.h"

void TransformComponent::SetPosition(int x, int y)
{
	pos.x = x;
	pos.y = y;
}

void TransformComponent::addPosition(int x, int y)
{
	pos.x = pos.x + x;
	pos.y = pos.y + y;
}