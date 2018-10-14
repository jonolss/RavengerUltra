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

	Entity entity4;
	entity4.id = 4;


	sf::Texture texture0;
	if (texture0.loadFromFile("giraldo.png", sf::IntRect(0, 0, 10, 10)))
	{
	  sf::Vector2f position0 = sf::Vector2f(10.0f,20.0f);
    sf::Vector2f size0 = sf::Vector2f(10, 10);
    sf::Vector2f scale0 = sf::Vector2f(1.0f, 1.0f);
    sf::Vector2f origin0 = sf::Vector2f(5.0f,5.0f);

	  entity0.modelComponent = std::make_unique<ModelComponent>();
		entity0.modelComponent.get()->position = position0;
		entity0.modelComponent.get()->origin = origin0;
		entity0.modelComponent.get()->scale = scale0;

		entity0.collisionComponent = std::make_unique<CollisionComponent>();
		entity0.collisionComponent.get()->boundingBox = sf::FloatRect(position0, size0);

		entity0.drawableComponent = std::make_unique<DrawableComponent>();
		entity0.drawableComponent.get()->sprite = std::unique_ptr<sf::Sprite>(new sf::Sprite(texture0));
		entity0.drawableComponent.get()->sprite->setOrigin(origin0);
		entity0.drawableComponent.get()->sprite->setScale(scale0);
		entity0.drawableComponent.get()->sprite->setPosition(position0);

    entity0.dynamicComponent = std::make_unique<DynamicComponent>();
		entity0.dynamicComponent.get()->maxSpeed = 0.75f;
		entity0.dynamicComponent.get()->speed = {0.0f,0.0f};
		entity0.dynamicComponent.get()->desiredPosition = {300.0f,300.0f};

		entity0.systemsKey = {true,true,true};
	}


	sf::Texture texture1;
	if (texture1.loadFromFile("giraldo.png", sf::IntRect(0, 0, 1200, 675)))
	{
		sf::Vector2f position1 = sf::Vector2f(980.0f, 20.0f);
    sf::Vector2f size1 = sf::Vector2f(1200, 675);
    sf::Vector2f scale1 = sf::Vector2f(-0.4f, 0.4f);
    sf::Vector2f origin1 = sf::Vector2f(0.0f, 0.0f);

		entity1.modelComponent = std::make_unique<ModelComponent>();
		entity1.modelComponent.get()->position = position1;
		entity1.modelComponent.get()->scale = scale1;
		entity1.modelComponent.get()->origin = origin1;

		entity1.drawableComponent = std::make_unique<DrawableComponent>();
		entity1.drawableComponent.get()->sprite = std::unique_ptr<sf::Sprite>(new sf::Sprite(texture1));

		entity1.drawableComponent.get()->sprite->setScale(scale1);
		entity1.drawableComponent.get()->sprite->setPosition(position1);

		entity1.systemsKey = {false,true,false};


		sf::Vector2f position2 = sf::Vector2f(30.0f, 550.0f);
    sf::Vector2f size2 = sf::Vector2f(1200, 675);
    sf::Vector2f scale2 = sf::Vector2f(0.4f, -0.4f);
    sf::Vector2f origin2 = sf::Vector2f(0.0f, 0.0f);

		entity2.modelComponent = std::make_unique<ModelComponent>();
		entity2.modelComponent.get()->position = position2;
		entity2.modelComponent.get()->scale = scale2;
		entity2.modelComponent.get()->origin = origin2;

		entity2.drawableComponent = std::make_unique<DrawableComponent>();
		entity2.drawableComponent.get()->sprite = std::unique_ptr<sf::Sprite>(new sf::Sprite(texture1));

		entity2.drawableComponent.get()->sprite->setScale(scale2);
		entity2.drawableComponent.get()->sprite->setPosition(position2);

		entity2.systemsKey = {false,true,false};


		sf::Vector2f position3 = sf::Vector2f(980.0f, 550.0f);
    sf::Vector2f size3 = sf::Vector2f(1200, 675);
    sf::Vector2f scale3 = sf::Vector2f(-0.4f, -0.4f);
    sf::Vector2f origin3 = sf::Vector2f(0.0f, 0.0f);

		entity3.modelComponent = std::make_unique<ModelComponent>();
		entity3.modelComponent.get()->position = position3;
		entity3.modelComponent.get()->scale = scale3;
		entity3.modelComponent.get()->origin = origin3;

		entity3.drawableComponent = std::make_unique<DrawableComponent>();
		entity3.drawableComponent.get()->sprite = std::unique_ptr<sf::Sprite>(new sf::Sprite(texture1));

		entity3.drawableComponent.get()->sprite->setScale(scale3);
		entity3.drawableComponent.get()->sprite->setPosition(position3);

		entity3.systemsKey = {false,true,false};
	}

	sf::Texture texture2;
	if (texture2.loadFromFile("giraldo.png", sf::IntRect(0, 0, 5, 50)))
	{
    sf::Vector2f position4 = sf::Vector2f(500.0f, 650.0f);
    sf::Vector2f size4 = sf::Vector2f(5.0f, 50.0f);
    sf::Vector2f scale4 = sf::Vector2f(1.0f, 1.0f);
    sf::Vector2f origin4 = sf::Vector2f(0.0f, 0.0f);

		entity4.modelComponent = std::make_unique<ModelComponent>();
		entity4.modelComponent.get()->position = position4;
		entity4.modelComponent.get()->scale = scale4;
		entity4.modelComponent.get()->origin = origin4;

		entity4.collisionComponent = std::make_unique<CollisionComponent>();
		entity4.collisionComponent.get()->boundingBox = sf::FloatRect(position4, size4);

		entity4.drawableComponent = std::make_unique<DrawableComponent>();
		entity4.drawableComponent.get()->sprite = std::unique_ptr<sf::Sprite>(new sf::Sprite(texture2));

		entity4.drawableComponent.get()->sprite->setScale(scale4);
		entity4.drawableComponent.get()->sprite->setPosition(position4);

		entity4.systemsKey = {false,true,true};

	}

	std::list<Entity*> entities;
	entities.push_back(&entity3);
	entities.push_back(&entity2);
	entities.push_back(&entity1);
	entities.push_back(&entity0);
	entities.push_back(&entity4);

	while (window.get()->isOpen())
	{
	  readAndDistruibuteEvents(window.get(), &entities);
	  moveEntity(&entities);
		render(window.get(), &entities);
	}

	return 0;
}


