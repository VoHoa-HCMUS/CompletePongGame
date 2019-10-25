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
			switch (event.type)
			{
			case sf::Event::KeyReleased:
			{
				/*Di chuyển các lựa chọn*/
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;
				case sf::Keyboard::Down:
					menu.MoveDown();
					break;
					/*Trường hợp người dùng chọn 1 trong 3 lựa chọn*/
				case sf::Keyboard::Enter:
				{
					/*Các trường hợp chọn*/
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
					break;
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
						MenuWindow.close();
					}
				}
				break;
				}

			}
			break;
			case sf::Event::Closed:
				MenuWindow.close();
				break;
			}
		}
		/*Hiển thị cửa sổ Menu*/
		MenuWindow.clear();
		menu.DrawMenu(MenuWindow);
		MenuWindow.display();
	}
	return 0;
}