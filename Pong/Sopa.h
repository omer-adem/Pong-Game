#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Sopa {
private:
	RectangleShape m_Shape;
	Vector2f m_Position;

	float m_Speed = 1000.0f;
	bool m_MovingLeft = false;
	bool m_MovingRight = false;

public:
	Sopa(float X, float Y);
	RectangleShape getShape();
	FloatRect getPosition();

	void moveLeft();
	void stopLeft();
	void moveRight();
	void stopRight();
	void update(Time dt);
};
