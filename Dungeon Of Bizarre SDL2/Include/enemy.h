#pragma once
#include "player.h"
#include "drawFunctions.h"

extern App app;
extern Camera camera;

class Enemy : public Entity
{
public:
	Enemy(int pX, int pY, int pSize, SDL_Texture* pTexture);

	float health;

	void Update(Player* pPlayer);
	void Draw();
};