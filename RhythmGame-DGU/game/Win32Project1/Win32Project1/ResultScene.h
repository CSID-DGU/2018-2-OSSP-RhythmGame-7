#pragma once

#include "Scene.h"

class Sprite;
class Font_r;

class ResultScene : public Scene
{
private:
	//Sprite* _backgroundSprite;
	Font_r* _score;
	Font_r* _maxCombo;

public:
	ResultScene();
	~ResultScene();

	void Init();
	void Deinit();
	void Update(int deltaTime);
	void Render();

	void KeyUp(unsigned int keyCode);
	void KeyDown(unsigned int keyCode);
};
