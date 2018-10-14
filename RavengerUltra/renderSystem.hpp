#ifndef RENDERSYSTEM_HPP__
#define RENDERSYSTEM_HPP__

#include <SFML/Graphics.hpp>
#include <memory>
#include <list>
#include "entities.hpp"

void render(sf::RenderWindow* window, std::list<Entity*>* entities);

#endif // RENDERSYSTEM_HPP__
