#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "GameLogicLoop.hpp"
#include "renderSystem.hpp"
#include "components.hpp"
#include "entities.hpp"
#include <memory>
#include <list>








int main()
{
	entity entity0;
	entity0.id = 0;

	entity entity1;
	entity1.id = 1;

	entity entity2;
	entity2.id = 2;

	entity entity3;
	entity3.id = 3;

	sf::Texture texture0;
	if (texture0.loadFromFile("giraldo.png", sf::IntRect(0, 0, 1200, 675)))
	{
		entity0.modelComponent = std::make_unique<modelComponent>();
		entity0.modelComponent.get()->position = sf::Vector2f(30.0f,20.0f);
		entity0.modelComponent.get()->scale = sf::Vector2f(0.4f, 0.4f);

		entity0.drawableComponent = std::make_unique<drawableComponent>();
		entity0.drawableComponent.get()->sprite = std::unique_ptr<sf::Sprite>(new sf::Sprite(texture0));

		entity0.drawableComponent.get()->sprite->setScale(0.1f, 0.1f);
		entity0.drawableComponent.get()->sprite->setPosition(20.0f, 20.0f);

		entity1.modelComponent = std::make_unique<modelComponent>();
		entity1.modelComponent.get()->position = sf::Vector2f(980.0f, 20.0f);
		entity1.modelComponent.get()->scale = sf::Vector2f(-0.4f, 0.4f);

		entity1.drawableComponent = std::make_unique<drawableComponent>();
		entity1.drawableComponent.get()->sprite = std::unique_ptr<sf::Sprite>(new sf::Sprite(texture0));

		entity1.drawableComponent.get()->sprite->setScale(0.1f, 0.1f);
		entity1.drawableComponent.get()->sprite->setPosition(20.0f, 20.0f);

		entity2.modelComponent = std::make_unique<modelComponent>();
		entity2.modelComponent.get()->position = sf::Vector2f(30.0f, 550.0f);
		entity2.modelComponent.get()->scale = sf::Vector2f(0.4f, -0.4f);

		entity2.drawableComponent = std::make_unique<drawableComponent>();
		entity2.drawableComponent.get()->sprite = std::unique_ptr<sf::Sprite>(new sf::Sprite(texture0));

		entity2.drawableComponent.get()->sprite->setScale(0.1f, 0.1f);
		entity2.drawableComponent.get()->sprite->setPosition(20.0f, 20.0f);

		entity3.modelComponent = std::make_unique<modelComponent>();
		entity3.modelComponent.get()->position = sf::Vector2f(980.0f, 550.0f);
		entity3.modelComponent.get()->scale = sf::Vector2f(-0.4f, -0.4f);

		entity3.drawableComponent = std::make_unique<drawableComponent>();
		entity3.drawableComponent.get()->sprite = std::unique_ptr<sf::Sprite>(new sf::Sprite(texture0));

		entity3.drawableComponent.get()->sprite->setScale(0.1f, 0.1f);
		entity3.drawableComponent.get()->sprite->setPosition(20.0f, 20.0f);
	}

	std::list<entity*> entities;
	entities.push_back(&entity0);
	entities.push_back(&entity1);
	entities.push_back(&entity2);
	entities.push_back(&entity3);

	initRenderSystem();

	bool windowOpen = false;
	do
	{
		windowOpen = render(&entities);

	} while (windowOpen);

	return 0;
}


