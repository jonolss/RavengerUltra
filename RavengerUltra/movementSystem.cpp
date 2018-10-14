#include "movementSystem.hpp"

#define FLOAT_PRECISSION 0.0001f

void moveEntity(std::list<Entity*>* entities)
{
  KeyboardInputs keyboardInputs = checkKeyboardInputs();

  for (Entity* entity : *entities)
  {
    if(entity->systemsKey.MovementSystem)
    {
      ModelComponent* model = entity->modelComponent.get();
      DynamicComponent* dynamicComponent = entity->dynamicComponent.get();

      sf::Vector2f speed = {0.0f,0.0f};
      float rotationalSpeed = 0.0f;

      if(false)
      {
        if(keyboardInputs.a || keyboardInputs.arrowLeft)
        {
          speed.x += -1.0f;
        }

        if(keyboardInputs.d || keyboardInputs.arrowRight)
        {
          speed.x += 1.0f;
        }

        if(keyboardInputs.w || keyboardInputs.arrowUp)
        {
          speed.y += -1.0f;
        }

        if(keyboardInputs.s || keyboardInputs.arrowDown)
        {
          speed.y += 1.0f;
        }
      }

      sf::Vector2f desiredPosition = dynamicComponent->desiredPosition;
      sf::Vector2f distance = desiredPosition - model->position;
      sf::Vector2f normalizedDistance = normalize(distance);
      speed = sf::Vector2f(fmin(normalizedDistance.x, distance.x), fmin(normalizedDistance.y, distance.y));

      if(entity->systemsKey.CollisionSystem)
      {
        for (Entity* collisionableEntity : *entities)
        {
          // TODO: ADD NORMAL BOUNDING BOX COLLISION DETECTION


        }
      }


      model->position += speed;
    }
  }

}

sf::Vector2f normalize(sf::Vector2f input)
{
  float x = input.x < FLOAT_PRECISSION && input.x > -FLOAT_PRECISSION ? 0.0f : input.x;
  float y = input.y < FLOAT_PRECISSION && input.y > -FLOAT_PRECISSION ? 0.0f : input.y;

  if(x == 0.0f && y == 0.0f)
  {
    return sf::Vector2f(0.0f,0.0f);
  }

  float length = sqrt(input.x * input.x + input.y * input.y);
  return sf::Vector2f(input / length);
}

KeyboardInputs checkKeyboardInputs()
{
  KeyboardInputs inputs = {false,false,false,false,false,false,false,false,false};

  inputs.a = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
  inputs.d = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
  inputs.s = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
  inputs.w = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
  inputs.space = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
  inputs.arrowUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
  inputs.arrowDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
  inputs.arrowLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
  inputs.arrowRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);

  return inputs;
}
