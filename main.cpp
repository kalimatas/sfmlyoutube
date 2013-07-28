#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>

int main(int argc, char** argv) {
	sf::Vector2i screenDimensions(600, 442);

	sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "SFML tutorial");

	sf::Texture texture;
	sf::Sprite image;

	if (!texture.loadFromFile("Resources/texture.jpg")) {
		std::cout << "cannot load texture" << std::endl;
	}

	image.setTexture(texture);
	image.setScale(1.0f, (float)screenDimensions.y / texture.getSize().y);

	sf::RectangleShape rect(sf::Vector2f(20, 20));
	rect.setFillColor(sf::Color::Green);

	sf::Clock clock;
	float moveSpeed = 10000.0f;

	sf::View view;
	view.reset(sf::FloatRect(0, 0, screenDimensions.x, screenDimensions.y));
	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f)); // display full view

	sf::Vector2f position(screenDimensions.x / 2, screenDimensions.y / 2);

	while (window.isOpen()) {
		clock.restart();

		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;

			default:
				break;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			rect.move(moveSpeed * clock.restart().asSeconds(), 0);
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			rect.move(-moveSpeed * clock.restart().asSeconds(), 0);
		}

		/*
		position.x = rect.getPosition().x + 10 - (screenDimensions.x / 2);
		position.y = rect.getPosition().y + 10 - (screenDimensions.y / 2);

		if (position.x < 0)
			position.x = 0;
		if (position.y < 0)
			position.y = 0;
		*/

		if (rect.getPosition().x + 10 > screenDimensions.x / 2)
			position.x = rect.getPosition().x + 10;
		else
			position.x = screenDimensions.x / 2;

		//view.reset(sf::FloatRect(position.x, position.y, screenDimensions.x, screenDimensions.y));
		view.setCenter(position);

		window.setView(view);
		window.draw(image);
		window.draw(rect);
		window.display();
		window.clear(sf::Color(66, 66, 66));
	}

	return EXIT_SUCCESS;
}
