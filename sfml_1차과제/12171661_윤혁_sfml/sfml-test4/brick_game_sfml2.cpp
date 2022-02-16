#include<SFML/Graphics.hpp>
#include<windows.h>
#include<vector>
#include<iostream>
#include<string>

using namespace std;
using namespace sf;
float BALL_SPEED = 5.0;
int score = 0;
string status;
string level;
string timecheck;
class Paddle :public RectangleShape {
	float init_x, init_y;
public:
	Paddle(float x, float y) :init_x(x), init_y(y) {
		setSize({ 80.0,20.0 });
		setPosition(x, y);
		setFillColor(Color(0, 255, 64));
		setOrigin(0, 0);
	}
	void update(int x) {
		setPosition(x, init_y);
	}
};
class Ball :public CircleShape {
public:
	float speedx = BALL_SPEED, speedy = BALL_SPEED;
	Ball(float x, float y) :CircleShape(12.0) {
		setPosition(x, y);
		setFillColor(Color(255, 128, 0));
		setOrigin(0, 0);
	}
	void update() {
		move(speedx, speedy);
		if ((getPosition().x) < 0)
			speedx = BALL_SPEED;
		else if ((getPosition().x + 2 * 20) > 800)
			speedx = -BALL_SPEED;
		if (getPosition().y < 0)
			speedy = BALL_SPEED;
		else if ((getPosition().y + 2 * 20) > 600)
			speedy = -BALL_SPEED;
	}
	bool isIntersecting(Paddle& paddle) {
		return getGlobalBounds().intersects(paddle.getGlobalBounds());
	}
	void handleCollision(Paddle& paddle) {
		if (!isIntersecting(paddle))return;
		speedy = -BALL_SPEED;
		if (getPosition().x < paddle.getPosition().x)
			speedx = -BALL_SPEED;
		else
			speedx = BALL_SPEED;
	}
};

class Brick :public RectangleShape {
public:

	bool deleted = false;
	Brick(float x, float y) {
		setSize({ 60.0,20.0 });
		setPosition(x, y);
		setFillColor(Color::Yellow);
		setOrigin(0, 0);
	
	}
	bool isIntersecting(Ball& ball) {

		return getGlobalBounds().intersects(ball.getGlobalBounds());
	}
	void handleCollision(Ball& ball) {
		if (!isIntersecting(ball)) return;
		deleted = true;
	}
	
};

int main() {
	Ball ball = { 800.0 / 2,600.0 / 2 };
	Paddle paddle = { 800.0 / 2,550.0 };
	
	vector<Brick> bricks;
	for (int x = 0; x < 10; x++)
		for (int y = 0; y < 5; y++)
			bricks.push_back(Brick(x * (60 + 3) + 20, y * (20 + 3) + 40));
	Font font;
	Text text;
	Clock clock;
	
	if (!font.loadFromFile("OpenSans-Bold.ttf")) {
		cout << "폰트 파일을 오픈할 수 없음!" << endl;
	}
	text.setFont(font);

	RenderWindow window(VideoMode(800, 600), "12171661 Yun Hyeok");
	window.setFramerateLimit(60);

	while (window.isOpen()) {
		window.clear(sf::Color::Blue);

		status = "SCORE : " + to_string(score);
		Time elapsed1 = clock.getElapsedTime();
		timecheck = "TIME : "+to_string(elapsed1.asSeconds());
		
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}
		
		Vector2i position = Mouse::getPosition(window);
		paddle.update(position.x);

		ball.update();
		ball.handleCollision(paddle);
		for (auto& brick : bricks) {
			brick.handleCollision(ball);
		}
		int size = bricks.size();
		bricks.erase(remove_if(begin(bricks), end(bricks), [](Brick& b)
			{	
				return b.deleted; 
			}),end(bricks));

		int n = size - bricks.size();
		if (bricks.size() == size - n) {
			score = score + n;
			status = "SCORE : "	+ to_string(score);
		}
	
		if (bricks.size() == 0) {///2단계
			level = "Level 1 success!  This is Level 2";
			BALL_SPEED = 7.5;

			score = 0;
			status = "SCORE : " + to_string(score);

			Ball ball = { 800.0 / 2,600.0 / 2 };
			Paddle paddle = { 800.0 / 2,550.0 };
			paddle.setSize({ 40,20 });

			vector<Brick> bricks;
			for (int x = 0; x < 10; x++)
				for (int y = 0; y < 5; y++)
					bricks.push_back(Brick(x * (60 + 3) + 20, y * (20 + 3) + 40));

			Font font;
			Text text;

			if (!font.loadFromFile("OpenSans-Bold.ttf")) {
				cout << "폰트 파일을 오픈할 수 없음!" << endl;
			}
			text.setFont(font);

			clock.restart();
			while (window.isOpen()) {
				window.clear(sf::Color::Blue);
				
				Time elapsed2 = clock.getElapsedTime();
				timecheck = "TIME : " + to_string(elapsed2.asSeconds());

				Event event;
				while (window.pollEvent(event)) {
					if (event.type == Event::Closed)
						window.close();
				}

				Vector2i position = Mouse::getPosition(window);
				paddle.update(position.x);
				ball.update();
				ball.handleCollision(paddle);
				for (auto& brick : bricks) {
					brick.handleCollision(ball);
				}
				int size = bricks.size();
				bricks.erase(remove_if(begin(bricks), end(bricks), [](Brick& b)
					{
						return b.deleted;
					}), end(bricks));
				int n = size - bricks.size();
				if (bricks.size() == size - n) {
					score = score + n;
					status = "SCORE : " + to_string(score);
				}

				if (bricks.size() == 0) {
					level = "You have cleared Level 1 and 2!  Great!!!@@";
				}

				window.draw(ball);
				window.draw(paddle);

				for (auto& brick : bricks)
					window.draw(brick);

				text.setString(status);
				text.setCharacterSize(20);
				text.setPosition(10, 300);
				window.draw(text);

				text.setString(level);
				text.setCharacterSize(20);
				text.setPosition(10, 360);
				window.draw(text);

				text.setString(timecheck);
				text.setCharacterSize(20);
				text.setPosition(10, 330);
				window.draw(text);

				window.display();
			}

		}

		window.draw(ball);
		window.draw(paddle);

		for (auto& brick : bricks)
			window.draw(brick);

		text.setString(status);
		text.setCharacterSize(20);
		text.setPosition(10, 300);
		window.draw(text);

		text.setString(level);
		text.setCharacterSize(20);
		text.setPosition(10, 360);
		window.draw(text);

		text.setString(timecheck);
		text.setCharacterSize(20);
		text.setPosition(10, 330);
		window.draw(text);

		window.display();
	}
	return 0;
}
