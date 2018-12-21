#pragma once
#pragma once

#include "Scene.h"

class Sprite;
class Font_o_s;
class Font_o;

extern int BPM;
extern int TRACK_COUNT;

class OptionScenex1 : public Scene
{
private:
	//Sprite* _backgroundSprite;
	int _updateTick;
	int _waitTick;

	
	Font_o_s* _X1;
	Font_o* _X2;
	Font_o* _X3;
	Font_o* _K5;
	Font_o* _K7;
	Font_o* _K9;
	Font_o* _BACK;
	Font_o_s* _SpeedSetting;
	Font_o_s* _KeySetting;
	

	OptionScenex1* _bpm;

public:
	OptionScenex1();
	~OptionScenex1();

	void Init();
	void Deinit();
	void Update(int deltaTime);
	void Render();

	void KeyUp(unsigned int keyCode);
	void KeyDown(unsigned int keyCode);

	OptionScenex1* bpm();
	float getbpm(float bpmnum);




};
