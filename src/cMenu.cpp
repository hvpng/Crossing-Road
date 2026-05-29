#include "cMenu.h"
using namespace std;

void cMenu::draw(int x, int y, int color, char character)
{
    cConsole console;
    console.gotoXY(x, y);
    console.textColor(color);
    cout << character;
    console.textColor(7);
}

void cMenu::drawTree(int startX, int startY)
{
    cConsole console;
    SetConsoleOutputCP(CP_UTF8);
    console.gotoXY(startX, startY);
    console.textColor(178);
    cout << u8"  ███████████  ";
    console.gotoXY(startX, startY + 1);
    console.textColor(178);
    cout << u8" █████████████ ";
    console.gotoXY(startX, startY + 2);
    console.textColor(178);
    cout << u8"███████████████";
    console.gotoXY(startX, startY + 3);
    console.textColor(178);
    cout << u8"███████████████";
    console.gotoXY(startX, startY + 4);
    console.textColor(178);
    cout << u8"███████████████";
    console.gotoXY(startX, startY + 5);
    console.textColor(178);
    cout << u8" ████     ████ ";
    console.gotoXY(startX + 5, startY + 5);
    console.textColor(182);
    cout << u8"█████";
    console.gotoXY(startX, startY + 6);
    console.textColor(178);
    cout << u8"  ███     ███  ";
    console.gotoXY(startX + 5, startY + 6);
    console.textColor(182);
    cout << u8"█████";
    console.gotoXY(startX, startY + 7);
    console.textColor(182);
    cout << u8"     █████     ";
    console.gotoXY(startX, startY + 8);
    console.textColor(182);
    cout << u8"     █████     ";
    console.gotoXY(startX, startY + 9);
    console.textColor(182);
    cout << u8"     █████     ";
    console.gotoXY(startX, startY + 10);
    console.textColor(182);
    cout << u8"     █████     ";
    console.gotoXY(startX, startY + 11);
    console.textColor(182);
    cout << u8"     █████     ";
    SetConsoleOutputCP(437);
}

void cMenu::drawCloud(int startX, int startY)
{
    cConsole console;
    SetConsoleOutputCP(CP_UTF8);
    console.gotoXY(startX, startY);
    console.textColor(185);
    cout << u8"      ███████████         ";
    console.gotoXY(startX, startY + 1);
    console.textColor(185);
    cout << u8"    ██           ██       ";
    console.gotoXY(startX + 6, startY + 1);
    console.textColor(240);
    cout << u8"           ";
    console.gotoXY(startX, startY + 2);
    console.textColor(185);
    cout << u8" ███               ███    ";
    console.gotoXY(startX + 4, startY + 2);
    console.textColor(240);
    cout << u8"               ";
    console.gotoXY(startX, startY + 3);
    console.textColor(185);
    cout << u8"█                     ███ ";
    console.gotoXY(startX + 1, startY + 3);
    console.textColor(240);
    cout << u8"                     ";
    console.gotoXY(startX, startY + 4);
    console.textColor(185);
    cout << u8"█                        █";
    console.gotoXY(startX + 1, startY + 4);
    console.textColor(240);
    cout << u8"                        ";
    console.gotoXY(startX, startY + 5);
    console.textColor(185);
    cout << u8" █                      █ ";
    console.gotoXY(startX + 2, startY + 5);
    console.textColor(240);
    cout << u8"                      ";
    console.gotoXY(startX, startY + 6);
    console.textColor(185);
    cout << u8"  ██████████████████████  ";
    SetConsoleOutputCP(437);
}

