#pragma once
#include "SDL.h"
class Collision
{
public:
	static bool CollideAABB(SDL_Rect pRectA, SDL_Rect pRectB);
};