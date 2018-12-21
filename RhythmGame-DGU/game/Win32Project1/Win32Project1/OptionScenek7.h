#pragma once
#pragma once

#include "Scene.h"

class Sprite;
class Font_o_s;
class Font_o;



class OptionScenek7 : public Scene
{
private:
	//Sprite* _backgroundSprite;
	int _updateTick;
	int _waitTick;


	Font_o* _X1;
	Font_o* _X2;
	Font_o* _X3;
	Font_o* _K5;
	Font_o_s* _K7;
	Font_o* _K9;
	Font_o* _BACK;
	Font_o_s* _SpeedSetting;
	Font_o_s* _KeySetting;


	OptionScenek7* _bpm;

public:
	OptionScenek7();
	~OptionScenek7();

	void Init();
	void Deinit();
	void Update(int deltaTime);
	void Render();

	void KeyUp(unsigned int keyCode);
	void KeyDown(unsigned int keyCode);

	OptionScenek7* bpm();
	float getbpm(float bpmnum);




};