void cMenu::drawTitleGame(int startX, int startY, int color)
{
    cConsole console;
    SetConsoleOutputCP(CP_UTF8);
    console.gotoXY(startX, startY);
    console.textColor(color);
    cout << u8"███████ █████████     ███████ ███████ ███████ ███ ██    ██ ███████";
    console.gotoXY(startX, startY + 1);
    console.textColor(color);
    cout << u8"██      ████    ███   ██   ██ ██▄▄▄▄▄ ██▄▄▄▄▄ ███ ████  ██ ██     ";
    console.gotoXY(startX, startY + 2);
    console.textColor(color);
    cout << u8"██      ████     ███  ██   ██       █       █ ███ ██ ██ ██ ██   ██";
    console.gotoXY(startX, startY + 3);
    console.textColor(color);
    cout << u8"███████ ████    ███   ███████ ███████ ███████ ███ ██  ████ ███████";
    console.gotoXY(startX, startY + 4);
    console.textColor(color);
    cout << u8"        █████████                                                 ";
    console.gotoXY(startX, startY + 5);
    console.textColor(color);
    cout << u8"        ███     ███   ███████    ███    ███████";
    console.gotoXY(startX, startY + 6);
    console.textColor(color);
    cout << u8"        ███     ███   ██   ██   ██ ██   ██    ██";
    console.gotoXY(startX, startY + 7);
    console.textColor(color);
    cout << u8"        ███     ███   ██   ██  ██▀▀▀██  ██    ██";
    console.gotoXY(startX, startY + 8);
    console.textColor(color);
    cout << u8"        ███     ███   ███████ ██     ██ ███████";
    SetConsoleOutputCP(437);
}

void cMenu::drawButton(int startX, int startY, int colorFrame, int colorBackground)
{
    cConsole console;
    SetConsoleOutputCP(CP_UTF8);
    console.gotoXY(startX, startY);
    console.textColor(colorFrame);
    cout << u8"  ▄▄▄▄▄▄▄▄▄  ";
    console.gotoXY(startX, startY + 1);
    console.textColor(colorFrame);
    cout << u8" █         █ ";
    console.gotoXY(startX + 2, startY + 1);
    console.textColor(colorBackground);
    cout << u8"         ";
    console.gotoXY(startX, startY + 2);
    console.textColor(colorFrame);
    cout << u8"█           █";
    console.gotoXY(startX + 1, startY + 2);
    console.textColor(colorBackground);
    cout << u8"           ";
    console.gotoXY(startX, startY + 3);
    console.textColor(colorFrame);
    cout << u8"█           █";
    console.gotoXY(startX + 1, startY + 3);
    console.textColor(colorBackground);
    cout << u8"           ";
    console.gotoXY(startX, startY + 4);
    console.textColor(colorFrame);
    cout << u8"█           █";
    console.gotoXY(startX + 1, startY + 4);
    console.textColor(colorBackground);
    cout << u8"           ";
    console.gotoXY(startX, startY + 5);
    console.textColor(colorFrame);
    cout << u8" █         █ ";
    console.gotoXY(startX + 2, startY + 5);
    console.textColor(colorBackground);
    cout << u8"         ";
    console.gotoXY(startX, startY + 6);
    console.textColor(colorFrame);
    cout << u8"  ▀▀▀▀▀▀▀▀▀  ";
    SetConsoleOutputCP(437);
}

void cMenu::drawNewGameSymbol(int startX, int startY, int color)
{
    cConsole console;
    SetConsoleOutputCP(CP_UTF8);
    console.gotoXY(startX, startY);
    console.textColor(color);
    cout << u8"█▄  ";
    console.gotoXY(startX, startY + 1);
    console.textColor(color);
    cout << u8"███■";
    console.gotoXY(startX, startY + 2);
    console.textColor(color);
    cout << u8"█▀  ";
    SetConsoleOutputCP(437);
}

void cMenu::drawLoadGameSymbol(int startX, int startY, int color)
{
    cConsole console;
    SetConsoleOutputCP(CP_UTF8);
    console.gotoXY(startX, startY);
    console.textColor(color);
    cout << u8" ▄▄▄▄▄ ";
    console.gotoXY(startX, startY + 1);
    console.textColor(color);
    cout << u8"▐ ▀▄▀ ▌";
    console.gotoXY(startX, startY + 2);
    console.textColor(color);
    cout << u8"▐▄███▄▌";
    SetConsoleOutputCP(437);
}

