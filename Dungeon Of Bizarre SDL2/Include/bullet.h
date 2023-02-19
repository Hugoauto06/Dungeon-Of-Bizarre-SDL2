#pragma once
#include <math.h>
#include "player.h"
#include "drawFunctions.h" 

#define PI	3.14159265

extern App app;
extern Camera camera;
extern Player player;

class Bullet : public Entity
{
public:
	Bullet(int pX, int pY, int pSize, SDL_Texture* pTexture);

	float speed;
	double angle;

	void Update();
	void Draw();
};