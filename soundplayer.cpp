#include <cassert>
#include "soundplayer.h"

soundplayer::soundplayer()
{

}

soundplayer::~soundplayer()
{

}

void soundplayer::playSound(const std::string &fileName,
                            int volume, bool loop)
{
    for (int i = 0; i < SOUND_SUM; i++)
        if (_sound[i].getStatus() != sf::Sound::Playing) {
            _sound[i] = _soundCache.getSound(fileName);
            _sound[i].setVolume(volume);
            _sound[i].setLoop(loop);
            _sound[i].play();
            break;
        }

}


soundCache::soundCache()
{
}

soundCache::~soundCache()
{
    for (std::map<std::string, sf::SoundBuffer*>::iterator ite = _soundBuffer.begin();
         ite != _soundBuffer.end(); ite++) {
        delete ite->second;
        ite->second = NULL;
    }
}

sf::Sound soundCache::getSound(const std::string &fileName)
{
    if (!_soundBuffer.count(fileName)) {
        sf::SoundBuffer *buffer = new sf::SoundBuffer;
        assert(buffer->loadFromFile(fileName));
        _soundBuffer[fileName] = buffer;
    }

    return sf::Sound(*_soundBuffer[fileName]);
}