void cMenu::drawSettingsSymbol(int startX, int startY, int color)
{
    cConsole console;
    SetConsoleOutputCP(CP_UTF8);
    console.gotoXY(startX, startY);
    console.textColor(color);
    cout << u8" ▀▄■▄▀ ";
    console.gotoXY(startX, startY + 1);
    console.textColor(color);
    cout << u8"■█ ■ █■";
    console.gotoXY(startX, startY + 2);
    console.textColor(color);
    cout << u8" ▄▀■▀▄ ";
    SetConsoleOutputCP(437);
}

void cMenu::drawLeaderBoardSymbol(int startX, int startY, int color)
{
    cConsole console;
    SetConsoleOutputCP(CP_UTF8);
    console.gotoXY(startX, startY);
    console.textColor(color);
    cout << u8"   ██   ";
    console.gotoXY(startX, startY + 1);
    console.textColor(color);
    cout << u8"██ ██ ▄▄";
    console.gotoXY(startX, startY + 2);
    console.textColor(color);
    cout << u8"██ ██ ██";
    SetConsoleOutputCP(437);
}

void cMenu::drawExitSymbol(int startX, int startY, int color)
{
    cConsole console;
    SetConsoleOutputCP(CP_UTF8);
    console.gotoXY(startX, startY);
    console.textColor(color);
    cout << u8"██▀ ▄  ";
    console.gotoXY(startX, startY + 1);
    console.textColor(color);
    cout << u8"▌■■■██■";
    console.gotoXY(startX, startY + 2);
    console.textColor(color);
    cout << u8"██▄ ▀  ";
    SetConsoleOutputCP(437);
}

void cMenu::drawNewGameText(int startX, int startY, int color)
{
    cConsole console;
    SetConsoleOutputCP(CP_UTF8);
    console.gotoXY(startX, startY);
    console.textColor(color);
    cout << u8"     █▄ █ █▀▀ █ █ █   █▀▀ ▄▀█ █▀▄▀█ █▀▀    ";
    console.gotoXY(startX, startY + 1);
    console.textColor(color);
    cout << u8"     █ ▀█ ██▄ ▀▄▀▄▀   █▄█ █▀█ █ ▀ █ ██▄    ";
    SetConsoleOutputCP(437);
}

void cMenu::drawLoadGameText(int startX, int startY, int color)
{
    cConsole console;
    SetConsoleOutputCP(CP_UTF8);
    console.gotoXY(startX, startY);
    console.textColor(color);
    cout << u8"    █   █▀█ ▄▀█ █▀▄   █▀▀ ▄▀█ █▀▄▀█ █▀▀    ";
    console.gotoXY(startX, startY + 1);
    console.textColor(color);
    cout << u8"    █▄▄ █▄█ █▀█ █▄▀   █▄█ █▀█ █ ▀ █ ██▄    ";
    SetConsoleOutputCP(437);
}

void cMenu::drawSettingsText(int startX, int startY, int color)
{
    cConsole console;
    SetConsoleOutputCP(CP_UTF8);
    console.gotoXY(startX, startY);
    console.textColor(color);
    cout << u8"        █▀ █▀▀ ▀█▀ ▀█▀ █ █▄ █ █▀▀ █▀       ";
    console.gotoXY(startX, startY + 1);
    console.textColor(color);
    cout << u8"        ▄█ ██▄  █   █  █ █ ▀█ █▄█ ▄█       ";
    SetConsoleOutputCP(437);
}

void cMenu::drawLeaderboardText(int startX, int startY, int color)
{
    cConsole console;
    SetConsoleOutputCP(CP_UTF8);
    console.gotoXY(startX, startY);
    console.textColor(color);
    cout << u8"█   █▀▀ ▄▀█ █▀▄ █▀▀ █▀█ █▄▄ █▀█ ▄▀█ █▀█ █▀▄";
    console.gotoXY(startX, startY + 1);
    console.textColor(color);
    cout << u8"█▄▄ ██▄ █▀█ █▄▀ ██▄ █▀▄ █▄█ █▄█ █▀█ █▀▄ █▄▀";
    SetConsoleOutputCP(437);
}

