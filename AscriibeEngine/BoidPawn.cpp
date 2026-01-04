#include "BoidPawn.h"

BoidPawn::BoidPawn()
{
	transform.SetPosition(0, 0);
	visual.SetVisual('▲', {0,0,0,255});
}

BoidPawn::~BoidPawn()
{
}
