#include "Ball.h"

Ball::Ball(float X, float Y)
{
	m_Position.x = X;
	m_Position.y = Y;
	m_texture.loadFromFile("ball.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_Position);
}

FloatRect Ball::getPosition()
{
	return m_sprite.getGlobalBounds();
}

Sprite Ball::getShape() {
	return m_sprite;
}
float Ball::getDirectionX()
{
	return m_DirectionX;
}
float Ball::getDirectionY()
{
	return m_DirectionY;
}

void Ball::ChangeX()
{
	m_DirectionX *= -1;
}

void Ball::ChangeY()
{
	m_DirectionY *= -1;
}

void Ball::IncreaseXSpeed(float Speed)
{
	m_DirectionX += Speed;
}

void Ball::IncreaseYSpeed()
{
	if(!(m_DirectionY < -1.0f))
		m_DirectionY -= 0.01f;
}

void Ball::OutOfBounds() {
	m_DirectionX = .4f;
	m_DirectionY = -.4f;
	m_Position.x = 1920 / 2;
	m_Position.y = 1080 / 2 + 250;
}

void Ball::update(Time dt) {
	m_Position.x += m_Speed * m_DirectionX * dt.asSeconds();
	m_Position.y += m_Speed * m_DirectionY * dt.asSeconds();
	m_sprite.setPosition(m_Position);
}