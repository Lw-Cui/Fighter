#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H

#include "SFML/Audio.hpp"
#include <map>
#include <string>

class soundCache
{
public:
    soundCache();
    ~soundCache();

    sf::Sound getSound(const std::string &fileName);

private:
    std::map<std::string, sf::SoundBuffer*> _soundBuffer;
};


class soundplayer
{
public:
    soundplayer();
    ~soundplayer();

    void playSound(const std::string &fileName);

private:
    const static int SOUND_SUM = 10;
    sf::Sound _sound[SOUND_SUM];
    soundCache _soundCache;
};

#endif // SOUNDPLAYER_H
