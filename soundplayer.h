#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H

#include "SFML/Audio.hpp"
#include <map>

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

    void playSound(const std::string &fileName,
                   int volume = 100, bool loop = false);

private:
    const static int SOUND_SUM = 20;
    sf::Sound _sound[SOUND_SUM];
    soundCache _soundCache;
};

#endif // SOUNDPLAYER_H
