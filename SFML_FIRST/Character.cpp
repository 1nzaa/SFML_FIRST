#include "Character.h"

using namespace sf;

Character::~Character() {}

void Character::takeDamage(float damage) {
    m_health -= damage;
}

void Character::setPosition(Vector2f& pos) {
    m_pos = pos;
}

void Character::setDirection(Direction direction) {
    m_direction = direction;
}

float Character::getHP() const {
    return m_health;
}

Vector2f Character::getSize() const {
    return m_size;
}

Vector2f Character::getPosition() const {
    return m_pos;
}

Sprite Character::getSprite() const {
    return m_sprite;
}

Direction Character::getDirection() const {
    return m_direction;
}