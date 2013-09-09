#pragma once
#ifndef ENGINE
#define ENGINE
#include <Win32toAndroid.h>
#include "code/graphics/SceneManager.h"


class Engine
{
	public:
		Engine();
		~Engine();

		void Draw();
		void Update(float deltaTime);

	private:
		float number;
		SceneManager* m_pSceneManager;

};
#endif