#include "GraphicLoop.hpp"

class Kov {

private:
	int a;

public:
	Kov(int a) {
		this->a = a;
	}

	int getA() { return a; }


};

int graphicLoop(sf::RenderWindow *window) {

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
	}

	window->clear();
	window->draw(shape);
	window->display();

	std::unique_ptr<Kov> pointer(new Kov(2));


	return 0;
}

