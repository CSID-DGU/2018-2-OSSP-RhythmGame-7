#pragma once

#include "Scene.h"

class Sprite;
class Font;

extern int BPM;
extern int TRACK_COUNT;

class OptionScene : public Scene
{
private:
	//Sprite* _backgroundSprite;
	int _updateTick;
	int _waitTick;

	Font* _test;
	Font* _test1;
	Font* _test2;
	Font* _test3;
	Font* _test4;
	Font* _test5;
	Font* _test6;
	Font* _test7;

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
