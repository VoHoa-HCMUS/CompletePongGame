#include "Menu.h"
/*Constructor của Menu*/
 Menu::Menu(int Height,int Width)
{
	 /*Khởi tạo và vẽ các lựa chọn*/
	font.loadFromFile("Bubblegum.ttf");
	text[0].setFont(font);
	text[0].setFillColor(sf::Color::Red);
	text[0].setCharacterSize(40);
	text[0].setPosition(Width / 2-90, Height / 2-50);
	text[0].setString("1 Player");
	text[0].setOutlineThickness(3);
	text[0].setOutlineColor(sf::Color::Black);
	text[1].setFont(font);
	text[1].setFillColor(sf::Color::White);
	text[1].setCharacterSize(40);
	text[1].setPosition(Width / 2-90, Height / 2+20);
	text[1].setString("2 Player");
	text[1].setOutlineThickness(3);
	text[1].setOutlineColor(sf::Color::Black);
	text[2].setFont(font);
	text[2].setFillColor(sf::Color::White);
	text[2].setCharacterSize(40);
	text[2].setPosition(Width / 2-50, Height / 2 + 90);
	text[2].setString("Exit");
	text[2].setOutlineThickness(3);
	SelectedOption = 0;/*Gán lựa chọn ban đầu là 0*/
	BackGround.loadFromFile("background.png");
	sprite.setTexture(BackGround);
	sprite.setTextureRect(sf::IntRect(0, 0, Width, Height));
}
 /*Hàm vẽ Menu*/
void Menu::DrawMenu(sf::RenderWindow &Window)
{
	
	Window.draw(sprite);
	for (int i = 0;i < Options; i++)
	{
		Window.draw(text[i]);
	}
}
/*Hàm di chuyển các lựa chọn*/
void Menu::MoveUp()
{
	/*Kiểm tra lựa chọn không vượt quá khi đi lên*/
	if (SelectedOption - 1 >= 0)
	{
		/*Đổi màu chuỗi tại vị trí lựa chọn và vị trí trước đó*/
		text[SelectedOption].setFillColor(sf::Color::White);
		SelectedOption--;
		text[SelectedOption].setFillColor(sf::Color::Red);
	}
}
void Menu::MoveDown()
{
	/*Kiểm tra lựa chọn không vượt quá khi đi xuống*/
	if (SelectedOption +1 < Options)
	{
		text[SelectedOption].setFillColor(sf::Color::White);
		SelectedOption++;
		text[SelectedOption].setFillColor(sf::Color::Red);
	}
}
/*Hàm trả về lựa chọn người chơi*/
int Menu::YourOption()
{
	return SelectedOption;
}
