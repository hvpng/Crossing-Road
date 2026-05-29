#pragma once
#include "cConsole.h"
using namespace std;
class cMenu
{
    const int WIDTH_SCREEN_MENU = 120;
    const int HEIGHT_SCREEN_MENU = 40;
    void draw(int x, int y, int color, char character);
    void drawTree(int startX, int startY);
    void drawCloud(int startX, int startY);
    void drawTitleGame(int startX, int startY, int color);
    void drawButton(int startX, int startY, int colorFrame, int colorBackground);
    void drawNewGameSymbol(int startX, int startY, int color);
    void drawLoadGameSymbol(int startX, int startY, int color);
    void drawSettingsSymbol(int startX, int startY, int color);
    void drawLeaderBoardSymbol(int startX, int startY, int color);
    void drawExitSymbol(int startX, int startY, int color);
    void drawNewGameText(int startX, int startY, int color);
    void drawLoadGameText(int startX, int startY, int color);
    void drawSettingsText(int startX, int startY, int color);
    void drawLeaderboardText(int startX, int startY, int color);
    void drawExitText(int startX, int startY, int color);
    void drawNewGameButton(int startX, int startY, int colorFrame, int colorBackground, int colorIcon);
    void drawLoadGameButton(int startX, int startY, int colorFrame, int colorBackground, int colorIcon);
    void drawSettingsButton(int startX, int startY, int colorFrame, int colorBackground, int colorIcon);
    void drawLeaderboardButton(int startX, int startY, int colorFrame, int colorBackground, int colorIcon);
    void drawExitButton(int startX, int startY, int colorFrame, int colorBackground, int colorIcon);
    void drawMenuSettings();
public:
    int runMenu();
    void playMusic();
    void stopMusic();
};


