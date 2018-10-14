#include "renderSystem.hpp"


void render(sf::RenderWindow* window, std::list<Entity*>* entities) {

	window->clear();
	for (Entity* entity : *entities)
	{
		if (entity->systemsKey.RenderSystem)
		{
			sf::Vector2f newPosition = entity->modelComponent.get()->position;
			sf::Vector2f newScale = entity->modelComponent.get()->scale;
			sf::Vector2f newOrigin = entity->modelComponent.get()->origin;

			sf::Sprite* sprite = entity->drawableComponent.get()->sprite.get();

			//sprite->
			sprite->setPosition(newPosition);
			sprite->setScale(newScale);
			sprite->setOrigin(newOrigin);
			window->draw(*sprite);
		}

	}
	window->display();
}

