#pragma once
#include "SDL_mixer.h"
#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include "SDL.h"
#include "app.h"
#include "inputs.h"
#include "enemy.h"
#include "camera.h"
#include "player.h"
#include "frameRate.h"
#include "drawFunctions.h"
#include "collision.h"
#include "spawner.h"
#include "SDL_ttf.h"
#include "bullet.h"
//#include "initializeApp.h"

extern void DoInput(void);
extern void InstantiateBullet(int pX, int pY);
extern void InstantiateEnemy(int pX, int pY);