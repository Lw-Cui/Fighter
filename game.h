#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "objectmanager.h"
#include "extract.h"
#include "soundplayer.h"

class game
{
public:
    game();
    static void start();
    static bool gameLoop();
    const static int WIDTH = 480;
    const static int LENGTH = 700;
    static void soundPlay(const std::string &fileName);
    static sf::Texture& getTexture(const std::string &fileName);

private:
    static extract _extract;
    static soundplayer _audioPlay;
    static sf::RenderWindow _window;
    static objectManager _object;
    static sf::Font _font;
};

#endif // GAME_H
