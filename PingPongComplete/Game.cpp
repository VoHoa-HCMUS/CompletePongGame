#include "Game.h"
/*Hàm tạo Paddlde trái và phải*/
void Game::CreatePaddle()
{
	/*Tạo màu*/
	PaddleLeft.setFillColor(sf::Color::Red);
	PaddleRight.setFillColor(sf::Color::Blue);
	/*Cập nhật vị trí Paddle trên màn hình chơi*/
	PaddleLeft.setPosition(30, 225);
	PaddleRight.setPosition(Width - 50, 225);
}
/*Hàm tạo các chuỗi in ra màn hình*/
void Game::CreateText()
{
	/*Load font chữ từ project*/
	font.loadFromFile("Bubblegum.ttf");
	/*Tạo font chữ*/
	text.setFont(font);
	text.setFillColor(sf::Color::Yellow);
	/*Tạo kích thươc chữ*/
	text.setCharacterSize(30);
	text.setPosition(320, 400);
	text.setOutlineThickness(3);
	text.setOutlineColor(sf::Color::Black);
	Player1Point.setFont(font);
	Player1Point.setPosition(400, 30);
	Player1Point.setFillColor(sf::Color::Yellow);
	Player1Point.setString("0");
	Player1Point.setOutlineThickness(3);
	Player1Point.setOutlineColor(sf::Color::Black);
	Player2Point.setFont(font);
	Player2Point.setPosition(580, 30);
	Player2Point.setFillColor(sf::Color::Yellow);
	Player2Point.setString("0");
	Player2Point.setOutlineThickness(3);
	Player2Point.setOutlineColor(sf::Color::Black);
	Exit.setFont(font);
	Exit.setFillColor(sf::Color::Yellow);
	Exit.setCharacterSize(30);
	Exit.setPosition(390, 440);
	Exit.setOutlineThickness(3);
	Exit.setOutlineColor(sf::Color::Black);
	Winner.setFont(font);
	Winner.setFillColor(sf::Color::Yellow);
	Winner.setCharacterSize(40);
	Winner.setPosition(400, 300);
	Winner.setOutlineThickness(3);
	Winner.setOutlineColor(sf::Color::Black);
	BackGround.loadFromFile("backgroundgameplay.jpg");
	sprite.setTexture(BackGround);
	sprite.setTextureRect(sf::IntRect(0, 0, Width, Height));
}
/*Hàm tạo đường viền cho màn hình chơi*/
void Game::CreateOutline()
{
	Outline1.setSize(sf::Vector2f(10, Height));
	Outline1.setOutlineThickness(3);
	Outline1.setOutlineColor(sf::Color::Black);
	Outline1.setFillColor(sf::Color::Cyan);
	Outline2.setSize(sf::Vector2f(Width, 10));
	Outline2.setFillColor(sf::Color::Cyan);
	Outline2.setOutlineThickness(3);
	Outline2.setOutlineColor(sf::Color::Black);
	Outline3.setPosition(sf::Vector2f(Width - 10, 0));
	Outline3.setSize(sf::Vector2f(10, Height));
	Outline3.setFillColor(sf::Color::Cyan);
	Outline3.setOutlineThickness(3);
	Outline3.setOutlineColor(sf::Color::Black);
	Outline4.setPosition(sf::Vector2f(0, Height - 10));
	Outline4.setSize(sf::Vector2f(Width, 10));
	Outline4.setFillColor(sf::Color::Cyan);
	Outline4.setOutlineThickness(3);
	Outline4.setOutlineColor(sf::Color::Black);
	middle.setSize(sf::Vector2f(5, Height));
	middle.setFillColor(sf::Color::White);
	middle.setPosition(sf::Vector2f(Width / 2, 0));
	middle.setOutlineThickness(3);
	middle.setOutlineColor(sf::Color::Black);
}
/*Hàm tạo tường gai trên màn hình chơi*/
void Game::CreateBard()
{
	int pos = 10;
	for (int i = 0; i <= 30; i++)
	{
		Bard[i].setPointCount(4);
		Bard[i].setRadius(10);
		Bard[i].setPosition(sf::Vector2f(0, pos));
		Bard[i].setFillColor(sf::Color::Cyan);
		Bard[i].setOutlineThickness(3);
		Bard[i].setOutlineColor(sf::Color::Black);
		pos += 20;
	}
	pos = 10;
	for (int i = 31; i < 60; i++)
	{
		Bard[i].setPointCount(4);
		Bard[i].setRadius(10);
		Bard[i].setPosition(sf::Vector2f(Width - 20, pos));
		Bard[i].setFillColor(sf::Color::Cyan);
		Bard[i].setOutlineThickness(3);
		Bard[i].setOutlineColor(sf::Color::Black);
		pos += 20;
	}
}
/*Hàm ve tường gai*/
void Game::DrawBard()
{
	for (int i = 0; i <= 30; i++)
	{
		Window.draw(Bard[i]);
	}
	for (int i = 31; i < 60; i++)
	{
		Window.draw(Bard[i]);
	}
}
/*Hàm vẽ đường bao màn hình*/
void Game::DrawOutline()
{
	Window.draw(middle);
	Window.draw(Outline1);
	Window.draw(Outline2);
	Window.draw(Outline3);
	Window.draw(Outline4);
}
/*Hàm vẽ các chuỗi trên màn hình*/
void Game::DrawText()
{
	Window.draw(Player1Point);
	Window.draw(Player2Point);
	Window.draw(text);
	Window.draw(Exit);
	Window.draw(Winner);
}
/*Hàm vẽ Paddle*/
void Game::DrawPaddle()
{
	Window.draw(PaddleLeft);
	Window.draw(PaddleRight);
}
/*Constructor của Class game*/
Game::Game()
{ 
	/*Tạo các vật thể và chuỗi*/
	CreateText();
	CreateBard();
	CreateOutline();
	CreatePaddle();
	/*Khởi tạo FPS cho trò chơi*/
	Fps = sf::seconds(1.f / 160.f);
	/*Khởi tạo cửa sổ chơi*/
	Window.create(sf::VideoMode(Width, Height), "PingPong");
}

