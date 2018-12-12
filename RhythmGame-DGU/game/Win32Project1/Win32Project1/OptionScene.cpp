#include <stdio.h>
#include "GameSystem.h"
#include "Sprite.h"
#include "SceneManager.h"

#include "OptionScene.h"
#include "font_option.h"
#include "font_option_exp.h"
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
	
	_test1 = new Font_o("arialbd.ttf", 24);
	_test2 = new Font_o("arialbd.ttf", 24);
	_test3 = new Font_o("arialbd.ttf", 24);
	_test4 = new Font_o("arialbd.ttf", 24);
	_test5 = new Font_o("arialbd.ttf", 24);
	_test6 = new Font_o("arialbd.ttf", 24);
	_test7 = new Font_o("arialbd.ttf", 24);
	_test8 = new Font_o("arialbd.ttf", 24);

	_backgroundSprite = new Sprite("option_bgd", true);
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

	char text1[256];
	sprintf(text1, "X1");
	_test1->SetText(text1, 300, 350);

	char text2[256];
	sprintf(text2, "X2");
	_test2->SetText(text2, 300, 400);

	char text3[256];
	sprintf(text3, "X3");
	_test3->SetText(text3, 300, 450);

	char text4[256];
	sprintf(text4, "5 KEY");
	_test4->SetText(text4, 600, 350);

	char text5[256];
	sprintf(text5, "7 KEY");
	_test5->SetText(text5, 600, 400);

	char text6[256];
	sprintf(text6, "9 KEY");
	_test6->SetText(text6, 600, 450);

	char text7[256];
	sprintf(text7, "Press the 'B'");
	_test7->SetText(text7, 830, 350);

	char text8[256];
	sprintf(text8, "Please press the key to set options");
	_test8->SetText(text8, 230, 800);

	_backgroundSprite->Update(deltaTime);


}

void OptionScene::Render()
{
	_backgroundSprite->Render();
	_test1->Render();
	_test2->Render();
	_test3->Render();
	_test4->Render();
	_test5->Render();
	_test6->Render();
	_test7->Render();
	_test8->Render();
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
	case SDLK_5:
		TRACK_COUNT = 5;

		break;
	case SDLK_7:
		TRACK_COUNT = 7;

		break;
	case SDLK_9:
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