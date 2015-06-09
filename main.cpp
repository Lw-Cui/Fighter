
#include "game.h"

int main()
{
    game lwToy;
    lwToy.start();

/*
    sf::RenderWindow x(sf::VideoMode(300, 300), "x");

    while (x.isOpen()) {

        sf::Event event;
        while (x.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                x.close();

            sf::Sprite sp;
            sp.setTexture(game::getTexture("5-bat"));
            x.draw(sp);
            x.display();
        }
    }
*/

    return 0;
}
