#ifndef RESOURCEHOLDER_H
#define RESOURCEHOLDER_H
#include <SFML/Graphics.hpp>
#include <map>
#include <memory>

namespace Textures {
    enum class ID{Landscape, Airplane, Missile};
}

class ResorceHolder
{
private:
    std::map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap;
public:
    ResorceHolder();
    void loadingFromFiles(Textures::ID id, const std::string &fileName);
    sf::Texture &get(Textures::ID id);
    const sf::Texture &get(Textures::ID id) const;
};

#endif // RESOURCEHOLDER_H
