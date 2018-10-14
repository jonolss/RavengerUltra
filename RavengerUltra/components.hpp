#ifndef COMPONENTS_HPP__
#define COMPONENTS_HPP__

#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>

struct modelComponent {
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Vector2f scale;
	float rotation;
};

struct drawableComponent {
	std::unique_ptr<sf::Sprite> sprite;
};

#endif