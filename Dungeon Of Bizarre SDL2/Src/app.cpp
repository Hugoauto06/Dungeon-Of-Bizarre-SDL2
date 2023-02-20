#include "app.h"

App::App(const char* pName, int pWidth, int pHeight)
{
	window		= SDL_CreateWindow(pName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, pWidth, pHeight, SDL_WINDOW_SHOWN);
	renderer	= SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	mouseX		= 0;
	mouseY		= 0;
	done		= false;
	up			= false;
	down		= false;
	left		= false;
	right		= false;
	click		= false;
	Q			= false;
	E			= false;
}

void App::Display()
{
	SDL_SetRenderDrawColor(renderer, 0, 124, 160, 255);
	SDL_RenderPresent(renderer);
}

void App::Clear()
{
	SDL_RenderClear(renderer);
}