void Game::StrikeAngle(int pc, Paddle p, Ball &ball) {
	float layer1 = 25; float layer2 = 50;
	float ballY = ball.getPosition().y + ball.getRadius();
	float mid = p.getPosition().y + p.getSize().y / 2;
	float convCurAngle = ball.GetAngle() * 180 / pi;

	srand(time(NULL));
	int x = rand() % 15 + 0;
	float strike1 = (19 + x) * pi / 180; float strike2 = (40 + x) * pi / 180; float strike3 = (57 + x) * pi / 180;

	if (pc == 1) { //di chuyen sang trai
		if (mid - layer1 <= ballY && ballY <= mid) ball.SetAngle(-strike1);
		else if (mid <= ballY && ballY < mid + layer1) ball.SetAngle(strike1);

		else if (mid - layer1 - layer2 <= ballY && ballY <= mid - layer1) ball.SetAngle(-strike2);
		else if (mid + layer1 < ballY && ballY <= mid + layer1 + layer2) ball.SetAngle(strike2);

		else if (mid - layer1 - 2 * layer2 <= ballY && ballY <= mid - layer1 - layer2) ball.SetAngle(-strike3);
		else if (mid + layer1 + layer2 < ballY && ballY <= mid + layer1 + 2 * layer2) ball.SetAngle(strike3);
	} else if (pc == 2) { //di chuyen sang phai
		if (mid - layer1 <= ballY && ballY <= mid) ball.SetAngle(pi + strike1);
		else if (mid <= ballY && ballY < mid + layer1) ball.SetAngle(pi - strike1);

		else if (mid - layer1 - layer2 <= ballY && ballY <= mid - layer1) ball.SetAngle(pi + strike2);
		else if (mid + layer1 < ballY && ballY <= mid + layer1 + layer2) ball.SetAngle(pi - strike2);

		else if (mid - layer1 - 2 * layer2 <= ballY && ballY <= mid - layer1 - layer2) ball.SetAngle(pi + strike3);
		else if (mid + layer1 + layer2 < ballY && ballY <= mid + layer1 + 2 * layer2) ball.SetAngle(pi - strike3);
	}
}

