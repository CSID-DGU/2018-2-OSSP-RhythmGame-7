#include <stdio.h>
#include "GameSystem.h"
#include "Sprite.h"
#include "SceneManager.h"

#include "OptionScenex1.h"
#include "OptionScenex3.h"
#include "font_option.h"
#include "font_option_select.h"
#include "font_option_exp.h"



OptionScenex3::OptionScenex3()
{
}

OptionScenex3::~OptionScenex3()
{
}

void OptionScenex3::Init()
{

	_X1 = new Font_o("arialbd.ttf", 24);
	_X2 = new Font_o("arialbd.ttf", 24);
	_X3 = new Font_o_s("arialbd.ttf", 60);
	_K5 = new Font_o("arialbd.ttf", 24);
	_K7 = new Font_o("arialbd.ttf", 24);
	_K9 = new Font_o("arialbd.ttf", 24);
	_BACK = new Font_o("arialbd.ttf", 24);
	_SpeedSetting = new Font_o_s("arialbd.ttf", 24);
	_KeySetting = new Font_o_s("arialbd.ttf", 24);


	_backgroundSprite = new Sprite("option_bgd", true);
	_backgroundSprite->SetPosition(GameSystem::GetInstance()->GetWindowWidth() / 2,
		GameSystem::GetInstance()->GetWindowHeight() / 2);

	_waitTick = 3 * 1000;
	_updateTick = 0;
}

void OptionScenex3::Deinit()
{

	delete _backgroundSprite;
}

void OptionScenex3::Update(int deltaTime)
{

	char X1[256];
	sprintf(X1, "X1");
	_X1->SetText(X1, 280, 370);

	char X2[256];
	sprintf(X2, "X2");
	_X2->SetText(X2, 280, 520);

	char X3[256];
	sprintf(X3, "X3");
	_X3->SetText(X3, 270, 660);

	char K5[256];
	sprintf(K5, "5 KEY");
	_K5->SetText(K5, 600, 370);

	char K7[256];
	sprintf(K7, "7 KEY");
	_K7->SetText(K7, 600, 520);

	char K9[256];
	sprintf(K9, "9 KEY");
	_K9->SetText(K9, 600, 670);

	char BACK[256];
	sprintf(BACK, "BACK");
	_BACK->SetText(BACK, 600, 800);

	char SpeedSetting[256];
	sprintf(SpeedSetting, "X%d", BPM / 60);
	_SpeedSetting->SetText(SpeedSetting, 920, 450);

	char KeySetting[256];
	sprintf(KeySetting, "%d KEY", TRACK_COUNT);
	_KeySetting->SetText(KeySetting, 860, 550);



	_backgroundSprite->Update(deltaTime);


}

void OptionScenex3::Render()
{
	_backgroundSprite->Render();
	_X1->Render();
	_X2->Render();
	_X3->Render();
	_K5->Render();
	_K7->Render();
	_K9->Render();
	_BACK->Render();
	_SpeedSetting->Render();
	_KeySetting->Render();

}

void OptionScenex3::KeyUp(unsigned int keyCode)
{


	switch (keyCode)
	{
	case SDLK_SPACE:
		BPM = 180;
		break;
	case SDLK_DOWN:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_OPTIONback);
		break;
	case SDLK_UP:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_OPTIONx2);
		break;
	case SDLK_RIGHT:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_OPTIONk9);
		break;

	default:
		break;
	}

}

void OptionScenex3::KeyDown(unsigned int keyCode)
{
}

OptionScenex3* OptionScenex3::bpm()
{
	return _bpm;
}
float OptionScenex3::getbpm(float bpmnum)
{
	return bpmnum;
}