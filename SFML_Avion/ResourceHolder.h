#ifndef RESOURCEHOLDER_H
#define RESOURCEHOLDER_H
#include <SFML/Graphics.hpp>
#include <map>
#include <memory>
#include <cassert>

namespace Textures {
    enum class ID{Landscape, Airplane, Missile};
}


template<typename Resource, typename Identifier>
class ResorceHolder
{
private:
    std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
public:
    void load(Identifier id, const std::string &fileName);
    Resource &get(Identifier id);
    const Resource &get(Identifier id) const;
};

template<typename Resource, typename Identifier>
void ResorceHolder<Resource, Identifier>::load(Identifier id, const std::string &fileName)
{
    std::unique_ptr<Resource> texture(new Resource());
    if(!texture->loadFromFile(fileName)){
        throw std::runtime_error("Texture not loaded: " + fileName);
    }
    auto inserted = mResourceMap.insert(std::make_pair(id, std::move(texture)));
    assert(inserted.second);
}

template<typename Resource, typename Identifier>
Resource &ResorceHolder<Resource, Identifier>::get(Identifier id)
{
    auto found = mResourceMap.find(id);
    assert(found != mResourceMap.end());
    return *found->second;
}

template<typename Resource, typename Identifier>
const Resource &ResorceHolder<Resource, Identifier>::get(Identifier id) const
{
    auto found = mResourceMap.find(id);
    assert(found != mResourceMap.end());
    return *found->second;
}

#endif // RESOURCEHOLDER_H
