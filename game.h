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
    static void soundPlay(const std::string &fileName, int volume = 100);
    static sf::Texture& getTexture(const std::string &fileName);
    static void setFont();

    static sf::Font _font;
private:
    static extract _extract;
    static soundplayer _audioPlay;
    static sf::RenderWindow _window;
    static objectManager _object;
};

#endif // GAME_H
