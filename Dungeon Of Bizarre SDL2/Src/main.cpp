#include "main.h"
#include "collision.h"
#include "spawner.h"
#include "SDL_ttf.h"
using namespace std;

App app					= App("Dungeon Of Bizarre", 1280, 720);
SDL_Texture* tPlayer	= DrawFunctions::LoadTexture("player.png");
SDL_Texture* tEnemy		= DrawFunctions::LoadTexture("enemy.png");
SDL_Texture* tBullet	= DrawFunctions::LoadTexture("bullet.png");
SDL_Texture* tDirt		= DrawFunctions::LoadTexture("dirt.png");
Player player			= Player(320, 420, 64, tPlayer);
Camera camera			= Camera(0, 0, 1280, 720);
Spawner spawner			= Spawner();
vector<Bullet*> bullets;
vector<Enemy*> enemies;
TTF_Font* font;
int delayClick = 0;
long score = 0;

void Init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	Mix_Init(MIX_INIT_MP3);
	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);

	font = TTF_OpenFont("font.ttf", 72);
}

void InstantiateEnemy(int pX, int pY)
{
	Enemy* _enemy = new Enemy(pX, pY, 64, tEnemy);
	enemies.push_back(_enemy);
}

void InstantiateBullet(int pX, int pY)
{
	Bullet* _bullet = new Bullet(pX, pY, 16, tBullet);
	_bullet->speed	= 15.0f;
	bullets.push_back(_bullet);

	Mix_Chunk* sndGunshot = Mix_LoadWAV("sndGunshot.wav");
	Mix_VolumeChunk(sndGunshot, 10);
	Mix_PlayChannel(2, sndGunshot, 0);
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
			score += 100;
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

	if (app.click && delayClick > 8)
	{
		InstantiateBullet(player.x, player.y);
		delayClick = 0;
	}

	if (player.health <= 0)
	{
		player.Restart();
		bullets.clear();
		enemies.clear();
		score = 0;
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

	/* Gui */
	SDL_Rect _dst = { 32, 32, 96, 48 };
	SDL_Color _col = { 0, 255, 255, 255 };
	string _s = "Score: " + to_string(score);

	DrawFunctions::DrawText(_s.c_str(), _dst, _col);

	/* Update Display */
	app.Display();
	app.Clear();
}

int main(int argc, char** args)
{
	long then;
	float remainder;
	remainder = 0;

	Init();
	
	Mix_Music* musSong = Mix_LoadMUS("song.mp3");
	Mix_PlayMusic(musSong, false);
	Mix_VolumeMusic(50);

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