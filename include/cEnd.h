#pragma once
#include "cConsole.h"
class cEnd
{
    const int WIDTH_SCREEN_MENU = 120;
    const int HEIGHT_SCREEN_MENU = 40;
    void draw(int x, int y, int color, char character);
    void drawBackGround();
    void drawCurtain();
    void drawGoodbey(int);
    void drawCloud(int startX, int startY);
    void drawTextEnd();
public:
    void runEnd();
};
