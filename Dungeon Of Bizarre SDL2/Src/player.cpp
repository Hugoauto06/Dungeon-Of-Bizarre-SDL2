#include "player.h"

Player::Player(int pX, int pY, int pSize, SDL_Texture* pTexture)
	:Entity { pX, pY, pSize, pTexture }
{
	health = 100.0f;
	type = "player";
	hurt = false;
}

void Player::Restart()
{
	health = 100.0f;
	hurt = false;
	x = ROOM_MAX_WIDTH/2;
	y = ROOM_MAX_HEIGHT/2;
}

void Player::Update()
{
	positionRect.x = x;
	positionRect.y = y;

	short hsp = ((-app.left) + app.right) * 5;
	short vsp = ((-app.up) + app.down) * 5;

	x = SDL_clamp(x, 0, ROOM_MAX_WIDTH);
	y = SDL_clamp(y, 0, ROOM_MAX_WIDTH);

	x += hsp;
	y += vsp;

	if (hsp > 0)
		flip = SDL_FLIP_NONE;

	if (hsp < 0)
		flip = SDL_FLIP_HORIZONTAL;

	if ((hsp != 0 && vsp != 0) || (hsp != 0 || vsp != 0))
	{
		animated = true;
	}
	else
	{
		animated = false;
		currentFrame = 0;
	}

	if (animated)
		Animate();

	if (hurt)
	{
		hurt = false;
	}
}

void Player::Draw()
{
	DrawFunctions::DrawEntity(*this, camera);
}