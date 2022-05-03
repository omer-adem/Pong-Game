#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball
{
private:
	Vector2f m_Position;
	Texture m_texture;
	Sprite m_sprite;
	float m_Speed = 1200.0f;
	float m_DirectionX = .4f;
	float m_DirectionY = .4f;

public:
	Ball(float X, float Y);
	FloatRect getPosition();
	Sprite getShape();
	float getDirectionX();
	float getDirectionY();

	void ChangeX();
	void ChangeY();
	void IncreaseXSpeed(float Speed);
	void IncreaseYSpeed();
	void OutOfBounds();
	void update(Time dt);
};