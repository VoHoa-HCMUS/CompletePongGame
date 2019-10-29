#include "Paddle.h"
/*Hàm set Paddle đi lên*/
void Paddle::SetUp(bool _Up)
{
	Up = _Up;
}
/*Hàm set Paddle đi xuống*/
void Paddle::SetDown(bool _Down)
{
	Down = _Down;
}
void Paddle::SetSpeed(float x)
{
	Speed = x;
}
/*Hàm kiểm tra Paddle đi lên*/
bool Paddle::MoveUp()
{
	return Up;
}
/*Hàm kiểm tra Paddle đi xuống*/
bool Paddle::MoveDown()
{
	return Down;
}
/*Hàm lấy vận tốc Paddle*/
float Paddle::GetSpeed()
{
	return Speed;
}
/*Constructor của Paddle*/
Paddle::Paddle()
{
	RectangleShape::setSize(sf::Vector2f(20, 150));
	RectangleShape::setOutlineThickness(3);
	RectangleShape::setOutlineColor(sf::Color::Black);
	Speed = 400.f;
	Up = false;
	Down = false;
}