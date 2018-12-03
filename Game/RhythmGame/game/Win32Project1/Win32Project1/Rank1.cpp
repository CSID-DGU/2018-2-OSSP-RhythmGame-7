#include <stdio.h>
#include "GameSystem.h"
#include "Sprite.h"
#include "SceneManager.h"

#include "Rank1.h"
#include "Font.h"


Rank1::Rank1()
{
}

Rank1::~Rank1()
{
}

void Rank1::Init()
{
	_test = new Font("arialbd.ttf", 24);

	_backgroundSprite = new Sprite("rank", true);
	_backgroundSprite->SetPosition(GameSystem::GetInstance()->GetWindowWidth() / 2,
		GameSystem::GetInstance()->GetWindowHeight() / 2);

	_updateTick = 0;
}

void Rank1::Deinit()
{

	delete _backgroundSprite;
}

void Rank1::Update(int deltaTime)
{

	/*char text[256];
	sprintf(text, "RHYTHM GAME TITLE");
	_test->SetText(text, 375, 300);
*/
	_backgroundSprite->Update(deltaTime);


}

void Rank1::Render()
{
	_backgroundSprite->Render();
	_test->Render();
}

void Rank1::KeyUp(unsigned int keyCode)
{
	switch (keyCode)
	{
	case SDLK_UP:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_OPTION1);
		break;
	case SDLK_DOWN:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_QUIT);
		break;
	case SDLK_SPACE:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_RANK1);
		break;

	default:
		break;
	}
}

void Rank1::KeyDown(unsigned int keyCode)
{
}
