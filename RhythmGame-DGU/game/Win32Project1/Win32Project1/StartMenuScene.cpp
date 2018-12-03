#include <stdio.h>
#include "GameSystem.h"
#include "Sprite.h"
#include "SceneManager.h"

#include "StartMenuScene.h"
#include "Font.h"


StartMenuScene::StartMenuScene()
{
}

StartMenuScene::~StartMenuScene()
{
}

void StartMenuScene::Init()
{
	_backgroundSprite = new Sprite("startspr", true);
	_backgroundSprite->SetPosition(GameSystem::GetInstance()->GetWindowWidth() / 2,
		GameSystem::GetInstance()->GetWindowHeight() / 2);

	_waitTick = 3 * 1000;
	_updateTick = 0;
}

void StartMenuScene::Deinit()
{
	delete _backgroundSprite;
}

void StartMenuScene::Update(int deltaTime)
{
	_backgroundSprite->Update(deltaTime);
}

void StartMenuScene::Render()
{
	_backgroundSprite->Render();
}

void StartMenuScene::KeyUp(unsigned int keyCode)
{
	

	switch (keyCode)
	{
	case SDLK_SPACE:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_GAME);
		break;
	case SDLK_DOWN:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_OPTION1);
		break;
	default:
		break;
	}
}

void StartMenuScene::KeyDown(unsigned int keyCode)
{
}
