#pragma once
#include "player.h"
#include "drawFunctions.h"
#include "bullet.h"
#include "enemy.h"
#include <vector>

extern App app;
extern Camera camera;
extern std::vector<Bullet*> bullets;

class Enemy : public Entity
{
public:
	Enemy(int pX, int pY, int pSize, SDL_Texture* pTexture);

	float health;

	void Update(Player* pPlayer);
	void Draw();
};