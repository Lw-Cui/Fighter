#include "extract.h"
#include <cassert>
#include <utility>
#include <cstdio>

extract::extract()
{

}

extract::~extract()
{

}

extract::extract(const std::string &image, const std::string &index)
{
    FILE *filePoint = fopen(index.c_str(), "r");
    while (!feof(filePoint)) {
        char imageName[100];
        fscanf(filePoint, "%s", imageName);

        int x, y;
        int xSize, ySize;
        fscanf(filePoint, " xy: %d, %d", &x, &y);
        fscanf(filePoint, " size: %d, %d", &xSize, &ySize);

        sf::Texture texture;
        texture.loadFromFile(image, sf::IntRect(x, y, xSize, ySize));
        _allTexture.insert(make_pair(std::string(imageName), texture));
    }

}

void extract::loadFromFile(const std::string &image, const std::string &index)
{
    FILE *filePoint = fopen(index.c_str(), "r");
    while (!feof(filePoint)) {
        char imageName[100];
        fscanf(filePoint, "%s", imageName);

        int x, y;
        int xSize, ySize;
        fscanf(filePoint, " xy: %d, %d", &x, &y);
        fscanf(filePoint, " size: %d, %d", &xSize, &ySize);

        sf::Texture texture;
        texture.loadFromFile(image, sf::IntRect(x, y, xSize, ySize));
        _allTexture.insert(make_pair(std::string(imageName), texture));
    }
}


sf::Texture &extract::getTexture(const std::string &name)
{
    return _allTexture[name];
}

