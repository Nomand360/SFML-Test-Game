#include "Game.h"

#include <iostream>

Game::Game()
    : mWindow(sf::VideoMode(640, 480), "SFML Application")
{
    mWindow.setFramerateLimit(60);
    mPlayer.setPosition(100.f, 100.f);
    playerSpeed = 100.f;
    textures.load(Textures::ID::Airplane, "../SFML_Avion/Eagle.png");
    mPlayer.setTexture(textures.get(Textures::ID::Airplane));
}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while(mWindow.isOpen()){
        this->processEvent();
        timeSinceLastUpdate += clock.restart();
        while(timeSinceLastUpdate > timePerFrame){
            timeSinceLastUpdate -= timePerFrame;
            this->processEvent();
            this->update(timePerFrame);
        }
        this->render();
    }
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    if(key == sf::Keyboard::W){
        mIsMovingUp = isPressed;
    }
    else if(key == sf::Keyboard::S){
        mIsMovingDown = isPressed;
    }
    else if(key == sf::Keyboard::A){
        mIsMovingLeft = isPressed;
    }
    else if(key == sf::Keyboard::D){
        mIsMovingRight = isPressed;
    }
}

void Game::processEvent()
{
    sf::Event event;
    while(mWindow.pollEvent(event)){
        switch (event.type) {
        case sf::Event::KeyPressed:
            handlePlayerInput(event.key.code, true);
            break;
        case sf::Event::KeyReleased:
            handlePlayerInput(event.key.code, false);
            break;
        case sf::Event::Closed:
            mWindow.close();
            break;
        }
    }
}

void Game::update(sf::Time deltaTime)
{
    sf::Vector2f movement(0.f, 0.f);

    if(mIsMovingUp){
        movement.y -= playerSpeed;
    }
    if(mIsMovingDown){
        movement.y += playerSpeed;
    }
    if(mIsMovingLeft){
        movement.x -= playerSpeed;
    }
    if(mIsMovingRight){
        movement.x += playerSpeed;
    }

    mPlayer.move(movement * deltaTime.asSeconds());
}

void Game::render()
{
    mWindow.clear();
    mWindow.draw(this->mPlayer);
    mWindow.display();
}
