#include "BaseScene.h"

BaseScene::BaseScene(tstring name):m_SceneName(name)
{

}


BaseScene::~BaseScene(void)
{

}

void BaseScene::Initialize()
{
	m_bInitialized=true;

}