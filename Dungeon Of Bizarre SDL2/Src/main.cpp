#include "main.h"
#include "collision.h"
#include "spawner.h"
using namespace std;

App app					= App("My app", 1280, 720);
SDL_Texture* tPlayer	= DrawFunctions::LoadTexture("player.png");
SDL_Texture* tEnemy		= DrawFunctions::LoadTexture("enemy.png");
SDL_Texture* tBullet	= DrawFunctions::LoadTexture("bullet.png");
SDL_Texture* tDirt		= DrawFunctions::LoadTexture("dirt.png");
Player player			= Player(320, 420, 64, tPlayer);
Camera camera			= Camera(0, 0, 1280, 720);
Spawner spawner			= Spawner();
vector<Bullet*> bullets;
vector<Enemy*> enemies;
int delayClick = 0;


void Init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
}

void InstantiateEnemy(int pX, int pY)
{
	Enemy* _enemy = new Enemy(pX, pY, 64, tEnemy);
	enemies.push_back(_enemy);
}

void InstantiateBullet(int pX, int pY)
{
	Bullet* _bullet = new Bullet(pX, pY, 16, tBullet);
	_bullet->speed	= 10.0f;
	bullets.push_back(_bullet);
}

void UpdateDelegate()
{
	DoInput();
	delayClick++;
	spawner.Update();
	player.Update();
	camera.FollowPoint(player.x, player.y);

	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i]->Update(&player);
		if (enemies[i]->health <= 0)
		{
			enemies.erase(enemies.begin() + i);
			break;
		}

		for (int j = 0; j < bullets.size(); j++)
		{
			if (Collision::CollideAABB(enemies[i]->positionRect, bullets[j]->positionRect))
			{
				enemies[i]->health -= 25.0f;
				bullets.erase(bullets.begin() + j);
			}
		}
	}
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i]->Update();
	}

	if (app.click && delayClick > 10)
	{
		InstantiateBullet(player.x, player.y);
		delayClick = 0;
	}

	if (player.health <= 0)
	{
		player.Restart();
		bullets.clear();
		enemies.clear();
	}
}

void DrawDelegate()
{
	DrawFunctions::Blit(tDirt, 0, 0, camera);
	player.Draw();

	for (auto& _enemy : enemies)
	{
		_enemy->Draw();
	}

	for (auto& _bullet : bullets)
	{
		_bullet->Draw();
	}

	app.Display();
	app.Clear();
}

int main(int argc, char** args)
{
	long then;
	float remainder;
	remainder = 0;

	Init();

	while(!app.done)
	{
		then = SDL_GetTicks();
		UpdateDelegate();
		DrawDelegate();
		FrameRate::CapFrameRate(&then, &remainder);
	}

	enemies.clear();
	bullets.clear();

	SDL_Quit();
	return 0;
}