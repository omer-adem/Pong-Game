#include "Sopa.h"

Sopa::Sopa(float X, float Y)
{
	m_Position.x = X;
	m_Position.y = Y;

	m_Shape.setSize(Vector2f(200,15));
	m_Shape.setFillColor(Color::Magenta);
	m_Shape.setPosition(m_Position);
}

RectangleShape Sopa::getShape()
{
	return m_Shape;
}

FloatRect Sopa::getPosition()
{
	return m_Shape.getGlobalBounds();
}


void Sopa::moveLeft()
{
	m_MovingLeft = true;
}

void Sopa::moveRight()
{
	m_MovingRight = true;
}

void Sopa::stopLeft()
{
	m_MovingLeft = false;
}

void Sopa::stopRight()
{
	m_MovingRight = false;
}

void Sopa::update(Time dt)
{
	if (m_MovingLeft)
	{
		m_Position.x -= m_Speed * dt.asSeconds();
	}
	if (m_MovingRight)
	{
		m_Position.x += m_Speed * dt.asSeconds();
	}
	m_Shape.setPosition(m_Position);
}