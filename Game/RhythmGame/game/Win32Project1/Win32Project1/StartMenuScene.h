#pragma once

#include "Scene.h"

class Sprite;

class StartMenuScene : public Scene
{

private:
	int _selectPosX;
	int _selectPosY;

	Sprite* _selectBoxSprite;
	//Sprite* _backgroundSprite;
	int _updateTick;
	int _waitTick;

public:
	StartMenuScene();
	~StartMenuScene();

	void Init();
	void Deinit();
	void Update(int deltaTime);
	void Render();
	

	void KeyUp(unsigned int keyCode);
	void KeyDown(unsigned int keyCode);

};
