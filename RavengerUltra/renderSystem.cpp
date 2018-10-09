#include "renderSystem.hpp"

std::unique_ptr<sf::RenderWindow> window;

void initRenderSystem() {

	window = std::unique_ptr<sf::RenderWindow>(new sf::RenderWindow(sf::VideoMode(1024, 768), "SFML works!"));
}


int render(std::list<entity*>* entities) {

	sf::Event event;
	while (window.get()->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.get()->close();
	}

	window.get()->clear();
	for (entity* entity : *entities) 
	{
		if (entity->drawableComponent && entity->modelComponent) 
		{
			sf::Vector2f newPosition = entity->modelComponent.get()->position;
			sf::Vector2f newScale = entity->modelComponent.get()->scale;

			sf::Sprite* sprite = entity->drawableComponent.get()->sprite.get();
			sprite->setPosition(newPosition);
			sprite->setScale(newScale);
			window.get()->draw(*sprite);
		}
		
	}
	window.get()->display();

	return window.get()->isOpen();
}

