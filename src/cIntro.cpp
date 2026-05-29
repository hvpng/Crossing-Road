#include "cIntro.h"
void cIntro::draw(int x, int y, int color, char character)
{
    cConsole console;
    console.gotoXY(x, y);
    console.textColor(color);
    cout << character;
    console.textColor(7);
}
void cIntro::drawBackGround()
{
    cConsole c;
    c.textColor(187);
    int d = 0, gt = 1;
    int hang = WIDTH_SCREEN_MENU - 1, cot = HEIGHT_SCREEN_MENU - 1;
    while (gt <= WIDTH_SCREEN_MENU * HEIGHT_SCREEN_MENU) {
        for (int i = d; i <= cot; i++) {
            gt++;
            c.gotoXY(d, i);
            cout << " ";
        }
        Sleep(10);
        for (int i = d + 1; i <= hang; i++) {
            gt++;
            c.gotoXY(i, cot);
            cout << " ";
        }
        Sleep(10);
        for (int i = cot - 1; i >= d && gt <= WIDTH_SCREEN_MENU * HEIGHT_SCREEN_MENU; i--) {
            gt++;
            c.gotoXY(hang, i);
            cout << " ";
        }
        Sleep(10);
        for (int i = hang - 1; i > d && gt <= WIDTH_SCREEN_MENU * HEIGHT_SCREEN_MENU; i--) {
            gt++;
            c.gotoXY(i, d);
            cout << " ";
        }
        Sleep(10);
        d++; hang--; cot--;     
    }
    // to mau: dat
    for (int i = HEIGHT_SCREEN_MENU - 3; i < HEIGHT_SCREEN_MENU; i++)
    {
        for (int j = 0; j < WIDTH_SCREEN_MENU; j++)
        {
            draw(j, i, 204, ' ');
        }
        Sleep(10);
    }
}
void cIntro::drawAlphabet()
{
    cConsole c;
    int x = 23;
    int y = 10;
    c.textColor(176);
    SetConsoleOutputCP(CP_UTF8);
    for (int i = 0; i < y; i++)
    {
        c.gotoXY(x, i);   cout << u8"         ";
        c.gotoXY(x, i+1); cout << u8"  ██████╗";
        c.gotoXY(x, i+2); cout << u8" ██╔════╝";
        c.gotoXY(x, i+3); cout << u8" ██║     ";
        c.gotoXY(x, i+4); cout << u8" ██║     ";
        c.gotoXY(x, i+5); cout << u8" ╚██████╗";
        c.gotoXY(x, i+6); cout << u8"  ╚═════╝";
        Sleep(10);
    }

    for (int i = 0; i < y; i++)
    {
        c.gotoXY(x+10, i);   cout << u8"         ";
        c.gotoXY(x+10, i+1); cout << u8" ██████╗ ";
        c.gotoXY(x+10, i+2); cout << u8" ██╔══██╗";
        c.gotoXY(x+10, i+3); cout << u8" ██████╔╝";
        c.gotoXY(x+10, i+4); cout << u8" ██╔══██╗";
        c.gotoXY(x+10, i+5); cout << u8" ██║  ██║";
        c.gotoXY(x+10, i+6); cout << u8" ╚═╝  ╚═╝";
        Sleep(10);
    }

    for (int i = 0; i < y; i++)
    {
        c.gotoXY(x + 19, i);   cout << u8"          ";
        c.gotoXY(x + 19, i+1); cout << u8"  ██████╗ ";
        c.gotoXY(x + 19, i+2); cout << u8" ██╔═══██╗";
        c.gotoXY(x + 19, i+3); cout << u8" ██║   ██║";
        c.gotoXY(x + 19, i+4); cout << u8" ██║   ██║";
        c.gotoXY(x + 19, i+5); cout << u8" ╚██████╔╝";
        c.gotoXY(x + 19, i+6); cout << u8"  ╚═════╝ ";
        Sleep(10);
    }

    for (int i = 0; i < y; i++)
    {
        c.gotoXY(x + 29, i);   cout << u8"         ";
        c.gotoXY(x + 29, i+1); cout << u8" ███████╗";
        c.gotoXY(x + 29, i+2); cout << u8" ██╔════╝";
        c.gotoXY(x + 29, i+3); cout << u8" ███████╗";
        c.gotoXY(x + 29, i+4); cout << u8" ╚════██║";
        c.gotoXY(x + 29, i+5); cout << u8" ███████║";
        c.gotoXY(x + 29, i+6); cout << u8" ╚══════╝";
        Sleep(10);
    }

    for (int i = 0; i < y; i++)
    {
        c.gotoXY(x + 38, i);     cout << u8"         ";
        c.gotoXY(x + 38, i + 1); cout << u8" ███████╗";
        c.gotoXY(x + 38, i + 2); cout << u8" ██╔════╝";
        c.gotoXY(x + 38, i + 3); cout << u8" ███████╗";
        c.gotoXY(x + 38, i + 4); cout << u8" ╚════██║";
        c.gotoXY(x + 38, i + 5); cout << u8" ███████║";
        c.gotoXY(x + 38, i + 6); cout << u8" ╚══════╝";
        Sleep(10);
    }

    for (int i = 0; i < y; i++)
    {
        c.gotoXY(x + 47, i);   cout << u8"    ";
        c.gotoXY(x + 47, i+1); cout << u8" ██╗";
        c.gotoXY(x + 47, i+2); cout << u8" ██║";
        c.gotoXY(x + 47, i+3); cout << u8" ██║";
        c.gotoXY(x + 47, i+4); cout << u8" ██║";
        c.gotoXY(x + 47, i+5); cout << u8" ██║";
        c.gotoXY(x + 47, i+6); cout << u8" ╚═╝";
        Sleep(10);
    }

    for (int i = 0; i < y; i++)
    {
        c.gotoXY(x + 51, i);   cout << u8"           ";
        c.gotoXY(x + 51, i+1); cout << u8" ███╗   ██╗";
        c.gotoXY(x + 51, i+2); cout << u8" ████╗  ██║";
        c.gotoXY(x + 51, i+3); cout << u8" ██╔██╗ ██║";
        c.gotoXY(x + 51, i+4); cout << u8" ██║╚██╗██║";
        c.gotoXY(x + 51, i+5); cout << u8" ██║ ╚████║";
        c.gotoXY(x + 51, i+6); cout << u8" ╚═╝  ╚═══╝";
        Sleep(10);
    }

    for (int i = 0; i < y; i++)
    {
        c.gotoXY(x + 62, i);   cout << u8"          ";
        c.gotoXY(x + 62, i+1); cout << u8"  ██████╗ ";
        c.gotoXY(x + 62, i+2); cout << u8" ██╔════╝ ";
        c.gotoXY(x + 62, i+3); cout << u8" ██║  ███╗";
        c.gotoXY(x + 62, i+4); cout << u8" ██║   ██║";
        c.gotoXY(x + 62, i+5); cout << u8" ╚██████╔╝";
        c.gotoXY(x + 62, i+6); cout << u8"  ╚═════╝ ";
        Sleep(10);
    }

    c.textColor(176);
    int x1 = 60;
    int y1 = HEIGHT_SCREEN_MENU - 10;
    for (int i = 0; i < 13; i++)
    {
        c.gotoXY(x1, y1  -i);     cout << u8"██████╗   ██████╗              ██████╗ ";
        c.gotoXY(x1, y1 - i + 1); cout << u8"██╔══██╗ ██╔═══██╗             ██╔══██╗";
        c.gotoXY(x1, y1 - i + 2); cout << u8"██████╔╝ ██║   ██║             ██║  ██║";
        c.gotoXY(x1, y1 - i + 3); cout << u8"██╔══██╗ ██║   ██║             ██║  ██║";
        c.gotoXY(x1, y1 - i + 4); cout << u8"██║  ██║ ╚██████╔╝             ██████╔╝";
        c.gotoXY(x1, y1 - i + 5); cout << u8"╚═╝  ╚═╝  ╚═════╝              ╚═════╝ ";
        c.gotoXY(x1, y1 - i+6);   cout << u8"                                       ";
        Sleep(50);
    }

    int y2 = HEIGHT_SCREEN_MENU - 10;
    for (int i = 0; i < 79; i++)
    {
        c.gotoXY(i, y2);     cout << u8"   ███████  ";
        c.gotoXY(i, y2 + 1); cout << u8"   ███████  ";
        c.gotoXY(i, y2 + 2); cout << u8"   █     █  ";
        c.gotoXY(i, y2 + 3); cout << u8" ███████████";
        c.gotoXY(i, y2 + 4); cout << u8"   ███████  ";
        c.gotoXY(i, y2 + 5); cout << u8"   █     █  ";
        c.gotoXY(i, y2 + 6); cout << u8"            ";
        Sleep(10);
        if (i < 78) {
            c.gotoXY(i, y2 + 1); cout << " ";
            c.gotoXY(i, y2 + 2); cout << " ";
            c.gotoXY(i, y2);     cout << " ";
            c.gotoXY(i, y2 + 3); cout << " ";
            c.gotoXY(i, y2 + 4); cout << " ";
            c.gotoXY(i, y2 + 5); cout << " ";
            c.gotoXY(i, y2 + 6); cout << " ";
        }
    }

    for (int i = 0; i < 13; i++)
    {
        c.gotoXY(78, y2 - i);     cout << u8"   ███████  ";
        c.gotoXY(78, y2 - i + 1); cout << u8"   ███████  ";
        c.gotoXY(78, y2 - i + 2); cout << u8"   █     █  ";
        c.gotoXY(78, y2 - i + 3); cout << u8" ███████████";
        c.gotoXY(78, y2 - i + 4); cout << u8"   ███████  ";
        c.gotoXY(78, y2 - i + 5); cout << u8"   █     █  ";
        c.gotoXY(78, y2 - i + 6); cout << u8"            ";
        Sleep(100);
    }
    Sleep(150);
}
void cIntro::runIntro()
{
    drawBackGround();
    drawAlphabet();
}