#pragma once
#include <iostream>
#include "app.h"
#include "SDL.h"
#include "SDL_image.h"
#include "camera.h"
#include "entity.h"

extern App app;

class DrawFunctions
{
public:
	static void DrawRectangle(int pX, int pY, int pWidth, int pHeight);
	static void DrawRectangle(int pX, int pY, int pWidth, int pHeight, int pR, int pG, int pB, int pAlpha);
	static void DrawEntity(Entity pEntity);
	static void DrawEntity(Entity pEntity, Camera pCamera);
	static void DrawEntity(Entity pEntity, Camera pCamera, double pAngle);
	static void Blit(SDL_Texture* pTexture, int pX, int pY);
	static void Blit(SDL_Texture* pTexture, int pX, int pY, Camera pCamera);

	static SDL_Texture* LoadTexture(const char* pFilepath);
	static SDL_Point GetTextureSize(SDL_Texture* pTexture);
};