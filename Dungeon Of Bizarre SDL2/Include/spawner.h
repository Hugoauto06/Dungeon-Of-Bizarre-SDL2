#pragma once
#include "defines.h"

extern void InstantiateEnemy(int pX, int pY);

class Spawner
{
public:
	Spawner();
	int clock;
	void Update();
};