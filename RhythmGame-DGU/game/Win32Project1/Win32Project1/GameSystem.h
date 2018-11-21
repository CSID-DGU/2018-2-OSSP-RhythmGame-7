#pragma once

#include "SDL.h"

class GameSystem
{
private:
	GameSystem();
	~GameSystem();

private:
	static GameSystem* _instance;

public:
	static GameSystem* GetInstance();
	
	int GetWindowWidth();
	int GetWindowHeight();

	void Quit();

private:
	int _trackHeight;

public:
	int GetTotalPlayingTime();
		
	void SetTrackHeight(int trackHeight);
	int GetTrackHeight();

private:
	SDL_Renderer* _sdlRenderer;

public:
	void SetRenderer(SDL_Renderer* sdlRenderer);
	SDL_Renderer* GetRenderer();

private:
	int _finalScore;
	int _maxCombo;

public:
	int GetFinalScore() { return _finalScore; }
	void SetFinalScore(int finalScore) { _finalScore = finalScore; }

	int GetMaxCombo() { return _maxCombo; }
	void SetMaxCombo(int maxCombo) { _maxCombo = maxCombo; }
};
