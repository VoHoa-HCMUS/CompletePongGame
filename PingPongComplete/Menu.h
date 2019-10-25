#define Options 3
#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;
class Menu
{
private:
	int SelectedOption;
	sf::Font font;
	sf::Text text[Options];
	sf::Text Mode;
	sf::Text Title;
public:
	void DrawMenu(sf::RenderWindow& Window);
	void MoveUp();
	void MoveDown();
	int YourOption();
	Menu(int Height, int Width);

};

