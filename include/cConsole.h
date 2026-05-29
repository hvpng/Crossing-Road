//﻿#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <conio.h>
#include <io.h>
#include <fcntl.h>
#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <thread>
#include <mmsystem.h>
#include <io.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#define ENTER '\r'
#define BACKSPACE 8
using namespace std;
class cConsole
{
    bool showFlag;//Biến nhận biết nên hiện hay tắt con trỏ nhấp nháy
    int width;//Chiều rộng console
    int height;//Chiều dài console
public:
    int inputName(string& s, int x, int y);
    void checkNumber(char number, int startX, int startY, int color);
    void ShowConsoleCursor();//Thực hiện chức năng tắt hoặc mở cont trỏ nhấp nháy
    void resizeConsole();//Chỉnh sửa kích thước console
    void FixConsoleWindow();//Cố định console
    void assignWidth(int);//Gán chiều rộng console
    void assignHeight(int);//Gán chiều cao console
    void assignFlag(bool);//Gán cờ tắt hoặc mở
    void textColor(int color);
    void gotoXY(int x, int y);
    void Draw(int x, int y, char str, int color);
};

