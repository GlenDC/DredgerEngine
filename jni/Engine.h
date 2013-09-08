#pragma once
#ifndef ENGINE
#define ENGINE
#include <Win32toAndroid.h>
class Engine
{
	public:
		Engine();
		~Engine();

		void Draw();
		void Update();

	private:
		float number;
};
#endif