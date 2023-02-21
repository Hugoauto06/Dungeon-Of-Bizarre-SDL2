#include "enemy.h"
#include "collision.h"
Enemy::Enemy(int pX, int pY, int pSize, SDL_Texture* pTexture)
	:Entity { pX, pY, pSize, pTexture }
{
	health		= 100.0f;
	type		= "enemy";
}

void Enemy::Update(Player *pPlayer)
{
	Animate();
	int _speed = 2;
	positionRect.x = x;
	positionRect.y = y;
	if (x < pPlayer->x)
	{
		x+= _speed;
		flip = SDL_FLIP_NONE;
	}
	if (x > pPlayer->x)
	{
		x-= _speed;
		flip = SDL_FLIP_HORIZONTAL;
	}
	if (y < pPlayer->y)
	{
		y+= _speed;
	}
	if (y > pPlayer->y)
	{
		y-= _speed;
	}


	for (int j = 0; j < bullets.size(); j++)
	{
		if (Collision::CollideAABB(positionRect, bullets[j]->positionRect))
		{
			health -= 25.0f;
			bullets.erase(bullets.begin() + j);
		}
	}

	if (Collision::CollideAABB(positionRect, pPlayer->positionRect) && pPlayer->hurt == false)
	{
		pPlayer->health -= 25.0f;
		pPlayer->hurt = true;
	}

}

void Enemy::Draw()
{
	DrawFunctions::DrawEntity(*this, camera);
}