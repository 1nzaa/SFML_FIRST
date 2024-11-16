#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include <SFML/Graphics.hpp>

class Player : public GameObject {
public:
    Player(const sf::Texture& texture, float x, float y)
        : GameObject(texture, x, y) {}

    void update(float deltaTime, float speed) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            move(0.f, -speed * deltaTime);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            move(0.f, speed * deltaTime);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            move(-speed * deltaTime, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            move(speed * deltaTime, 0.f);
        }
    }

    void scale(float scaleSpeed, float deltaTime) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
            this->scale(1 + scaleSpeed * deltaTime, 1 + scaleSpeed * deltaTime);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
            this->scale(1 - scaleSpeed * deltaTime, 1 - scaleSpeed * deltaTime);
        }
    }
};

#endif // PLAYER_H
