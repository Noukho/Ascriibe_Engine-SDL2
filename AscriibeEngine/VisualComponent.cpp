#include "VisualComponent.h"

void VisualComponent::SetVisual(char ch, SDL_Color color)
{
	visualChar  = ch;
	charColor = color;
}

void VisualComponent::SetVisual(char ch, SDL_Color color, int zOrd)
{
	visualChar = ch;
	charColor = color;
	zOrder = zOrd;
}
