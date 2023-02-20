#pragma once
#include "SDL.h"
#include "defines.h"
#include "app.h"

extern App app;
extern int naive_lerp(float a, float b, float t);


class Camera
{
public:
	Camera(int pX, int pY, int pW, int pH);
	
	void FollowPoint(int pX, int pY);

	SDL_Rect cameraRect;
};