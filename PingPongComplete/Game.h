#include"BotPlay.h"
using namespace std;
class Game
{
private:
	void processEvents(bool& CloseMode);
	void update(sf::Time deltatime);
	void render();
private:
	Ball ball;
	Paddle PaddleLeft;
	Paddle PaddleRight;
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
	sf::Text Player1Point;
	sf::Text Player2Point;
	sf::Time Fps;
	sf::Texture BackGround;
	sf::Sprite sprite;
	int iPlayer1Point;
	int iPlayer2Point;
public:
	Game();
	void CreateOutline();
	void CreateText();
	void CreatePaddle();
	void CreateBard();
	void DrawBard();
	void DrawOutline();
	void DrawText();
	void DrawPaddle();
	void MoveBall(sf::Time deltatime);
	void MovePaddle(sf::Time deltatime);
	bool TouchPaddleLeft();
	bool TouchPaddleRight();
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


