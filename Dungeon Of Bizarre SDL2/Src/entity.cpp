#include "entity.h"

Entity::Entity(int pX, int pY, int pSize, SDL_Texture* pTexture)
	:x(pX), y(pY), spritesheet(pTexture), size (pSize)
{
	animated		= false;
	flip			= SDL_FLIP_NONE;

	spriteRect.x	= 0;
	spriteRect.y	= 0;
	spriteRect.w	= size;
	spriteRect.h	= size;

	positionRect.x	= x;
	positionRect.y	= y;
	positionRect.w	= size;
	positionRect.h	= size;

	type = "entity";

	SDL_Point _size;
	SDL_QueryTexture(pTexture, NULL, NULL, &_size.x, &_size.y);

	maxFrames = (short) _size.x / pSize;
	maxFrames -= 1;
}

void Entity::Animate()
{
	clock++;
	if (clock >= 3)
	{
		currentFrame++;
		if (currentFrame > maxFrames)
		{
			currentFrame = 0;
		}

		spriteRect.x = size * currentFrame;
		clock = 0;
	}
}