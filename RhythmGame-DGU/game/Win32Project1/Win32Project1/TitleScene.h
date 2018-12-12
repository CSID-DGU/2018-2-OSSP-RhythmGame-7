#pragma once

#include "Scene.h"

class Sprite;
class Font_t;

class TitleScene : public Scene
{
private:
	//Sprite* _backgroundSprite;
	int _updateTick;
	int _waitTick;

	Font_t* _test;
	Font_t* _test1;

public:
	TitleScene();
	~TitleScene();

	void Init();
	void Deinit();
	void Update(int deltaTime);
	void Render();

	void KeyUp(unsigned int keyCode);
	void KeyDown(unsigned int keyCode);
};
