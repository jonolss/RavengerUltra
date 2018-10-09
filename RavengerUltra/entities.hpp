#pragma once

#include "components.hpp"

struct entity {

	unsigned long id;
	unsigned long componentsKey;

	std::unique_ptr<modelComponent> modelComponent;
	std::unique_ptr<drawableComponent> drawableComponent;

};