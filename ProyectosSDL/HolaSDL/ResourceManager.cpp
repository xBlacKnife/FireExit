#include "ResourceManager.h"
#include "Game.h"


ResourceManager::ResourceManager(Game* game) : game_(game)
{
}


ResourceManager::~ResourceManager()
{
}

void ResourceManager::addTexture(string id, string filepath)
{
	textures_.insert(pair<string, Texture*>(id, new Texture(game_->getRenderer(), filepath)));
}

Texture * ResourceManager::getTexture(string id)
{
	return textures_[id];
}