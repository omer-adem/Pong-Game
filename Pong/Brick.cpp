#include "Brick.h"

Texture Brick::m_texture;

void Brick::setup(float X, float Y)
{
	m_Position.x = X;
	m_Position.y = Y;

	m_Shape.setTexture(m_texture);
	m_Shape.setPosition(m_Position);

	m_Left = FloatRect(m_Position.x - 1, m_Position.y + 6, 1, HEIGHT - 12);
	m_Right = FloatRect(m_Position.x + WIDTH - 1, m_Position.y + 6, 1, HEIGHT - 12);
	m_Top = FloatRect(m_Position.x-3, m_Position.y - 1, WIDTH+3,2);
	m_Bottom = FloatRect(m_Position.x-3, m_Position.y + HEIGHT - 1, WIDTH+3,2);
}

void Brick::restore()
{
	status = 1;
}


Sprite Brick::getShape()
{
	return m_Shape;
}

FloatRect Brick::getLeft()
{
	return m_Left;
}

FloatRect Brick::getRight()
{
	return m_Right;
}

FloatRect Brick::getTop()
{
	return m_Top;
}

FloatRect Brick::getBottom()
{
	return m_Bottom;
}

void Brick::hit()
{
	status = 0;
}