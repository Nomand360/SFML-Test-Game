#include "ResourceHolder.h"
#include <cassert>

ResorceHolder::ResorceHolder()
{

}

void ResorceHolder::loadingFromFiles(Textures::ID id, const std::string &fileName)
{
    std::unique_ptr<sf::Texture> texture(new sf::Texture());
    if(!texture->loadFromFile(fileName)){
        throw std::runtime_error("Texture not loaded: " + fileName);
    }
    auto inserted = mTextureMap.insert(std::make_pair(id, std::move(texture)));
    assert(inserted.second);
}

sf::Texture &ResorceHolder::get(Textures::ID id)
{
    auto found = mTextureMap.find(id);
    assert(found != mTextureMap.end());
    return *found->second;
}
