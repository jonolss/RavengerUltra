#ifndef MOVEMENTSYSTEM_HPP__
#define MOVEMENTSYSTEM_HPP__


#include <math.h>
#include <list>
#include "entities.hpp"

struct KeyboardInputs
{
    bool a;
    bool d;
    bool s;
    bool w;
    bool space;
    bool arrowUp;
    bool arrowDown;
    bool arrowLeft;
    bool arrowRight;
};

void moveEntity(std::list<Entity*>* entities);

bool closeEnough(sf::Vector2f vec0, sf::Vector2f vec1);

sf::Vector2f normalize(sf::Vector2f input);

KeyboardInputs checkKeyboardInputs();


#endif // MOVEMENTSYSTEM_HPP__WW
