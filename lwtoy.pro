TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp \
    game.cpp \
    visualobject.cpp \
    bullet.cpp \
    soundplayer.cpp \
    extract.cpp \
    objectmanager.cpp \
    plane.cpp \
    difficultcontrol.cpp \
    gift.cpp

include(deployment.pri)
qtcAddDeployment()

LIBS += -L"/home/lw/SFML-master/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += "/home/lw/SFML-master/include"
DEPENDPATH += "/home/lw/SFML-master/include"

RESOURCES +=

HEADERS += \
    game.h \
    objectmanager.h \
    visualobject.h \
    bullet.h \
    soundCache.h \
    soundplayer.h \
    extract.h \
    plane.h \
    difficultcontrol.h \
    gift.h
