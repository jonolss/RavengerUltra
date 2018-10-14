#ifndef COMPONENTS_HPP__
#define COMPONENTS_HPP__

#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>

struct ModelComponent
{
	sf::Vector2f position;
	sf::Vector2f origin;
	sf::Vector2f size;
	sf::Vector2f scale;
	float rotation;
};

struct CollisionComponent
{
	sf::FloatRect boundingBox;
};

struct DynamicComponent
{
  float maxSpeed;
  sf::Vector2f speed;
  sf::Vector2f desiredPosition;
};

struct DrawableComponent
{
	std::unique_ptr<sf::Sprite> sprite;
};

#endif
