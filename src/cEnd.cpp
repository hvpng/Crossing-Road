#include "cEnd.h"
void cEnd::draw(int x, int y, int color, char character)
{
    cConsole console;
    console.gotoXY(x, y);
    console.textColor(color);
    cout << character;
    console.textColor(7);
}
void cEnd::drawBackGround()
{
    cConsole c;
    int x = 0;
    int y = 12;
   // to mau: nen
    for (int i = 0; i < HEIGHT_SCREEN_MENU; i++)
    {
        for (int j = 0; j < WIDTH_SCREEN_MENU; j++)
        {
            draw(j, i, 187, ' ');
        }
    }
}
void cEnd::drawCurtain()
{
    cConsole c;
    SetConsoleOutputCP(CP_UTF8);
    for (int k = 0; k < HEIGHT_SCREEN_MENU/2; k++) {
        for (int j = 0; j < WIDTH_SCREEN_MENU; j++)
        {
           c.textColor(96);
           c.gotoXY(j, k);
           cout << u8"▒";
           c.gotoXY(WIDTH_SCREEN_MENU - 1 -j, HEIGHT_SCREEN_MENU - 1 -k);
           cout << u8"▒";
        }
        drawGoodbey(k);
        Sleep(150);
    }
    c.gotoXY(0, HEIGHT_SCREEN_MENU + 1);
}
void cEnd::drawGoodbey(int k)
{
    cConsole c;
    int x = 0;
    int y = 12;
    c.textColor(180);
    SetConsoleOutputCP(CP_UTF8);
    if (y > k && y < HEIGHT_SCREEN_MENU - 1 - k)           { c.gotoXY(x + k, y);       cout << u8" ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄                                                         "; }
    if (y + 1 > k && y + 1 < HEIGHT_SCREEN_MENU - 1 - k)   { c.gotoXY(x + k, y + 1);   cout << u8" █░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█                                                       "; }
    if (y + 2 > k && y + 2 < HEIGHT_SCREEN_MENU - 1 - k)   { c.gotoXY(x + k, y + 2);   cout << u8" █░░░░░▄▄▀▀▀▀▀▄░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█                                                      "; }
    if (y + 3 > k && y + 3 < HEIGHT_SCREEN_MENU - 1 - k)   { c.gotoXY(x + k, y + 3);   cout << u8" █░░░░▄▀░░░░░░░▀▄░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█                                                     "; }
    if (y + 4 > k && y + 4 < HEIGHT_SCREEN_MENU - 1 - k)   { c.gotoXY(x + k, y + 4);   cout << u8" █░░░▄▀░░░▄▄░░░░▀▀▀▀▀▀▀▄▄▀▀▀▀▀▀▀▀▀▀▀▀▄▄░░░░░░░░░█                                                    "; }
    if (y + 5 > k && y + 5 < HEIGHT_SCREEN_MENU - 1 - k)   { c.gotoXY(x + k, y + 5);   cout << u8" █░░░█░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░░░▀▄░░░░░░░█                 ▄▄▄▄▄                              "; }
    if (y + 6 > k && y + 6 < HEIGHT_SCREEN_MENU - 1 - k)   { c.gotoXY(x + k, y + 6);   cout << u8" █░░░█░░░░██▄████▄░██▄░░░░▄██░▄████▄░░░░▀▄░░░░░░█                  ▐   ▐▄▄      ▄▄▄▄▄                "; }
    if (y + 7 > k && y + 7 < HEIGHT_SCREEN_MENU - 1 - k)   { c.gotoXY(x + k, y + 7);   cout << u8" █░░░█░░░░██▀░░▀██▄░██▄░░██▀░██▀░▄██░░░░░█░░░░░░█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▐   ▐▐▄▄▄▄▄▄▄▐▄▄▄▐████████████   "; }
    if (y + 8 > k && y + 8 < HEIGHT_SCREEN_MENU - 1 - k)   { c.gotoXY(x + k, y + 8);   cout << u8" █░░░█░░░░██░░░░███░░█████▀░░██▄█▀▀░░░░░░█░░░░░░█                   ▐ ▐▄▐   ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄  █▄▄"; }
    if (y + 9 > k && y + 9 < HEIGHT_SCREEN_MENU - 1 - k)   { c.gotoXY(x + k, y + 9);   cout << u8" █░░░█░░░░███▄▄███▀░░░▀██▀░░░▀██▄▄▄██░░░░█░░░░░░█                    ▐▄▄▄▄▄▄▄▄▄▄.▄▄▄▄.▄▄▄▄▄▄▄▄▄▄▄▄▄▄▀"; }
    if (y + 10 > k && y + 10 < HEIGHT_SCREEN_MENU - 1 - k) { c.gotoXY(x + k, y + 10);  cout << u8" █░░░▀▄░░░░▀▀▀▀▀▀░░░░░██▀░░░░░░▀▀▀▀▀░░░░░█░░░░░░█                           ...▄▐▄▄▄▄▐               "; }
    if (y + 11 > k && y + 11 < HEIGHT_SCREEN_MENU - 1 - k) { c.gotoXY(x + k, y + 11);  cout << u8" █░░░░▀▄░░░░░░░░░░░░░██▀░░░▄▄░░░░░░░░░▄▄▀░░░░░░░█                                                    "; }
    if (y + 12 > k && y + 12 < HEIGHT_SCREEN_MENU - 1 - k) { c.gotoXY(x + k, y + 12);  cout << u8" █░░░░░░▀▀▀▀▀▀▀▀▀▄░░░▀▀░░░▄▀░▀▀▀▀▀▀▀▀▀░░░░░░░░░█                                                     "; }
    if (y + 13 > k && y + 13 < HEIGHT_SCREEN_MENU - 1 - k) { c.gotoXY(x + k, y + 13);  cout << u8" █░░░░░░░░░░░░░░░░▀▄░░░░░░▄▀░░░░░░░░░░░░░░░░░░█                                                      "; }
    if (y + 14 > k && y + 14 < HEIGHT_SCREEN_MENU - 1 - k) { c.gotoXY(x + k, y + 14);  cout << u8" █░░░░░░░░░░░░░░░░░░▀▀▀▀▀▀░░░░░░░░░░░░░░░░░░░█                                                       "; }
    if (y + 15 > k && y + 15 < HEIGHT_SCREEN_MENU - 1 - k) { c.gotoXY(x + k, y + 15);  cout << u8"  ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀                                                        "; }
}
void cEnd::drawCloud(int startX, int startY)
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
//███████╗
//██╔════╝
//█████╗
//██╔══╝
//███████╗
//╚══════╝
void cEnd::drawTextEnd()
{
    cConsole console;
    SetConsoleOutputCP(CP_UTF8);
    console.textColor(96);
    int x = 40;
    int y = 13;
    for (int i = -26; i <= 0; i++) {
        if (y - 13 + i >= 0) { console.gotoXY(x, y - 13 + i);    cout << u8"▒▒▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▒▒▒▒▒"; }
        if (y - 12 + i >= 0) { console.gotoXY(x, y - 12 + i);    cout << u8"▒▒▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▒▒▒▒▒"; }
        if (y - 11 + i >= 0) { console.gotoXY(x, y - 11 + i);    cout << u8"▒▒▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▒▒▒▒▒"; }
        if (y - 10 + i >= 0) { console.gotoXY(x, y - 10 + i);    cout << u8"▒▒▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▒▒▒▒▒"; }
        if (y - 9 + i >= 0) { console.gotoXY(x, y - 9 + i);     cout << u8"▒▒▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▒▒▒▒▒"; }
        if (y - 8 + i >= 0) { console.gotoXY(x, y - 8 + i);     cout << u8"▒▒▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▒▒▒▒▒"; }
        if (y - 7 + i >= 0) { console.gotoXY(x, y - 7 + i);     cout << u8"▒▒▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▒▒▒▒▒"; }
        if (y - 6 + i >= 0) { console.gotoXY(x, y - 6 + i);     cout << u8"▒▒▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▒▒▒▒▒"; }
        if (y - 5 + i >= 0) { console.gotoXY(x, y - 5 + i);     cout << u8"▒▒▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▒▒▒▒▒"; }
        if (y - 4 + i >= 0) { console.gotoXY(x, y - 4 + i);     cout << u8"▒▒▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▒▒▒▒▒"; }
        if (y - 3 + i >= 0) { console.gotoXY(x, y - 3 + i);     cout << u8"▒▒▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▒▒▒▒▒"; }
        if (y - 2 + i >= 0) { console.gotoXY(x, y - 2 + i);     cout << u8"▒▒▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▒▒▒▒▒"; }
        if (y - 1 + i >= 0) { console.gotoXY(x, y - 1 + i);     cout << u8"▒▒▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▒▒▒▒▒"; }
        if (y  + i >= 0) { console.gotoXY(x, y + i);     cout << u8"██████████████████████████████████████"; }
        if (y +1 + i >= 0) { console.gotoXY(x, y + 1 + i); cout << u8"█                                    █"; }
        if (y +2 + i >= 0) { console.gotoXY(x, y + 2 + i); cout << u8"█                                    █"; }
        if (y +3 + i >= 0) { console.gotoXY(x, y + 3 + i); cout << u8"█                                    █"; }
        if (y +4 + i >= 0) { console.gotoXY(x, y + 4 + i); cout << u8"█    ███████╗ ███╗   ██╗ ██████╗     █"; }
        if (y +5 + i >= 0) { console.gotoXY(x, y + 5 + i); cout << u8"█    ██╔════╝ ████╗  ██║ ██╔══██╗    █"; }
        if (y +6 + i >= 0) { console.gotoXY(x, y + 6 + i); cout << u8"█    █████╗   ██╔██╗ ██║ ██║  ██║    █"; }
        if (y +7 + i >= 0) { console.gotoXY(x, y + 7 + i); cout << u8"█    ██╔══╝   ██║╚██╗██║ ██║  ██║    █"; }
        if (y +8 + i >= 0) { console.gotoXY(x, y + 8 + i); cout << u8"█    ███████╗ ██║ ╚████║ ██████╔╝    █"; }
        if (y +9 + i >= 0) { console.gotoXY(x, y + 9 + i); cout << u8"█    ╚══════╝ ╚═╝  ╚═══╝ ╚═════╝     █"; }
        if (y +10 + i >= 0) { console.gotoXY(x, y + 10 + i); cout << u8"█                                    █"; }
        if (y +11 + i >= 0) { console.gotoXY(x, y + 11 + i); cout << u8"█                                    █"; }
        if (y +12 + i >= 0) { console.gotoXY(x, y + 12 + i); cout << u8"█                                    █"; }
        if (y +13 + i >= 0) { console.gotoXY(x, y + 13 + i); cout << u8"██████████████████████████████████████"; }
        Sleep(50);
    }
    console.gotoXY(0, HEIGHT_SCREEN_MENU + 1);
}
void cEnd::runEnd()
{
    drawBackGround();
    PlaySound(TEXT("sounds\\end.wav"), NULL, SND_LOOP | SND_ASYNC);
    drawCloud(5, 2);
    drawCloud(90, 5);
    drawCloud(5, 29);
    drawCloud(90, 30);
    drawCurtain();
    drawTextEnd();
}
