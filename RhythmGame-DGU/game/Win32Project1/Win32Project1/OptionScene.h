#pragma once

#include "Scene.h"

class Sprite;
class Font_o;

extern int BPM;
extern int TRACK_COUNT;

class OptionScene : public Scene
{
private:
	//Sprite* _backgroundSprite;
	int _updateTick;
	int _waitTick;

	Font_o* _test;
	Font_o* _test1;
	Font_o* _test2;
	Font_o* _test3;
	Font_o* _test4;
	Font_o* _test5;
	Font_o* _test6;
	Font_o* _test7;
	Font_o* _test8;

	OptionScene* _bpm;

public:
	OptionScene();
	~OptionScene();

	void Init();
	void Deinit();
	void Update(int deltaTime);
	void Render();

	void KeyUp(unsigned int keyCode);
	void KeyDown(unsigned int keyCode);

	OptionScene* bpm();
	float getbpm(float bpmnum);
	
	
	

};
