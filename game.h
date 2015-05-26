#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "objectmanager.h"
#include "extract.h"
#include "soundplayer.h"
#include "difficultcontrol.h"

class game
{
public:
    game();
    static void start();
    static bool gameLoop();
    const static int WIDTH = 480;
    const static int LENGTH = 700;
    static void setFont();

    static sf::Font _font;
    static difficultControl _controlPanel;
    static soundplayer _audioPlay;
    static extract _extract;

private:
    static sf::RenderWindow _window;
    static objectManager _object;


    static sf::Texture _image;
    static sf::Sprite _gameOver;
};

#endif // GAME_H
