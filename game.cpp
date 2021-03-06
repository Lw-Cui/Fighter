#include "game.h"

game::game()
{
}

void game::start()
{
    _font.loadFromFile("resources/font/STHeiti Light.ttc");
    _audioPlay.playSound("resources/sound/game_music.ogg", 80, true);
    _image.loadFromFile("resources/image/gameover.png");
    _gameOver.setTexture(_image);
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

     if (!_object.isContinue()) {
            _window.draw(_gameOver);
            _audioPlay.playSound("resources/sound/game_over.ogg", 75);
            _window.display();
            sf::sleep(sf::seconds(2));
            _object.reStart();
     }

     return true;
}


extract game::_extract("resources/image/image.png",
                       "resources/image/shoot.pack");
sf::RenderWindow game::_window;
soundplayer game::_audioPlay;
sf::Font game::_font;
objectManager game::_object;
difficultControl game::_controlPanel;
sf::Texture game::_image;
sf::Sprite game::_gameOver;
