#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>

class Entity
{
public:
    Entity() = default;

    inline void setVelocity(sf::Vector2f& velocity)
    {
        mVelocity = velocity;
    }
    void setVelocity(float vX, float vY);
    inline const sf::Vector2f& getVelocity() const
    {
        return mVelocity;
    }

private:
    sf::Vector2f mVelocity {};
};

#endif // ENTITY_H
