#include "Menu.h"
/*Constructor của Menu*/
 Menu::Menu(int Height,int Width)
{
	 /*Khởi tạo và vẽ các lựa chọn*/
	font.loadFromFile("Bubblegum.ttf");
	text[0].setFont(font);
	text[0].setFillColor(sf::Color::Red);
	text[0].setCharacterSize(40);
	text[0].setPosition(Width / 2-120, Height / 2+30);
	text[0].setString("1 Player");
	text[1].setFont(font);
	text[1].setFillColor(sf::Color::White);
	text[1].setCharacterSize(40);
	text[1].setPosition(Width / 2-120, Height / 2+100);
	text[1].setString("2 Player");
	text[2].setFont(font);
	text[2].setFillColor(sf::Color::White);
	text[2].setCharacterSize(40);
	text[2].setPosition(Width / 2-80, Height / 2 + 170);
	text[2].setString("Exit");
	/*Khởi tạo và vẽ chuỗi trang trí*/
	Mode.setFont(font);
	Mode.setFillColor(sf::Color::Yellow);
	Mode.setCharacterSize(40);
	Mode.setOutlineThickness(3);
	Mode.setOutlineColor(sf::Color::Green);
	Mode.setPosition(Width / 2 - 150, Height / 2 - 70);
	Mode.setString("Choose Mode:");
	Title.setFont(font);
	Title.setFillColor(sf::Color::Yellow);
	Title.setCharacterSize(50); 
	Title.setOutlineThickness(3);
	Title.setOutlineColor(sf::Color::Green);
	Title.setPosition(Width / 2 - 300, Height / 2 - 200);
	Title.setString("Welcome To Pong Game !");
	SelectedOption = 0;/*Gán lựa chọn ban đầu là 0*/
}
 /*Hàm vẽ Menu*/
void Menu::DrawMenu(sf::RenderWindow &Window)
{
	Window.draw(Mode);
	Window.draw(Title);
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
