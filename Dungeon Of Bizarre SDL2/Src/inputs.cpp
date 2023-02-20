#include "inputs.h"

void DoKeyUp(SDL_KeyboardEvent* event)
{
	if (event->repeat == 0)
	{

		switch (event->keysym.scancode)
		{
		case SDL_SCANCODE_UP:
		case SDL_SCANCODE_W:
			app.up = false;
			break;

		case SDL_SCANCODE_DOWN:
		case SDL_SCANCODE_S:
			app.down = false;
			break;

		case SDL_SCANCODE_LEFT:
		case SDL_SCANCODE_A:
			app.left = false;
			break;

		case SDL_SCANCODE_RIGHT:
		case SDL_SCANCODE_D:
			app.right = false;
			break;
		case SDL_SCANCODE_Q:
			app.Q	= false;
			break;
		case SDL_SCANCODE_E:
			app.E	= false;
			break;
		}
	}
}

void DoKeyDown(SDL_KeyboardEvent* event)
{
	if (event->repeat == 0)
	{
		switch (event->keysym.scancode)
		{
		case SDL_SCANCODE_UP:
		case SDL_SCANCODE_W:
			app.up = true;
		break;

		case SDL_SCANCODE_DOWN:
		case SDL_SCANCODE_S:
			app.down = true;
		break;

		case SDL_SCANCODE_LEFT:
		case SDL_SCANCODE_A:
			app.left = true;
		break;

		case SDL_SCANCODE_RIGHT:
		case SDL_SCANCODE_D:
			app.right = true;
		break;
		case SDL_SCANCODE_Q:
			app.Q = true;
		break;
		case SDL_SCANCODE_E:
			app.E = true;
		break;

		case SDL_SCANCODE_F1:
			SDL_SetWindowFullscreen(app.window, SDL_WINDOW_FULLSCREEN);
		break;
		case SDL_SCANCODE_F2:
			SDL_SetWindowFullscreen(app.window, 0);
		break;
		}
	}
}

void DoInput(void)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_MOUSEMOTION:
			SDL_GetMouseState(&app.mouseX, &app.mouseY);
		break;
		case SDL_MOUSEBUTTONUP:
			app.click = false;
		break;

		case SDL_MOUSEBUTTONDOWN:
			app.click = true;
		break;

		case SDL_QUIT:
			app.done = true;
		break;

		case SDL_KEYDOWN:
			DoKeyDown(&event.key);
		break;

		case SDL_KEYUP:
			DoKeyUp(&event.key);
		break;

		default:
		break;
		}
	}
}