#include <sstream>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Sopa.h"
#include "Brick.h"
#include "Ball.h"
using namespace sf;
using namespace std;

void writeScore(int& puan, Text& txt);

int main()
{
	int score = 0;
	VideoMode vm(1366,766);

	RenderWindow window(vm, "Brick Hitter");

	View view(sf::FloatRect(0, 0, 1920, 1080));
	window.setView(view);

	Sopa sopa(view.getSize().x/2, view.getSize().y - 20);
	Ball ball(view.getSize().x / 2, view.getSize().y / 2 + 150);

	Texture T_background;
	Sprite S_background;

	T_background.loadFromFile("background.jpg");
	S_background.setTexture(T_background);

	Brick bricks[7][5];
	Brick::m_texture.loadFromFile("brick.png");
	int OffsetX = 125;
	int OffsetY = 75;
	int PaddingX = 250;
	int PaddingY = 100;

	bool playing = true;

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 5; j++)
			bricks[i][j].setup(i * PaddingX + OffsetX, j * PaddingY + OffsetY);
	}

	Clock clock;

	Text Score;

	Font font;
	font.loadFromFile("fonts/Bombing.ttf");
	Score.setFont(font);

	Score.setString("Score = 0");
	Score.setCharacterSize(50);
	Score.setPosition(5, 0);

	window.setFramerateLimit(75);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				// Quit the game when the window is closed
				window.close();
		}

		if (!playing)
		{
			ball.OutOfBounds();
			score = 0;
			writeScore(score, Score);
			for (int i = 0; i < 7; i++)
			{
				for (int j = 0; j < 5; j++)
					bricks[i][j].restore();
			}
			playing = true;
		}

		// Handle the player quitting
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left) && sopa.getPosition().left > 6)
		{
			sopa.moveLeft();
		}
		else
		{
			sopa.stopLeft();
		}

		if (Keyboard::isKeyPressed(Keyboard::Right) && sopa.getPosition().left + sopa.getPosition().width < view.getSize().x - 6)
		{
			sopa.moveRight();
		}
		else
		{
			sopa.stopRight();
		}

		Time dt = clock.restart();
		ball.update(dt);
		sopa.update(dt);

		// COLLISION PART
        
		int startX = (ball.getPosition().left - OffsetX) / PaddingX-1;
		int endX = startX + 2;
		int startY = (ball.getPosition().top - OffsetY) / PaddingY-1;
		int endY = startY + 2;

		if (startX < 0)
		{
			startX = 0;
			endX = 1;
		}
		else if (endX > 6)
		{
			endX = 6;
			startX = 5;
		}
		if (startY < 0)
		{
			startY = 0;
			endY = 1;
		}
		else if (endY > 4)
		{
			startY = 3;
			endY = 4;
		}

		for (int j = startX; j <= endX; j++)
		{
			for (int k = startY; k <= endY; k++)
			{
				if (bricks[j][k].status == 0)
					continue;

				if (ball.getPosition().intersects(bricks[j][k].getLeft()) && ball.getDirectionX() > 0)
				{
					writeScore(++score, Score);
					bricks[j][k].hit();
					ball.ChangeX();
				}
				else if (ball.getPosition().intersects(bricks[j][k].getRight()) && ball.getDirectionX() < 0)
				{
					writeScore(++score, Score);
					bricks[j][k].hit();
					ball.ChangeX();
				}
				else if (ball.getPosition().intersects(bricks[j][k].getTop()) && ball.getDirectionY() > 0)
				{
					writeScore(++score, Score);
					bricks[j][k].hit();
					ball.ChangeY();
				}
				else if (ball.getPosition().intersects(bricks[j][k].getBottom()) && ball.getDirectionY() < 0)
				{
					writeScore(++score, Score);
					bricks[j][k].hit();
					ball.ChangeY();
				}
			}
		}
		
		if (score >= 35)
			playing = false;

		if ((ball.getPosition().left < 2 && ball.getDirectionX() < 0) || (ball.getPosition().left + 24 > view.getSize().x -2 && ball.getDirectionX() > 0))
			ball.ChangeX();

		if (ball.getPosition().top < 2 && ball.getDirectionY() < 0)
			ball.ChangeY();

		if (ball.getPosition().top > view.getSize().y - 45 && ball.getPosition().intersects(sopa.getPosition()) && ball.getDirectionY() > 0)
		{
			ball.ChangeY();
			ball.IncreaseXSpeed((ball.getPosition().left - sopa.getPosition().left - WIDTH / 2) / (WIDTH * 2));
			ball.IncreaseYSpeed();
		}

		else if (ball.getPosition().top > view.getSize().y - 26 && ball.getDirectionY() > 0)
		{
			writeScore(score, Score);
			playing = false;
		}

		window.clear();
		window.draw(S_background);
		window.draw(Score);
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (bricks[i][j].status == 1)
					window.draw(bricks[i][j].getShape());
			}
		}
		window.draw(ball.getShape());
		window.draw(sopa.getShape());
		window.display();
	}
	return 0;
}

void writeScore(int& puan, Text &txt)
{
	stringstream ss;
	ss << "Score = " << puan;
	txt.setString(ss.str());
}