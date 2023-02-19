#pragma once
#include "SDL.h"
class FrameRate
{
public:
	static void CapFrameRate(long* then, float* remainder);
};