#include "bullet.h"

Bullet::Bullet(int pX, int pY, int pSize, SDL_Texture* pTexture)
	:Entity{ pX, pY, pSize, pTexture }
{
	speed = 0.0f;
	int X = app.mouseX + camera.cameraRect.x;
	int Y = app.mouseY + camera.cameraRect.y;
	int deltaX = X - player.x;
	int deltaY = Y - player.y;
	angle = std::atan2(deltaY, deltaX) * 180.0000 / PI;
}

void Bullet::Update()
{
	
	x = x + float(speed * cos((double)angle * 0.0174532925));
	y = y + float(speed * sin((double)angle * 0.0174532925));
	positionRect.x = x;
	positionRect.y = y;
}

void Bullet::Draw()
{
	DrawFunctions::DrawEntity(*this, camera, angle);
}