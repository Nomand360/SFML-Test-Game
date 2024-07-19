#ifndef RESOURCEHOLDER_H
#define RESOURCEHOLDER_H
#include <cassert>
#include <map>
#include <memory>
#include <stdexcept>
#include <string>

namespace Textures {
enum class ID {
    Landscape,
    Airplane,
    Missile
};
}

template <typename Resource, typename Identifier>
class ResorceHolder {
private:
    std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;

public:
    void load(Identifier id, const std::string& fileName)
    {
        auto resource = std::make_unique<Resource>();
        if (!resource->loadFromFile(fileName)) {
            throw std::runtime_error("Texture not loaded: " + fileName);
        }
        insertResource(id, resource);
    }
    template <typename Parameter>
    void load(Identifier id, const std::string& filename, const Parameter& secondParam)
    {
        auto resource = std::make_unique<Resource>();
        if (!resource->loadFromFile(filename, secondParam))
            throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);

        insertResource(id, resource);
    }
    Resource& get(Identifier id)
    {
        auto found = mResourceMap.find(id);
        assert(found != mResourceMap.end());
        return *found->second;
    }
    const Resource& get(Identifier id) const
    {
        auto found = mResourceMap.find(id);
        assert(found != mResourceMap.end());
        return *found->second;
    }

private:
    void insertResource(Identifier id, std::unique_ptr<Resource>& resource)
    {
        auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));
        assert(inserted.second);
    }
};

#endif // RESOURCEHOLDER_H
