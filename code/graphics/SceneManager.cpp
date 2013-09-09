#include "SceneManager.h"

SceneManager* SceneManager::m_pSceneManager=nullptr;

SceneManager::SceneManager( void )
{
	m_ActiveScene=nullptr;
	m_NewActiveScene=nullptr;
	m_bSwitchingScene=false;
	m_bInitialized=false;
	CurrentSceneName=_T("");

}
SceneManager::~SceneManager( void ){}

SceneManager* SceneManager::GetInstance()
{
	if(m_pSceneManager==nullptr)
	{
		m_pSceneManager = new SceneManager();
	}
	return m_pSceneManager;
}

bool SceneManager::SetActiveScene( tstring name )
{
	if(CurrentSceneName==name)return true;

	if(m_ScenesList.find(name)!=m_ScenesList.end())
	{
		m_NewActiveScene = m_ScenesList[name];
		m_bSwitchingScene = true;
		m_bInitialized=m_NewActiveScene->IsInitialized();
		CurrentSceneName=name;
		return true;
	}else
	{
		m_bSwitchingScene=false;
		return false;
	}
	
	return true;
}

bool SceneManager::AddScene( tstring name,BaseScene* scene )
{
	if(m_ScenesList.find(name)==m_ScenesList.end())
	{
		m_ScenesList[name]=scene;
		return true;
	}
#ifdef DEBUG	
	else
	{
		cout<< "Scene :"<< name << " already exists"<<endl;
	}
#endif
	return false;
}

bool SceneManager::RemoveScene( tstring name )
{
	if(m_ScenesList.find(name)!=m_ScenesList.end())
	{
		m_ScenesList.erase(name);
		return true;
	}
#ifdef DEBUG	
	else
	{
		cout<< "Scene :"<< name << " already exists"<<endl;
	}
#endif
	return false;
}

bool SceneManager::InitializeCurScene()
{
	if(m_bInitialized)return true;
	if(m_NewActiveScene==nullptr)return false;
	m_NewActiveScene->Initialize();
	m_bInitialized=m_NewActiveScene->IsInitialized();
	return m_bInitialized;

}

void SceneManager::Update(float deltaTime)
{
	if(m_bSwitchingScene)
	{
		if(!m_bInitialized)InitializeCurScene();


		m_ActiveScene = m_NewActiveScene;
		m_NewActiveScene=nullptr;
		m_bSwitchingScene=false;
	}

	if(m_ActiveScene!=nullptr){

		m_ActiveScene->Update(deltaTime);
	}
#ifdef DEBUG	
	else
	{
		cout<< "Invalid or No Active Scene"<<endl;
	}
#endif

}


void SceneManager::Draw()
{
	if(m_ActiveScene!=nullptr)
		m_ActiveScene->Draw();
#ifdef DEBUG	
	else
	{
		cout<< "Invalid or No Active Scene"<<endl;
	}
#endif
}




