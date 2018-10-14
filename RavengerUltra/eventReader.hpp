#ifndef EVENTREADER_HPP__
#define EVENTREADER_HPP__

#include "entities.hpp"
#include <SFML/Graphics.hpp>
#include <list>

void readAndDistruibuteEvents(sf::Window* window, std::list<Entity*>* entities);

#endif
