#include "camera.h"


Camera::Camera(int pX, int pY, int pW, int pH)
{
	cameraRect.x = pX;
	cameraRect.y = pY;
	cameraRect.w = pW;
	cameraRect.h = pH;
}

void Camera::FollowPoint(int pX, int pY)
{
	if (pX > cameraRect.w / 2 && pX < ROOM_MAX_WIDTH - (cameraRect.w / 2))
	{
		int _targetX	= pX - (cameraRect.w / 2);
		int _realX		= naive_lerp(_targetX, app.mouseX, 0.02);
		cameraRect.x	= naive_lerp(cameraRect.x, _realX, 0.07);

	}
	if (pY > cameraRect.h / 2 && pY < ROOM_MAX_HEIGHT - (cameraRect.h / 2))
	{
		int _targetY	= pY - (cameraRect.h / 2);
		int _realY		= naive_lerp(_targetY, app.mouseY, 0.02);
		cameraRect.y	= naive_lerp(cameraRect.y, _realY, 0.07);
	}
}