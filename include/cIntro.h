#pragma once
#include "cConsole.h"
class cIntro
{
    const int WIDTH_SCREEN_MENU = 120;
    const int HEIGHT_SCREEN_MENU = 40;
    void draw(int x, int y, int color, char character);
    void drawBackGround();
    void drawAlphabet();
public:
    void runIntro();
};

