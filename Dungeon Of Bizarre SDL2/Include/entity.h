#pragma once
#include "SDL.h"
#include "app.h"

class Entity
{
public:
	//Entity();
	Entity(int pX, int pY, int pSize, SDL_Texture* pTexture);

	int x, y, size;
	bool animated;
	const char* type;
	short maxFrames, currentFrame, clock;

	void Update();
	void Draw();
	void Animate();

	SDL_Rect spriteRect;
	SDL_Rect positionRect;
	SDL_RendererFlip flip;
	SDL_Texture* spritesheet;
};