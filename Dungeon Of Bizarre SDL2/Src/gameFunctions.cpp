#include "gameFunctions.h"

void InstantiateEnemy(int pX, int pY)
{
	Enemy* _enemy = new Enemy(pX, pY, 64, tEnemy);
	enemies.push_back(_enemy);
}

void InstantiateBullet(int pX, int pY)
{
	Bullet* _bullet = new Bullet(pX, pY, 16, tBullet);
	_bullet->speed = 15.0f;
	bullets.push_back(_bullet);

	Mix_Chunk* sndGunshot = Mix_LoadWAV("sndGunshot.wav");
	Mix_VolumeChunk(sndGunshot, 10);
	Mix_PlayChannel(2, sndGunshot, 0);
}

int naive_lerp(float a, float b, float t)
{
	return (int)(a + t * (b - a));
}