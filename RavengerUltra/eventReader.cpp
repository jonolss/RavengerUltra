#include "eventReader.hpp"

#include <iostream>

void readAndDistruibuteEvents(sf::Window* window, std::list<Entity*>* entities)
{

  sf::Event event;
  while(window->pollEvent(event))
  {

    if(event.type == sf::Event::Closed)
    {
      window->close();
    }
    else if(event.type == sf::Event::MouseButtonPressed)
    {
      if(event.mouseButton.button == sf::Mouse::Right)
      {
        event.mouseButton.x;
        event.mouseButton.y;
      }

    }
    else if(event.type == sf::Event::MouseButtonReleased)
    {
      if(event.mouseButton.button == sf::Mouse::Right)
      {
        sf::Vector2u windowSize = window->getSize();
        int x = event.mouseButton.x < 0 ? 0 : event.mouseButton.x >= (int)windowSize.x ? (int)windowSize.x-1 : event.mouseButton.x;
        int y = event.mouseButton.y < 0 ? 0 : event.mouseButton.y >= (int)windowSize.y ? (int)windowSize.y-1 : event.mouseButton.y;

        sf::Vector2i mouseLocation = {x, y};



        std::cout << "mouseLocation x: " << mouseLocation.x << "\tmouseLocation y:" << mouseLocation.y << std::endl;

        for(Entity* entity : *entities)
        {
          if(entity->id == 0)
          {
            entity->dynamicComponent.get()->desiredPosition = (sf::Vector2f)mouseLocation;

          }

        }

      }
    }


  }

}
