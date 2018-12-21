#include "GameSystem.h"
#include "SceneManager.h"

GameSystem* GameSystem::_instance = 0;

GameSystem::GameSystem()
{

}

GameSystem::~GameSystem()
{

}

GameSystem* GameSystem::GetInstance()
{
	if (0 == _instance)
	{
		_instance = new GameSystem();
	}
	return _instance;
}

int GameSystem::GetWindowWidth()
{
	return 1280;
}

int GameSystem::GetWindowHeight()
{
	return 960;
}

void GameSystem::Quit()
{
	SDL_Event newEvent;
	newEvent.type = SDL_QUIT;
	SDL_PushEvent(&newEvent);
}

int GameSystem::GetTotalPlayingTime()
{
	int playingTime = 60 * 10 * 100;
	return playingTime;
}

void GameSystem::SetTrackHeight(int trackHeight)
{
	_trackHeight = trackHeight;
}

int GameSystem::GetTrackHeight()
{
	return _trackHeight;
}

void GameSystem::SetRenderer(SDL_Renderer* sdlRenderer)
{
	_sdlRenderer = sdlRenderer;
}

SDL_Renderer* GameSystem::GetRenderer()
{
	return _sdlRenderer;
}