/*Hàm di chuyển trái banh*/
void Game::MoveBall(sf::Time deltatime)
{
	/*Khởi tạo số pixel đi được mỗi giây của trái banh*/
	float factor = ball.GetSpeed() * deltatime.asSeconds();
	/*Di chuyển trái banh theo hướng cuar2 vector tạo bởi góc trái banh so với trục tọa độ*/
	ball.move(sf::Vector2f(cos(ball.GetAngle()) * factor, sin(ball.GetAngle()) * factor));
	cout << ball.GetAngle() << endl;
	/*Kiểm tra banh chạm Paddle bên trái*/
	if (TouchPaddleLeft() == 1)
	{
		/*Nếu tốc độ trái banh chưa vượt quá 800 tăng tốc độ trái banh lên 10%*/
		if (ball.GetSpeed() < 800.f)
			ball.SetSpeed(ball.GetSpeed() * 1.1);
		/*Thay đổi góc trái banh so với trục tọa độ*/
		StrikeAngle(1, PaddleLeft, ball);
	} else if (TouchPaddleLeft() == 2) {
		ball.SetAngle(-ball.GetAngle());
	}
	/*Kiểm tra banh chạm Paddle bên phải*/
	if (TouchPaddleRight() == 1)
	{
		if (ball.GetSpeed() < 800.f)
			ball.SetSpeed(ball.GetSpeed() * 1.1);
		StrikeAngle(2, PaddleRight, ball);
	} else if (TouchPaddleRight() == 2) {
		ball.SetAngle(-ball.GetAngle());
	}
	/*Kiểm tra banh chạm tường trên và dưới*/
	if (TouchWall())
	{
		ball.SetAngle(-ball.GetAngle());
	}
}
/*Hàm di chuyển Paddle*/
void Game::MovePaddle(sf::Time deltatime)
{
	/*Nếu Paddle đang đi lên di chuyển Paddle theo hướng vector(0,400.f)*/
	if (PaddleLeft.MoveUp() && PaddleLeft.getPosition().y > 20)
	{
		PaddleLeft.move(0.f, -PaddleLeft.GetSpeed() * deltatime.asSeconds());
	}
	/*Nếu Paddle đang đi xuống di chuyển Paddle theo hướng vector(0,-400.f)*/
	if (PaddleLeft.MoveDown() && PaddleLeft.getPosition().y < 430)
	{
		PaddleLeft.move(0.f, PaddleLeft.GetSpeed() * deltatime.asSeconds());
	}
	if (PaddleRight.MoveUp() && PaddleRight.getPosition().y > 20)
	{
		PaddleRight.move(0.f, -PaddleRight.GetSpeed() * deltatime.asSeconds());
	}
	if (PaddleRight.MoveDown() && PaddleRight.getPosition().y < 430)
	{
		PaddleRight.move(0.f, PaddleRight.GetSpeed() * deltatime.asSeconds());
	}
}
/*Hàm kiểm tra banh chạm Paddle trái*/
int Game::TouchPaddleLeft()
{
	float xPaddleLeft = PaddleLeft.getPosition().x;
	float yball = ball.getPosition().y;
	float xball = ball.getPosition().x;
	float yPaddleLeft = PaddleLeft.getPosition().y;
	float PaddleLong = PaddleLeft.getSize().y;
	/*Nếu tọa độ x của trái banh bé hơn hoành độ của Paddle + 30 
	và tung độ của trái banh nằm trong khoảng tung độ của Paddle return true*/
	if (xball <= xPaddleLeft + 30 && yball + ball.getRadius() + 20 >= yPaddleLeft && yball <= yPaddleLeft + PaddleLong)
		return 1;
	if ((xball >= xPaddleLeft && xball <= xPaddleLeft + 30 && yball + ball.getRadius() * 2 >= yPaddleLeft && yball < yPaddleLeft + 20)
		|| (xball >= xPaddleLeft && xball <= xPaddleLeft + 30 && yball <= yPaddleLeft + PaddleLong + 10 && yball > yPaddleLeft + PaddleLong - 20))
		return 2;
}
/*Hàm kiểm tra banh chạm Paddle trái*/
int Game::TouchPaddleRight()
{
	float xPaddleRight = PaddleRight.getPosition().x;
	float yball = ball.getPosition().y;
	float xball = ball.getPosition().x;
	float yPaddleRight = PaddleRight.getPosition().y;
	float PaddleLong = PaddleRight.getSize().y;
	/*Nếu hoành độ của trái banh lớn hơn tọa độ x của Paddle - 10 và 
	tung độ của trái banh nằm trong khoảng tung độ của Paddle return true*/
	if (xball >= xPaddleRight - 10 && yball + ball.getRadius() >= yPaddleRight && yball <= yPaddleRight + PaddleLong) {
		return 1;
	} 
	if ((xball >= xPaddleRight - 10 && xball <= xPaddleRight + 20 && yball + ball.getRadius() * 2 >= yPaddleRight && yball < yPaddleRight + 20)
		|| (xball >= xPaddleRight - 10 && xball <= xPaddleRight + 20 && yball <= yPaddleRight + PaddleLong + 10 && yball > yPaddleRight + PaddleLong - 20))
		return 2;
}
/*Hàm kiểm tra trái banh chạm tường gai*/
void Game::TouchBard()
{
	/*Nếu trái bay chạm tường gai trái tăng điểm player2*/
	if (ball.getPosition().x < 20 )
	{
		iPlayer2Point++;
		/*Hiển thị điểm lên màn hình*/
		DisplayScore();
		/*Restart lại game*/
		RestartGame(Fps);
	}
	/*Nếu trái bay chạm tường gai phải tăng điểm player1*/
	if (ball.getPosition().x + ball.getRadius() > 980)
	{
		iPlayer1Point++;
		DisplayScore();
		RestartGame(Fps);
	}
}
/*Hàm kiểm trai trái banh chạm tường trên và dưới*/
bool Game::TouchWall()
{
	int yBall = ball.getPosition().y;
	int Radius = ball.getRadius();
	/*Nếu tung độ của trái banh cộng với bán kính của nó lớn hơn tung độ màn hình chơi-10 
	hoặc tung độ của trái banh trừ với bán kính của nó nhỏ hơn 10 return true*/
	return(yBall + Radius > Height - 10 || yBall - Radius < 10);
}
/*Hàm xử lý phím nhập của người dùng*/
void Game::PressedKey(sf::Keyboard::Key key, bool Pressed,bool &CloseMode)
{
	/*Nếu nhấn W thì Paddle trái đi lên*/
	if (key == sf::Keyboard::W)
		PaddleLeft.SetUp(Pressed);
	/*Nếu nhấn W thì Paddle trái đi xuống*/
	if (key == sf::Keyboard::S)
		PaddleLeft.SetDown(Pressed);
	if (key == sf::Keyboard::Up)
		PaddleRight.SetUp(Pressed);
	if (key == sf::Keyboard::Down)
		PaddleRight.SetDown(Pressed);
	/*Nếu nhấn Space khởi tạo lại màn hình chơi và restart game*/
	if (key == sf::Keyboard::Space&&LoseTheGame())
	{
		CleanScreen();
		RestartGame(Fps);
	}
	/*Nếu nhấn phim Esc thoát màn hình chơi*/
	if (key == sf::Keyboard::Escape)
	{
		CloseMode = true;
		Window.close();
	}
}
/*Hàm hiển thị điểm người chơi*/
void Game::DisplayScore()
{
	string p1;
	string p2;
	/*Chuyển điểm của người chơi 1 và 2 thành chuỗi rồi in ra màn hình*/
	p1 = to_string(iPlayer1Point);
	p2 = to_string(iPlayer2Point);
	Player1Point.setString(p1);
	Player2Point.setString(p2);
}
/*Hàm kiểm tra thắng thua*/
bool Game::LoseTheGame()
{
	/*Nếu có 1 người chơi đạt 10 điểm return true*/
	if (iPlayer1Point == 10 || iPlayer2Point == 10)
		return true;
	else
		return false;
}
/*Hàm hiển thị người chơi dành chiến thắng*/
void Game::WinnerDisplay()
{
	text.setString("Press Space to play again");
	Exit.setString("Esc to exit mode");
	/*Hiển thị người chơi chiến thắng*/
	if (iPlayer1Point == 10)
	{
		/*Đưa trá banh ra ngoài màn hình*/
		ball.setPosition(0, 10);
		Winner.setString("Player1 Win");
	}
	else
	{
		ball.setPosition(1000, 10);
		Winner.setString("Player2 Win");
	}
}
/*Hàm khởi tạo lại màn hình chơi*/
void Game::CleanScreen()
{
	/*Khởi tạo lại điểm của 2 người chơi bằng không*/
	iPlayer1Point = 0;
	iPlayer2Point = 0;
	string p1;
	string p2;
	/*Hiển thị điểm*/
	p1 = to_string(iPlayer1Point);
	p2 = to_string(iPlayer2Point);
	Player1Point.setString(p1);
	Player2Point.setString(p2);
	/*Ẩn chuỗi khác*/
	Winner.setString("");
	text.setString("");
	Exit.setString("");
}
/*Hàm khởi tạo lại trò chơi*/
void Game::RestartGame(sf::Time deltatime)
{
	/*Khởi tạo góc của trái banh so với gốc tọa độ*/
	float BallAngle = 0.f;
	srand(time(NULL));
	/*Random ngẫu nhiên góc trái banh so với gốc tọa độ*/
	BallAngle = (float) (rand() % 1200 * 2) / (float) (1200);
	/*Khởi tạo tốc độ trái banh như cũ*/
	float OldSpeed = 400.f;
	/*Random ngẫu nhiên góc trái banh so với gốc tọa độ*/
	/*Set lại tốc độ ban đầu của trái banh*/
	ball.SetSpeed(OldSpeed);
	/*Đặt lại trái banh về vị trí ban đầu*/
	ball.setPosition(Width / 2, Height / 2);
	/*Đặt lại Paddle về vị trí ban đầu*/
	PaddleLeft.setPosition(30, 225);
	PaddleRight.setPosition(Width - 50, 225);
	/*Khởi tạo số pixel đi được mỗi giây của trái banh*/
	float factor = ball.GetSpeed() * deltatime.asSeconds();
	/*Cho trái banh bay*/
	ball.move(sf::Vector2f(cos(ball.GetAngle()) * factor, sin(ball.GetAngle()) * factor));

}
/*Hàm xử lý phím nhập và thả*/
void Game::processEvents(bool& CloseMode)
{
	sf::Event event;
	while (Window.pollEvent(event)) {
		switch (event.type)
		{
		case sf::Event::Closed:
			Window.close();
			break;
			/*Trường hợp người dùng nhập truyền vào hàm xử lý nhập của người dùng*/
		case sf::Event::KeyPressed:
			PressedKey(event.key.code, true, CloseMode);
			break;
		case sf::Event::KeyReleased:
			/*Trường hợp người dùng thả phím truyền vào hàm xử lý nhập của người dùng*/
			PressedKey(event.key.code, false, CloseMode);
			break;
		}
	}
}
/*Hàm xử lý game*/
void Game::update(sf::Time deltatime)
{
	/*Nếu chưa có ai thua tiếp tục gọi hàm di chuyển trái banh và Paddle*/
	if (LoseTheGame() == false)
	{
		MoveBall(deltatime);
		MovePaddle(deltatime);
		TouchBard();
	}
	/*Ngược lại hiển thị người thắng*/
	else
	{
		WinnerDisplay();
	}
}
/*Hàm vẽ màn hình chơi*/
void Game::render()
{
	Window.clear();
	Window.draw(sprite);
	Window.draw(ball);
	DrawPaddle();
	DrawBard();
	DrawOutline();
	DrawText();
	Window.display();
}
/*Hàm chạy game*/
void Game::run(bool& CloseMode)
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	/*Trong khi cửa sổ chơi còn mở gọi hàm xử lý nhập và thả phím của người dùng, hàm xử lý game, hàm vẽ màn hình chơi*/
	while (Window.isOpen()) {
		processEvents(CloseMode);
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > Fps) {
			timeSinceLastUpdate -= Fps;
			processEvents(CloseMode);
			update(Fps);
		}
		render();
	}
}
