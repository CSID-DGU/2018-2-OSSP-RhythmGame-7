#pragma once

class Sprite;

class Scene
{
protected:
	Sprite* _backgroundSprite;
	Sprite* _lifeBarSprite;
	Sprite* _option;

public:
	Scene();
	~Scene();

	virtual void Init();
	virtual void Deinit();
	virtual void Update(int deltaTime);
	virtual void Render();
	
	virtual void KeyUp(unsigned int keyCode);
	virtual void KeyDown(unsigned int keyCode);
};
