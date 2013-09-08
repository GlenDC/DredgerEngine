#include <Engine.h>

Engine::Engine()
{
	number = 0.0f;
}

Engine::~Engine()
{

}

void Engine::Update()
{

}

void Engine::Draw()
{
	
			number+=0.01f;
			if(number>1.0f)
				number = 0.0f;
			glClearColor(number,number,number, 1.0f); // Sets the clear color
			glClear(GL_COLOR_BUFFER_BIT); // Clears the display buffer

			
			
}