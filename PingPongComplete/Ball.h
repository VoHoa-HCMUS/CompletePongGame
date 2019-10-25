#include <SFML/Graphics.hpp>
using namespace std;
class Ball : public sf::CircleShape
{
private:
	float Radius;
	float BallAngel;
	float Speed;
public:
	float GetAngle();
	float GetSpeed();
	void SetAngle(float);
	void SetSpeed(float);
	Ball();
};

