#include"Ball.h"
#include"Paddle.h"
#include<iostream>
const float pi = 3.14159265359f;
const int Height = 600, Width = 1000;
using namespace std;
class BotPlay
{
private:
	void processEvents(bool& CloseMode);
	void update(sf::Time deltatime);
	void render();
private:
	Ball ball;
	Paddle YourPaddle;
	Paddle BotPaddle;
	sf::RenderWindow Window;
	sf::RectangleShape Outline1;
	sf::RectangleShape Outline2;
	sf::RectangleShape Outline3;
	sf::RectangleShape Outline4;
	sf::RectangleShape middle;
	sf::CircleShape Bard[60];
	sf::Font font;
	sf::Text text;
	sf::Text Exit;
	sf::Text Winner;
	sf::Text YourPoint;
	sf::Text BotPoint;
	sf::Time Fps;
	sf::Texture BackGround;
	sf::Sprite sprite;
	int iYourPoint;
	int iBotPoint;
public:
	BotPlay();
	void CreateOutline();
	void CreateText();
	void CreatePaddle();
	void CreateBard();
	void DrawBard();
	void DrawOutline();
	void DrawText();
	void DrawPaddle();
	void StrikeAngle(int pc, Paddle p, Ball& ball);
	void MoveBall(sf::Time deltatime);
	void SkyNet(sf::Time deltatime);
	void MovePaddle(sf::Time deltatime);
	bool TouchYourPaddle();
	bool TouchBotPaddle();
	bool TouchWall();
	void TouchBard();
	void PressedKey(sf::Keyboard::Key key, bool Pressed, bool& CloseMode);
	void DisplayScore();
	bool LoseTheGame();
	void WinnerDisplay();
	void CleanScreen();
	void RestartGame(sf::Time deltatime);
	void run(bool& CloseMode);
};

