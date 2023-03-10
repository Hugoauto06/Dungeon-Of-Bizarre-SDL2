#pragma once
#include "entity.h"
#include "app.h"
#include "defines.h"
#include "drawFunctions.h"

extern App app;
extern Camera camera;

class Player : public Entity
{
public:
	Player(int pX, int pY, int pSize, SDL_Texture* pTexture);

	bool hurt;
	float health;

	float speed = 0;
	double angle = 0;

	void Update();
	void Draw();
	void Restart();
};