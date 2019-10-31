#include "SFML-2.5.1/include/SFML/Graphics.hpp"


int main()
{
	sf::RenderWindow window(sf::VideoMode(1240, 720), "Bouncy Mushroom");

	sf::Texture mushroomTexture;
	mushroomTexture.loadFromFile("Assets/Textures/Mushroom.png");
	sf::Sprite mushroomSprite(mushroomTexture);
	sf::Vector2u mushroomSize = mushroomTexture.getSize();
	mushroomSprite.setOrigin(mushroomSize.x / 2, mushroomSize.y / 2);
	sf::Vector2f increment(0.05f, 0.05f);
	mushroomSprite.setColor(sf::Color::Blue);

	// Initialise Game Objects
	////Rect
	//sf::RectangleShape rect(sf::Vector2f(500.0f,300.0f));
	//rect.setFillColor(sf::Color::White);
	//rect.setPosition(windowSize.x / 2, windowSize.y / 2);
	//rect.setOrigin(sf::Vector2f(rect.getSize().x / 2, rect.getSize().y / 2));

	////Circle
	//sf::CircleShape circle(100);
	//circle.setFillColor(sf::Color::Red);
	//circle.setPosition(windowSize.x / 2, windowSize.y / 2);
	//circle.setOrigin(sf::Vector2f(circle.getRadius(), circle.getRadius()));

	////Triangle
	//sf::ConvexShape triangle;
	//triangle.setPointCount(3);
	//triangle.setPoint(0, sf::Vector2f(-200, 0));
	//triangle.setPoint(1, sf::Vector2f(0, -200));
	//triangle.setPoint(2, sf::Vector2f(200, 0));
	//triangle.setFillColor(sf::Color::Yellow);
	//triangle.setPosition(windowSize.x / 2, windowSize.y / 2);

	while (window.isOpen())
	{
		//Handle Keyboard-Events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

		}

		//Update

		if ((mushroomSprite.getPosition().x + (mushroomSize.x / 2) > window.getSize().x && increment.x > 0) || (mushroomSprite.getPosition().x - (mushroomSize.x / 2) < 0 && increment.x < 0))
		{
			//reverse direction on x axis
			increment.x = -increment.x;
			mushroomSprite.setColor(sf::Color::Blue);
		}

		if ((mushroomSprite.getPosition().y + (mushroomSize.y / 2) > window.getSize().y && increment.y > 0) || (mushroomSprite.getPosition().y - (mushroomSize.y / 2) < 0 && increment.y < 0))
		{
			//reverse direction on y axis
			increment.y = -increment.y;
			mushroomSprite.setColor(sf::Color::Green);
		}

		mushroomSprite.setPosition(mushroomSprite.getPosition() + increment);

		window.clear(sf::Color::Black);
		//Render
		window.draw(mushroomSprite);
		//window.draw(rect);
		//window.draw(circle);
		//window.draw(triangle);
		window.display();

	}


	return 0;
}