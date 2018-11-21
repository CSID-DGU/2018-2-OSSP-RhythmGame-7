#include <stdio.h>
#include "GameSystem.h"
#include "Sprite.h"
#include "SceneManager.h"

#include "OptionScene.h"
#include "Font.h"

int BPM = 60;
int TRACK_COUNT = 5;

OptionScene::OptionScene()
{
}

OptionScene::~OptionScene()
{
}

void OptionScene::Init()
{
	_test = new Font("arialbd.ttf", 50);
	_test1 = new Font("arialbd.ttf", 50);
	_test2 = new Font("arialbd.ttf", 50);
	_test3 = new Font("arialbd.ttf", 50);
	_test4 = new Font("arialbd.ttf", 50);
	_test5 = new Font("arialbd.ttf", 50);
	_test6 = new Font("arialbd.ttf", 50);
	_test7 = new Font("arialbd.ttf", 50);

	_backgroundSprite = new Sprite("backgroundspr", true);
	_backgroundSprite->SetPosition(GameSystem::GetInstance()->GetWindowWidth() / 2,
		GameSystem::GetInstance()->GetWindowHeight() / 2);

	_waitTick = 3 * 1000;
	_updateTick = 0;
}

void OptionScene::Deinit()
{

	delete _backgroundSprite;
}

void OptionScene::Update(int deltaTime)
{

	char text[256];
	sprintf(text, "SPEED");
	_test->SetText(text, 450, 300);

	char text1[256];
	sprintf(text1, "X1");
	_test1->SetText(text1, 450, 350);

	char text2[256];
	sprintf(text2, "X2");
	_test2->SetText(text2, 450, 400);

	char text3[256];
	sprintf(text3, "X3");
	_test3->SetText(text3, 450, 450);

	char text4[256];
	sprintf(text4, "KEY COUNT");
	_test4->SetText(text4, 450, 500);

	char text5[256];
	sprintf(text5, "5 KEY");
	_test5->SetText(text5, 450, 550);

	char text6[256];
	sprintf(text6, "7 KEY");
	_test6->SetText(text6, 450, 600);

	char text7[256];
	sprintf(text7, "9 KEY");
	_test7->SetText(text7, 450, 650);

	_backgroundSprite->Update(deltaTime);


}

void OptionScene::Render()
{
	_backgroundSprite->Render();
	_test->Render();
	_test1->Render();
	_test2->Render();
	_test3->Render();
	_test4->Render();
	_test5->Render();
	_test6->Render();
	_test7->Render();
}

void OptionScene::KeyUp(unsigned int keyCode)
{
	

	switch (keyCode)
	{
	case SDLK_b:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_OPTION1);
		break;
	case SDLK_1:
		BPM = 60;

		break;
	case SDLK_2:
		BPM = 120;

		break;
	case SDLK_3:
		BPM = 180;

		break;
	case SDLK_4:
		TRACK_COUNT = 5;

		break;
	case SDLK_5:
		TRACK_COUNT = 7;

		break;
	case SDLK_6:
		TRACK_COUNT = 9;

	default:
		break;
	}
	
}

void OptionScene::KeyDown(unsigned int keyCode)
{
}

OptionScene* OptionScene::bpm()
{
	return _bpm;
}
float OptionScene::getbpm(float bpmnum)
{
	return bpmnum;
}