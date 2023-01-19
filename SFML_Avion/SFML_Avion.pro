TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio
SOURCES += \
        Game.cpp \
        ResourceHolder.cpp \
        main.cpp

HEADERS += \
    Game.h \
    ResourceHolder.h
