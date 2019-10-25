#pragma once
#include <SFML/Graphics.hpp>
class Paddle : public sf::RectangleShape
{
private:
	bool Up;
	bool Down;
	float Speed;
public:
	void SetUp(bool);
	void SetDown(bool);
	void SetSpeed(float);
	bool MoveUp();
	bool MoveDown();
	float GetSpeed();
	Paddle();
};
