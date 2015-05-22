#ifndef EXTRACT_H
#define EXTRACT_H

#include <string>
#include <map>
#include "SFML/Graphics.hpp"

class extract
{
public:
    extract();
    ~extract();

    extract(const std::string &image, const std::string &index);
    void loadFromFile(const std::string &image, const std::string &index);
    sf::Texture &getTexture(const std::string &name);

private:
    std::map<std::string, sf::Texture> _allTexture;
};

#endif // EXTRACT_H
