#include <Engine.h>

Engine::Engine()
{
	number = 0.0f;
	m_pSceneManager = SceneManager::GetInstance();
}

Engine::~Engine()
{

}

void Engine::Update(float deltaTime)
{
	m_pSceneManager->Update(deltaTime);
}

void Engine::Draw()
{
	m_pSceneManager->Draw();
			number+=0.01f;
			if(number>1.0f)
				number = 0.0f;
			glClearColor(number,number,number, 1.0f); // Sets the clear color
			glClear(GL_COLOR_BUFFER_BIT); // Clears the display buffer

			
			
}