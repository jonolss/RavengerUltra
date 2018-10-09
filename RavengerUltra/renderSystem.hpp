#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <list>
#include "entities.hpp"


void initRenderSystem();

int render(std::list<entity*>* entities);