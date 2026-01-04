#pragma once
#include "Component.h"	
#include "Type.h"

class TransformComponent : public Component
{
	private:
		Vector2D pos;

	public:
		Vector2D GetPosition() { return pos; };
		void SetPosition(int x, int y);


		void addPosition(int x, int y);
};

