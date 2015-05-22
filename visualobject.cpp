#include "visualobject.h"
#include "game.h"

visualObject::visualObject()
{
}

visualObject::~visualObject()
{

}

void visualObject::load(int index)
{
    std::string tmp = _prototype;
    tmp[0] = '0' + index;
    _sprite.setTexture(game::getTexture(tmp));
    _sprite.setOrigin(getSize().x / 2, getSize().y / 2);
}

void visualObject::load()
{
    _sprite.setTexture(game::getTexture(_prototype));
    _sprite.setOrigin(sf::Vector2f(getSize().x / 2, getSize().y / 2));
}

void visualObject::draw(sf::RenderWindow &window)
{
    window.draw(_sprite);
}


sf::FloatRect visualObject::getBounds()
{
    return _sprite.getGlobalBounds();
}

const sf::Vector2u visualObject::getSize()
{
    return _sprite.getTexture()->getSize();
}

const sf::Vector2f visualObject::getPosition()
{
    return _sprite.getPosition();
}
