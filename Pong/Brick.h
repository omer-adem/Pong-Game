#pragma once
#include <SFML/Graphics.hpp>
#define WIDTH 150
#define HEIGHT 40
using namespace sf;

class Brick
{
private:
	Sprite m_Shape;
	Vector2f m_Position;

	FloatRect m_Left;
	FloatRect m_Right;
	FloatRect m_Top;
	FloatRect m_Bottom;

public:
	static Texture m_texture;
	bool status = 1;
	Brick() {}
	void setup(float X, float Y);
	void restore();
	Sprite getShape();
	
	FloatRect getLeft();
	FloatRect getRight();
	FloatRect getTop();
	FloatRect getBottom();

	void hit();
};