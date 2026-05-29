#include "cConsole.h"
void cConsole::ShowConsoleCursor() {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}
void cConsole::resizeConsole()
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void cConsole::FixConsoleWindow() {
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void cConsole::assignWidth(int w)
{
    width = w;
}
void cConsole::assignHeight(int h)
{
    height = h;
}
void cConsole::assignFlag(bool f)
{
    showFlag = f;
}
void cConsole::textColor(int code)
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, code);
}
void cConsole::gotoXY(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void cConsole::Draw(int x, int y, char str, int color) {
    gotoXY(x, y);
    textColor(color);
    cout << str;
    textColor(7);
}
void cConsole::checkNumber(char number, int startX, int startY, int color)
{
    cConsole c;
    SetConsoleOutputCP(CP_UTF8);
    c.textColor(color);
    if (number == '0')
    {
        c.gotoXY(startX, startY);      cout << u8" █████╗ ";
        c.gotoXY(startX, startY + 1);  cout << u8"██╔══██╗";
        c.gotoXY(startX, startY + 2);  cout << u8"██║  ██║";
        c.gotoXY(startX, startY + 3);  cout << u8"██║  ██║";
        c.gotoXY(startX, startY + 4);  cout << u8"╚█████╔╝";
        c.gotoXY(startX, startY + 5);  cout << u8" ╚════╝ ";
    }
    else if (number == '1')
    {
        c.gotoXY(startX, startY);      cout << u8"  ███╗  ";
        c.gotoXY(startX, startY + 1);  cout << u8" ████║  ";
        c.gotoXY(startX, startY + 2);  cout << u8"██╔██║  ";
        c.gotoXY(startX, startY + 3);  cout << u8"╚═╝██║  ";
        c.gotoXY(startX, startY + 4);  cout << u8"███████╗";
        c.gotoXY(startX, startY + 5);  cout << u8"╚══════╝";
    }
    else if (number == '2')
    {
        c.gotoXY(startX, startY);      cout << u8"██████╗ ";
        c.gotoXY(startX, startY + 1);  cout << u8"╚════██╗";
        c.gotoXY(startX, startY + 2);  cout << u8"  ███╔═╝";
        c.gotoXY(startX, startY + 3);  cout << u8"██╔══╝  ";
        c.gotoXY(startX, startY + 4);  cout << u8"███████╗";
        c.gotoXY(startX, startY + 5);  cout << u8"╚══════╝";
    }
    else if (number == '3')
    {
        c.gotoXY(startX, startY);      cout << u8"██████╗ ";
        c.gotoXY(startX, startY + 1);  cout << u8"╚════██╗";
        c.gotoXY(startX, startY + 2);  cout << u8" █████╔╝";
        c.gotoXY(startX, startY + 3);  cout << u8" ╚═══██╗";
        c.gotoXY(startX, startY + 4);  cout << u8"██████╔╝";
        c.gotoXY(startX, startY + 5);  cout << u8"╚═════╝ ";
    }
    else if (number == '4')
    {
        c.gotoXY(startX, startY);      cout << u8"  ██╗██╗";
        c.gotoXY(startX, startY + 1);  cout << u8" ██╔╝██║";
        c.gotoXY(startX, startY + 2);  cout << u8"██╔╝░██║";
        c.gotoXY(startX, startY + 3);  cout << u8"███████║";
        c.gotoXY(startX, startY + 4);  cout << u8"╚════██║";
        c.gotoXY(startX, startY + 5);  cout << u8"     ╚═╝";
    }
    else if (number == '5')
    {
        c.gotoXY(startX, startY);      cout << u8"███████╗";
        c.gotoXY(startX, startY + 1);  cout << u8"██╔════╝";
        c.gotoXY(startX, startY + 2);  cout << u8"██████╗ ";
        c.gotoXY(startX, startY + 3);  cout << u8"╚════██╗";
        c.gotoXY(startX, startY + 4);  cout << u8"██████╔╝";
        c.gotoXY(startX, startY + 5);  cout << u8"╚═════╝ ";
    }
    else if (number == '6')
    {
        c.gotoXY(startX, startY);      cout << u8" █████╗ ";
        c.gotoXY(startX, startY + 1);  cout << u8"██╔═══╝ ";
        c.gotoXY(startX, startY + 2);  cout << u8"██████╗ ";
        c.gotoXY(startX, startY + 3);  cout << u8"██╔══██╗";
        c.gotoXY(startX, startY + 4);  cout << u8"╚█████╔╝";
        c.gotoXY(startX, startY + 5);  cout << u8" ╚════╝ ";
    }
    else if (number == '7')
    {
        c.gotoXY(startX, startY);      cout << u8"███████╗";
        c.gotoXY(startX, startY + 1);  cout << u8"╚════██║";
        c.gotoXY(startX, startY + 2);  cout << u8"    ██╔╝";
        c.gotoXY(startX, startY + 3);  cout << u8"   ██╔╝ ";
        c.gotoXY(startX, startY + 4);  cout << u8"  ██╔╝  ";
        c.gotoXY(startX, startY + 5);  cout << u8"  ╚═╝   ";
    }
    else if (number == '8')
    {
        c.gotoXY(startX, startY);      cout << u8" █████╗ ";
        c.gotoXY(startX, startY + 1);  cout << u8"██╔══██╗";
        c.gotoXY(startX, startY + 2);  cout << u8"╚█████╔╝";
        c.gotoXY(startX, startY + 3);  cout << u8"██╔══██╗";
        c.gotoXY(startX, startY + 4);  cout << u8"╚█████╔╝";
        c.gotoXY(startX, startY + 5);  cout << u8" ╚════╝ ";
    }
    else if (number == '9')
    {
        c.gotoXY(startX, startY);      cout << u8" █████╗ ";
        c.gotoXY(startX, startY + 1);  cout << u8"██╔══██╗";
        c.gotoXY(startX, startY + 2);  cout << u8"╚██████║";
        c.gotoXY(startX, startY + 3);  cout << u8" ╚═══██║";
        c.gotoXY(startX, startY + 4);  cout << u8" █████╔╝";
        c.gotoXY(startX, startY + 5);  cout << u8" ╚════╝ ";
    }
    c.textColor(15);
    SetConsoleOutputCP(437);
}
int cConsole::inputName(string& s, int x, int y) {
    int i = 0;
    s = "";
    char c;
    while (1) {
        c = _getch();
        if (c == ENTER) {
            return 0;
        }
        else if (c == BACKSPACE && i > 0) {
            i--;
            textColor(228);
            gotoXY(x + i, y); cout << " ";
            s.pop_back();
        }
        else if ((c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9') && s.size() < 14) {
            textColor(228);
            gotoXY(x + i, y);  cout << c;
            s += c;
            i++;
        }
    }
}