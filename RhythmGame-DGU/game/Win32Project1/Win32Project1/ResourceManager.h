#pragma once

#include <map>
#include <string>
#include "SDL.h"

class ResourceManager
{
private:
	ResourceManager();
	~ResourceManager();

private:
	static ResourceManager* _instance;

public:
	static ResourceManager* GetInstance();

private:
	std::map<std::string, SDL_Texture*> _textureMap;

public:
	SDL_Texture* FindTexture(const char* filePath);
};