void cMenu::drawExitText(int startX, int startY, int color)
{
    cConsole console;
    SetConsoleOutputCP(CP_UTF8);
    console.gotoXY(startX, startY);
    console.textColor(color);
    cout << u8"               █▀▀ ▀▄▀ █ ▀█▀               ";
    console.gotoXY(startX, startY + 1);
    console.textColor(color);
    cout << u8"               ██▄ █ █ █  █                ";
    SetConsoleOutputCP(437);
}

void cMenu::drawNewGameButton(int startX, int startY, int colorFrame, int colorBackground, int colorIcon)
{
    drawButton(startX, startY, colorFrame, colorBackground);
    drawNewGameSymbol(startX + 5, startY + 2, colorIcon);
}

void cMenu::drawLoadGameButton(int startX, int startY, int colorFrame, int colorBackground, int colorIcon)
{
    drawButton(startX, startY, colorFrame, colorBackground);
    drawLoadGameSymbol(startX + 3, startY + 2, colorIcon);
}

void cMenu::drawSettingsButton(int startX, int startY, int colorFrame, int colorBackground, int colorIcon)
{
    drawButton(startX, startY, colorFrame, colorBackground);
    drawSettingsSymbol(startX + 3, startY + 2, colorIcon);
}

void cMenu::drawLeaderboardButton(int startX, int startY, int colorFrame, int colorBackground, int colorIcon)
{
    drawButton(startX, startY, colorFrame, colorBackground);
    drawLeaderBoardSymbol(startX + 3, startY + 2, colorIcon);
}

void cMenu::drawExitButton(int startX, int startY, int colorFrame, int colorBackground, int colorIcon)
{
    drawButton(startX, startY, colorFrame, colorBackground);
    drawExitSymbol(startX + 3, startY + 2, colorIcon);
}

void cMenu::drawMenuSettings()
{
    // Sua doi thong so o day:
    const int marginTree = 5; /* cach le cua cay */
    const int widthTree = 15, heightTree = 15; /* chieu rong va chieu cao cua cay */
    /*---------- SETTINGS ----------*/
   // to mau: nen
    for (int i = 0; i < HEIGHT_SCREEN_MENU - 3; i++)
    {
        for (int j = 0; j < WIDTH_SCREEN_MENU; j++)
        {
            draw(j, i, 187, ' ');
        }
    }

    // to mau: cay
    drawTree(marginTree, HEIGHT_SCREEN_MENU - heightTree);
    drawTree(WIDTH_SCREEN_MENU - marginTree - widthTree, HEIGHT_SCREEN_MENU - heightTree);

    // to mau: dat
    for (int i = HEIGHT_SCREEN_MENU - 3; i < HEIGHT_SCREEN_MENU; i++)
    {
        for (int j = 0; j < WIDTH_SCREEN_MENU; j++)
        {
            draw(j, i, 204, ' ');
        }
    }

    // to mau: may
    drawCloud(5, 12);
    drawCloud(90, 8);

    // to mau: title
    drawTitleGame(30, 2, 180);

    // to mau: button
    drawNewGameButton(45, 19, 176, 170, 175);
    drawLoadGameButton(62, 19, 176, 240, 253);
    drawLeaderboardButton(54, 27, 176, 240, 252);
    drawSettingsButton(37, 27, 176, 240, 248);
    drawExitButton(71, 27, 176, 240, 243);

    // default:
    drawNewGameText(39, 15, 176);
}

