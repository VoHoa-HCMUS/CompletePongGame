#include "Ball.h"
/*Hàm set góc của trái banh*/
void Ball::SetAngle(float _BallAngle)
{
	BallAngel = _BallAngle;
}
/*Hàm set vận tốc trái banh */
void Ball::SetSpeed(float _Speed)
{
	Speed = _Speed;
}
/*Hàm lấy góc trái banh*/
float Ball::GetAngle()
{
	return BallAngel;
}
/*Hàm lấy tốc độ trái banh*/
float Ball::GetSpeed()
{
	return Speed;
}
/*Constructor của trái banh*/
Ball::Ball()
{
	Radius = 10.f;
	CircleShape::setRadius(Radius);
	CircleShape::setOrigin(10.f, 10.f);
	CircleShape::setOutlineThickness(3);
	CircleShape::setOutlineColor(sf::Color::Blue);
	CircleShape::setFillColor(sf::Color::White);
	CircleShape::setPosition(400, 300);
	Speed = 400.f;
	BallAngel = 0.3f;
}
