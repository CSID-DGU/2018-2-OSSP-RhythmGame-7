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
	// ���� Ű(filePath) ���� �ش��ϴ� �ؽ��� �˻�
	std::map<std::string, SDL_Texture*>::iterator it = _textureMap.find(filePath);
	if (it != _textureMap.end())
	{
		// ������, �ִ� �ؽ��ĸ� ��ȯ
		return it->second;
	}
	
	// ������, �����ؼ� ��ȯ
	SDL_Texture* texture = IMG_LoadTexture(GameSystem::GetInstance()->GetRenderer(), filePath);
	_textureMap[filePath] = texture;
	return texture;
}

