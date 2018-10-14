#ifndef ENTITIES_HPP__
#define ENTITIES_HPP__

#include "components.hpp"

struct SystemKey {

  bool MovementSystem;
  bool RenderSystem;

};

struct Entity {

	unsigned long id;
	SystemKey systemsKey;

	std::unique_ptr<ModelComponent> modelComponent;
	std::unique_ptr<DynamicComponent> dynamicComponent;
	std::unique_ptr<DrawableComponent> drawableComponent;

};

#endif
