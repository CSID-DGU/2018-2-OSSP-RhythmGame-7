#include <stdio.h>
#include "GameSystem.h"
#include "Sprite.h"
#include "SceneManager.h"

#include "Quit.h"
#include "Font.h"


Quit::Quit()
{
}

Quit::~Quit()
{
}

void Quit::Init()
{
	_test = new Font("arialbd.ttf", 24);

	_backgroundSprite = new Sprite("quit", true);
	_backgroundSprite->SetPosition(GameSystem::GetInstance()->GetWindowWidth() / 2,
		GameSystem::GetInstance()->GetWindowHeight() / 2);

	_updateTick = 0;
}

void Quit::Deinit()
{

	delete _backgroundSprite;
}

void Quit::Update(int deltaTime)
{

	/*char text[256];
	sprintf(text, "RHYTHM GAME TITLE");
	_test->SetText(text, 375, 300);
*/
	_backgroundSprite->Update(deltaTime);


}

void Quit::Render()
{
	_backgroundSprite->Render();
	_test->Render();
}

void Quit::KeyUp(unsigned int keyCode)
{
	switch (keyCode)
	{
	case SDLK_UP:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_RANK1);
		break;
	case SDLK_SPACE:
		exit(0);
		break;
	
	}
}

void Quit::KeyDown(unsigned int keyCode)
{
}
