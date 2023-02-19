#include "drawFunctions.h"
using namespace std;
/*
Note:
	Renember that cameras exist, you have to find a way to draw to the position on the room
	and draw to the GUI.
	A little bit like the way GMS2 draws to the screen on separate methods, on "Draw" and
	"Draw GUI".

*/

void DrawFunctions::DrawRectangle(int pX, int pY, int pWidth, int pHeight)
{
	SDL_Rect rect = { pX, pY, pWidth, pHeight };
	SDL_SetRenderDrawColor(app.renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(app.renderer, &rect);
}
void DrawFunctions::DrawRectangle(int pX, int pY, int pWidth, int pHeight, int pR, int pG, int pB, int pAlpha)
{
	SDL_Rect rect = { pX, pY, pWidth, pHeight };
	SDL_SetRenderDrawColor(app.renderer, pR, pG, pB, pAlpha);
	SDL_RenderFillRect(app.renderer, &rect);
}

SDL_Texture* DrawFunctions::LoadTexture(const char* pFilepath)
{
	SDL_Texture* _texture = NULL;
	_texture = IMG_LoadTexture(app.renderer, pFilepath);

	if (_texture == NULL)
	{
		std::cout << "Error loading " << pFilepath << std::endl;
	}

	return _texture;
}

void DrawFunctions::DrawEntity(Entity pEntity)
{
	SDL_RenderCopyEx(app.renderer, pEntity.spritesheet, &pEntity.spriteRect, &pEntity.positionRect, 0, NULL, pEntity.flip);
}

void DrawFunctions::DrawEntity(Entity pEntity, Camera pCamera)
{
	SDL_Rect _dst = { (pEntity.positionRect.x - pEntity.positionRect.w/2) - pCamera.cameraRect.x, (pEntity.positionRect.y - pEntity.positionRect.h / 2) - pCamera.cameraRect.y, pEntity.positionRect.w, pEntity.positionRect.h };
	SDL_RenderCopyEx(app.renderer, pEntity.spritesheet, &pEntity.spriteRect, &_dst, 0, NULL, pEntity.flip);
}
void DrawFunctions::DrawEntity(Entity pEntity, Camera pCamera, double pAngle)
{
	SDL_Rect _dst = { pEntity.positionRect.x - pCamera.cameraRect.x, pEntity.positionRect.y - pCamera.cameraRect.y, pEntity.positionRect.w, pEntity.positionRect.h };
	SDL_RenderCopyEx(app.renderer, pEntity.spritesheet, &pEntity.spriteRect, &_dst, pAngle, NULL, pEntity.flip);
}

void DrawFunctions::Blit(SDL_Texture* pTexture, int pX, int pY)
{
	SDL_Rect _src = { pX, pY, 2000, 2000};
	SDL_RenderCopy(app.renderer, pTexture, &_src, NULL);
}

void DrawFunctions::Blit(SDL_Texture* pTexture, int pX, int pY, Camera pCamera)
{
	SDL_Rect _src = { pX - pCamera.cameraRect.x, pY - pCamera.cameraRect.y, 2000, 2000};
	SDL_RenderCopy(app.renderer, pTexture, NULL, &_src);
}

SDL_Point DrawFunctions::GetTextureSize(SDL_Texture* pTexture)
{
	SDL_Point _size;
	SDL_QueryTexture(pTexture, NULL, NULL, &_size.x, &_size.y);
	return _size;
}


void DrawFunctions::DrawText(const char* pText, SDL_Rect pDst, SDL_Color pColor)
{
	SDL_Surface* text;

	text = TTF_RenderText_Solid(font, pText, pColor);
	if (!text)
	{
		cout << "Failed to render text: " << TTF_GetError() << endl;
	}

	SDL_Texture* text_texture;

	text_texture = SDL_CreateTextureFromSurface(app.renderer, text);

	SDL_Rect dest = { 0, 0, text->w, text->h };

	SDL_RenderCopy(app.renderer, text_texture, &dest, &pDst);

	SDL_DestroyTexture(text_texture);
	SDL_FreeSurface(text);
}
