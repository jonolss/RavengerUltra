#include <SFML/Graphics.hpp>
#include "GameLogicLoop.hpp"
#include "GraphicLoop.hpp"
#include <memory>

#include <SFML/Graphics/Sprite.hpp>

struct ModelComponent {
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Vector2f scale;
	float rotation;
};

struct DrawableComponent {
	std::unique_ptr<sf::Sprite> sprite;

};

struct Entity {

	unsigned long id;
	unsigned long componentsKey;

	std::unique_ptr<ModelComponent> modelComponent;
	std::unique_ptr<DrawableComponent> drawableComponent;

};



int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

	Entity entity0;
	entity0.id = 0;

	sf::Texture texture0;
	if (texture0.loadFromFile("giraldo.png", sf::IntRect(0, 0, 1200, 675)))
	{
		entity0.modelComponent = std::make_unique<ModelComponent>();
		entity0.drawableComponent = std::make_unique<DrawableComponent>();
		entity0.drawableComponent.get()->sprite = std::unique_ptr<sf::Sprite>(new sf::Sprite(texture0));

		entity0.drawableComponent.get()->sprite->setScale(0.1f, 0.1f);
		entity0.drawableComponent.get()->sprite->setPosition(20.0f, 20.0f);
	}
	

	while (window.isOpen())
	{
		//graphicLoop(&window);

		sf::CircleShape shape(100.f);
		shape.setFillColor(sf::Color::Green);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.draw(*entity0.drawableComponent.get()->sprite.get());
		window.display();
	}

	return 0;
}


