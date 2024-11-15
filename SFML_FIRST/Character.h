#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

enum class Direction : bool {
	LEFT = 0,
	RIGHT = 1
};

class Character {
protected:
	float		 m_health;
	float		 m_speed;
	Vector2f m_size;
	Vector2f m_pos;
	Sprite   m_sprite;
	Direction    m_direction = Direction::RIGHT;

public:
	virtual ~Character();

	virtual void Update(float time) = 0;
	void takeDamage(float damage);

	void setPosition(Vector2f& pos);
	void setDirection(Direction direction);

	float getHP() const;
	Vector2f getSize() const;
	Vector2f getPosition() const;
	Sprite getSprite() const;
	Direction getDirection() const;
};