int cMenu::runMenu() {
    string stringChoice = "new game";
    cConsole c;
    drawMenuSettings();

    /*---------- CHOOSE MENU ----------*/
    while (true)
    {
        if (_kbhit)
        {
            char choice = _getch();
            // bam nut
            if (choice == 77) // mui ten sang phai
            {
                if (stringChoice == "new game") // neu tu new game bam sang phai -> load game
                {
                    drawNewGameButton(45, 19, 176, 240, 250);
                    drawLoadGameButton(62, 19, 176, 221, 223);
                    drawLoadGameText(39, 15, 176);
                    stringChoice = "load game";

                }
                else if (stringChoice == "settings") // neu tu new game bam sang phai -> leaderboard
                {
                    drawSettingsButton(37, 27, 176, 240, 248);
                    drawLeaderboardButton(54, 27, 176, 204, 207);
                    drawLeaderboardText(39, 15, 176);
                    stringChoice = "leaderboard";
                }
                else if (stringChoice == "leaderboard") // neu tu leaderboard bam sang phai -> exit
                {
                    drawLeaderboardButton(54, 27, 176, 240, 252);
                    drawExitButton(71, 27, 176, 51, 63);
                    drawExitText(39, 15, 176);
                    stringChoice = "exit";
                }
            }
            else if (choice == 80) // mui ten xuong
            {
                if (stringChoice == "new game") // neu tu new game bam xuong duoi -> settings
                {
                    drawNewGameButton(45, 19, 176, 240, 250);
                    drawSettingsButton(37, 27, 176, 136, 143);
                    drawSettingsText(39, 15, 176);
                    stringChoice = "settings";
                }
                else if (stringChoice == "load game") // neu tu load game bam xuong duoi -> leaderboard
                {
                    drawLoadGameButton(62, 19, 176, 240, 253);
                    drawLeaderboardButton(54, 27, 176, 204, 207);
                    drawLeaderboardText(39, 15, 176);
                    stringChoice = "leaderboard";
                }
            }
            else if (choice == 75) // mui ten sang trai
            {
                if (stringChoice == "load game") // neu tu load game bam sang trai -> new game
                {
                    drawLoadGameButton(62, 19, 176, 240, 253);
                    drawNewGameButton(45, 19, 176, 170, 175);
                    drawNewGameText(39, 15, 176);
                    stringChoice = "new game";
                }
                else if (stringChoice == "leaderboard") // neu tu leaderboard bam sang trai -> settings
                {
                    drawLeaderboardButton(54, 27, 176, 240, 252);
                    drawSettingsButton(37, 27, 176, 136, 143);
                    drawSettingsText(39, 15, 176);
                    stringChoice = "settings";
                }
                else if (stringChoice == "exit") // neu tu exit bam sang trai -> leaderboard
                {
                    drawExitButton(71, 27, 176, 240, 243);
                    drawLeaderboardButton(54, 27, 176, 204, 207);
                    drawLeaderboardText(39, 15, 176);
                    stringChoice = "leaderboard";
                }
            }
            else if (choice == 72) // mui ten len
            {
                if (stringChoice == "settings") // neu tu settings bam len -> new game
                {
                    drawSettingsButton(37, 27, 176, 240, 248);
                    drawNewGameButton(45, 19, 176, 170, 175);
                    drawNewGameText(39, 15, 176);
                    stringChoice = "new game";
                }
                else if (stringChoice == "leaderboard") // neu tu leaderboard bam len -> load game
                {
                    drawLeaderboardButton(54, 27, 176, 240, 252);
                    drawLoadGameButton(62, 19, 176, 221, 223);
                    drawLoadGameText(39, 15, 176);
                    stringChoice = "load game";
                }
                else if (stringChoice == "exit") // new tu exit bam len -> load game
                {
                    drawExitButton(71, 27, 176, 240, 243);
                    drawLoadGameButton(62, 19, 176, 221, 223);
                    drawLoadGameText(39, 15, 176);
                    stringChoice = "load game";
                }
            }
            else if (choice == 13) {
                c.textColor(7);
                if (stringChoice == "new game") return 1;
                if (stringChoice == "load game") return 2;
                if (stringChoice == "settings") return 3;
                if (stringChoice == "leaderboard") return 4;
                if (stringChoice == "exit") return 5;

            }
        }
    }
    return 0;
}

void cMenu::playMusic() {
    PlaySound(TEXT("sounds\\bg.wav"), NULL, SND_LOOP || SND_ASYNC);
}
void cMenu::stopMusic() {
    PlaySound(NULL, NULL, NULL);
}