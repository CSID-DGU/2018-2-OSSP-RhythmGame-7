#include <stdio.h>
#include "GameSystem.h"
#include "Sprite.h"
#include "SceneManager.h"

#include "LogoScene.h"
#include "Font.h"


LogoScene::LogoScene()
{
}

LogoScene::~LogoScene()
{
}

void LogoScene::Init()
{
	_test = new Font("arialbd.ttf",24);

	_backgroundSprite = new Sprite("backgroundspr", true);
	_backgroundSprite->SetPosition(GameSystem::GetInstance()->GetWindowWidth() / 2,
		GameSystem::GetInstance()->GetWindowHeight() / 2);

	_waitTick = 3 * 1000;
	_updateTick = 0;
}

void LogoScene::Deinit()
{
	
	delete _backgroundSprite;
}

void LogoScene::Update(int deltaTime)
{

	char text[256];
	sprintf(text, "RHYTHM GAME TITLE");
	_test->SetText(text, 375, 300);

	_backgroundSprite->Update(deltaTime);


}

void LogoScene::Render()
{
	_backgroundSprite->Render();
	_test->Render();
}

void LogoScene::KeyUp(unsigned int keyCode)
{
	switch (keyCode)
	{
	case SDLK_SPACE:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_STARTMENU);
		break;
	default:
		break;
	}
}

void LogoScene::KeyDown(unsigned int keyCode)
{
}
