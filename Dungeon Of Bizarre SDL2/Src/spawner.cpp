#include "spawner.h"

Spawner::Spawner()
{
	clock = 0;
}

void Spawner::Update()
{
	clock++;
	if (clock == 200)
	{
		InstantiateEnemy(-64, -64);
		InstantiateEnemy(ROOM_MAX_WIDTH+64, -64);
		InstantiateEnemy(-64, ROOM_MAX_HEIGHT+64);
		InstantiateEnemy(ROOM_MAX_WIDTH+64, ROOM_MAX_HEIGHT+64);

		clock = 0;
	}
}