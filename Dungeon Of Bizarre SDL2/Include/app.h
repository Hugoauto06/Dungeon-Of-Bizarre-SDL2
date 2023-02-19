#pragma once
#include "SDL.h"

class App
{
public:
	App(const char* pName, int pWidth, int pHeight);

	void Display();
	void Clear();

	int mouseX;
	int mouseY;

	bool done;
	bool up;
	bool down;
	bool left;
	bool right;
	bool click;
	bool fullScreen;

	SDL_Window* window;
	SDL_Renderer* renderer;
};