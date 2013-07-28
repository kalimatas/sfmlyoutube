#include <iostream>
#include <SFML/Graphics.hpp>

/* Set event */
bool setEvent(sf::RenderWindow&, sf::Event&);

int main(int argc, char** argv) {
	// Player dimensions
/*
	const unsigned short PLAYER_WIDTH = 32;
	const unsigned short PLAYER_HEIGHT = 32;

	float frameCounter = 0, switchFrame = 100, frameSpeed = 500;
	bool updateFrame = true;
*/

	sf::RenderWindow window(sf::VideoMode(400, 342), "Title from function!");
	window.setKeyRepeatEnabled(false);

	sf::Texture texture;
	sf::Sprite player;
	sf::Clock clock;

/*
	enum direction {Down, Left, Right, Up};
	sf::Vector2i source(0, Down);

	texture.loadFromFile("Resources/image.png");
	player.setTexture(texture);
*/

	sf::RectangleShape rect(sf::Vector2f(100, 100));

	while (window.isOpen()) {
		sf::Event event;
		while (setEvent(window, event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}

		/*
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			source.y = Right;
			player.move(0.1, 0);
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			source.y = Left;
			player.move(-0.1, 0);
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			source.y = Up;
			player.move(0, -0.1);
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			source.y = Down;
			player.move(0, 0.1);
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			updateFrame = true;
		} else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
			updateFrame = false;
		}

		frameCounter = updateFrame == true
				? frameCounter + frameSpeed * clock.restart().asSeconds()
				: 0;

		if (frameCounter >= switchFrame) {
			frameCounter = 0;
			if (++source.x > 2) {
				source.x = 0;
			}
		}

		player.setTextureRect(sf::IntRect(source.x * PLAYER_WIDTH, source.y * PLAYER_HEIGHT, PLAYER_WIDTH, PLAYER_HEIGHT));
		*/

		window.draw(rect);
		window.display();
		window.clear(sf::Color(66, 66, 66));
	}

	return EXIT_SUCCESS;
}

bool setEvent(sf::RenderWindow& window, sf::Event& event) {
	return window.pollEvent(event);
}
