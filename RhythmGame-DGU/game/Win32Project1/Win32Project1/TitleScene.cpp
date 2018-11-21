#include <stdio.h>
#include "GameSystem.h"
#include "Sprite.h"
#include "SceneManager.h"

#include "TitleScene.h"
#include "Font.h"


TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
	_test = new Font("arialbd.ttf", 24);

	_backgroundSprite = new Sprite("backgroundspr", true);
	_backgroundSprite->SetPosition(GameSystem::GetInstance()->GetWindowWidth() / 2,
		GameSystem::GetInstance()->GetWindowHeight() / 2);
	
	_waitTick = 3 * 1000;
	_updateTick = 0;
}

void TitleScene::Deinit()
{
	delete _backgroundSprite;
}

void TitleScene::Update(int deltaTime)
{
	char text[256];
	sprintf(text, "DONGGUK Rhythm Tak");
	_test->SetText(text, 800, 700);
	_backgroundSprite->Update(deltaTime);
}

void TitleScene::Render()
{
	_backgroundSprite->Render();
	_test->Render();
}

void TitleScene::KeyUp(unsigned int keyCode)
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

void TitleScene::KeyDown(unsigned int keyCode)
{
}
