#include "game.h"

game::game()
{
}

void game::start()
{
    _font.loadFromFile("resources/font/STHeiti Light.ttc");
    _audioPlay.playSound("resources/sound/game_music.ogg", 80);
    _window.create(sf::VideoMode(WIDTH, LENGTH), "lw's Toy");

    while (gameLoop());
    _window.close();
}

bool game::gameLoop()
{
    sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            return false;
    }

     _window.clear();
     _object.updateAll();
     _object.drawAll(_window);
     _window.display();
     return true;
}

void game::soundPlay(const std::string &fileName, int volume)
{
    _audioPlay.playSound(fileName, volume);
}

sf::Texture &game::getTexture(const std::string &fileName)
{
    return _extract.getTexture(fileName);
}



extract game::_extract("resources/image/image.png",
                       "resources/image/shoot.pack");
sf::RenderWindow game::_window;
soundplayer game::_audioPlay;
sf::Font game::_font;
objectManager game::_object;
