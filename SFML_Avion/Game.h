#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>


class Game
{
private:
    sf::Time timePerFrame = sf::seconds(1.f / 60.f);
    sf::RenderWindow mWindow;
    sf::Sprite mPlayer;
    bool mIsMovingUp{false};
    bool mIsMovingDown{false};
    bool mIsMovingRight{false};
    bool mIsMovingLeft{false};
    float playerSpeed{0};

public:
    Game();
    void run();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
    void processEvent();
    void update(sf::Time deltaTime);
    void render();

};

#endif // GAME_H
