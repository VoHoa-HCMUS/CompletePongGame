#include"Menu.h"
#include"Game.h"
int main()
{
	/*Khởi tạo cửa sổ Menu*/
	MenuOp:sf::RenderWindow MenuWindow(sf::VideoMode(Width, Height), "PingPong");
	Menu menu(Height, Width);
	while (MenuWindow.isOpen())
	{
		sf::Event event;
		while (MenuWindow.pollEvent(event))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
			{
				menu.MoveUp();
				break;
			} 
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) 
			{
				menu.MoveDown();
				break;
			} 
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
			{
				switch (menu.YourOption()) 
				{
					case 0: 
					{
						bool CloseMode = false;
						MenuWindow.close();
						BotPlay game;
						game.run(CloseMode);
						/*Kiểm tra nếu người dùng đã đóng mode chơi,
						hiển thị menu để người chơi tiếp tục chọn.*/
						if (CloseMode == true)
							goto MenuOp;
						break;
					}
					case 1: 
					{
						bool CloseMode = false;
						MenuWindow.close();
						Game game;
						game.run(CloseMode);
						if (CloseMode == true)
							goto MenuOp;
						break;
					}
					case 2: 
					{
						MenuWindow.close();
						break;
					}
				}
			}
			if (event.type == sf::Event::Closed) 
			{
				MenuWindow.close();
			}
		}
		/*Hiển thị cửa sổ Menu*/
		MenuWindow.clear();
		menu.DrawMenu(MenuWindow);
		MenuWindow.display();
	}
	return 0;
}