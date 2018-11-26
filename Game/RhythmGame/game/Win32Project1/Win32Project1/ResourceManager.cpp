#include "SDL_Image.h"
#include "GameSystem.h"

#include "ResourceManager.h"

ResourceManager* ResourceManager::_instance = 0;

ResourceManager::ResourceManager()
{

}

ResourceManager::~ResourceManager()
{

}

ResourceManager* ResourceManager::GetInstance()
{
	if (0 == _instance)
	{
		_instance = new ResourceManager();
	}
	return _instance;
}

SDL_Texture* ResourceManager::FindTexture(const char* filePath)
{
	// 현재 키(filePath) 값에 해당하는 텍스쳐 검색
	std::map<std::string, SDL_Texture*>::iterator it = _textureMap.find(filePath);
	if (it != _textureMap.end())
	{
		// 있으면, 있는 텍스쳐를 반환
		return it->second;
	}
	
	// 없으면, 생성해서 반환
	SDL_Texture* texture = IMG_LoadTexture(GameSystem::GetInstance()->GetRenderer(), filePath);
	_textureMap[filePath] = texture;
	return texture;
}

