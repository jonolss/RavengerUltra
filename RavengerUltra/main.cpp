#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "GameLogicLoop.hpp"
#include "movementSystem.hpp"
#include "renderSystem.hpp"
#include "eventReader.hpp"
#include "components.hpp"
#include "entities.hpp"

#include <memory>
#include <list>
#include <iostream>



int main()
{
  std::unique_ptr<sf::RenderWindow> window = std::unique_ptr<sf::RenderWindow>(new sf::RenderWindow(sf::VideoMode(1024, 768), "SFML works!"));

	Entity entity0;
	entity0.id = 0;

	Entity entity1;
	entity1.id = 1;

	Entity entity2;
	entity2.id = 2;

	Entity entity3;
	entity3.id = 3;

	sf::Texture texture0;
	if (texture0.loadFromFile("giraldo.png", sf::IntRect(0, 0, 1200, 675)))
	{
		entity0.modelComponent = std::make_unique<ModelComponent>();
		entity0.modelComponent.get()->position = sf::Vector2f(30.0f,20.0f);
		entity0.modelComponent.get()->scale = sf::Vector2f(0.4f, 0.4f);

		entity0.drawableComponent = std::make_unique<DrawableComponent>();
		entity0.drawableComponent.get()->sprite = std::unique_ptr<sf::Sprite>(new sf::Sprite(texture0));

		entity0.drawableComponent.get()->sprite->setScale(0.1f, 0.1f);
		entity0.drawableComponent.get()->sprite->setPosition(20.0f, 20.0f);

    entity0.dynamicComponent = std::make_unique<DynamicComponent>();
		entity0.dynamicComponent.get()->maxSpeed = 0.75f;
		entity0.dynamicComponent.get()->speed = {0.0f,0.0f};
		entity0.dynamicComponent.get()->desiredPosition = {300.0f,300.0f};

		entity0.systemsKey = {true,true};

		entity1.modelComponent = std::make_unique<ModelComponent>();
		entity1.modelComponent.get()->position = sf::Vector2f(980.0f, 20.0f);
		entity1.modelComponent.get()->scale = sf::Vector2f(-0.4f, 0.4f);

		entity1.drawableComponent = std::make_unique<DrawableComponent>();
		entity1.drawableComponent.get()->sprite = std::unique_ptr<sf::Sprite>(new sf::Sprite(texture0));

		entity1.drawableComponent.get()->sprite->setScale(0.1f, 0.1f);
		entity1.drawableComponent.get()->sprite->setPosition(20.0f, 20.0f);

		entity1.systemsKey = {false,true};

		entity2.modelComponent = std::make_unique<ModelComponent>();
		entity2.modelComponent.get()->position = sf::Vector2f(30.0f, 550.0f);
		entity2.modelComponent.get()->scale = sf::Vector2f(0.4f, -0.4f);

		entity2.drawableComponent = std::make_unique<DrawableComponent>();
		entity2.drawableComponent.get()->sprite = std::unique_ptr<sf::Sprite>(new sf::Sprite(texture0));

		entity2.drawableComponent.get()->sprite->setScale(0.1f, 0.1f);
		entity2.drawableComponent.get()->sprite->setPosition(20.0f, 20.0f);

		entity2.systemsKey = {false,true};

		entity3.modelComponent = std::make_unique<ModelComponent>();
		entity3.modelComponent.get()->position = sf::Vector2f(980.0f, 550.0f);
		entity3.modelComponent.get()->scale = sf::Vector2f(-0.4f, -0.4f);

		entity3.drawableComponent = std::make_unique<DrawableComponent>();
		entity3.drawableComponent.get()->sprite = std::unique_ptr<sf::Sprite>(new sf::Sprite(texture0));

		entity3.drawableComponent.get()->sprite->setScale(0.1f, 0.1f);
		entity3.drawableComponent.get()->sprite->setPosition(20.0f, 20.0f);

		entity3.systemsKey = {false,true};
	}

	std::list<Entity*> entities;
	entities.push_back(&entity3);
	entities.push_back(&entity2);
	entities.push_back(&entity1);
	entities.push_back(&entity0);

	while (window.get()->isOpen())
	{
	  readAndDistruibuteEvents(window.get(), &entities);
	  moveEntity(&entities);
		render(window.get(), &entities);
	}

	return 0;
}


