#ifndef VISUALOBJECT_H
#define VISUALOBJECT_H

#include <SFML/Graphics.hpp>
#include <string>

class visualObject
{
public:
    visualObject();
    virtual ~visualObject();

    virtual void update() = 0;
    virtual bool isExisting() = 0;
    sf::FloatRect getBounds();
    const sf::Vector2f getPosition();
    const sf::Vector2u getSize();
    void draw(sf::RenderWindow &window);

protected:
    void load(int index);
    void load();

    sf::Sprite _sprite;
    std::string _prototype;

};

#endif // VISUALOBJECT_H
