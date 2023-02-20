#pragma once
#include <vector>
#include "SDL.h"
#include "SDL_mixer.h"
#include "enemy.h"
#include "bullet.h"
using namespace std;

extern vector<Enemy*> enemies;
extern vector<Bullet*> bullets;
extern SDL_Texture* tEnemy;
extern SDL_Texture* tBullet;

//static void InstantiateEnemy(int pX, int pY);
//static void InstantiateBullet(int pX, int pY);