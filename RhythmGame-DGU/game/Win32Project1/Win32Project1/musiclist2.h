#pragma once

#include "Scene.h"

class Sprite;
class Font;

class musiclist2 : public Scene
{
private:
	//Sprite* _backgroundSprite;
	int _updateTick;
	int _waitTick;

	Font* _test;

public:
	musiclist2();
	~musiclist2();

	void Init();
	void Deinit();
	void Update(int deltaTime);
	void Render();

	void KeyUp(unsigned int keyCode);
	void KeyDown(unsigned int keyCode);

};
