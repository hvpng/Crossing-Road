#include "cLoad_HighScore.h"
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string cLoad_HighScore::getPlayerName() {
    return this->playerName;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int cLoad_HighScore::getLevel() {
    return this->level;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int cLoad_HighScore::getScore() {
    return this->Score;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void cLoad_HighScore::setdata(string name, int flevel, int Sscore) {
    this->playerName = name;
    this->level = flevel;
    this->Score = Sscore;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void cLoad_HighScore::datatoFileforHighScore(string fileName) {
    ofstream dataPlayer;
    dataPlayer.open(fileName, fstream::out | fstream::app);
    if (dataPlayer.fail()) {
        return;
    }
    dataPlayer << playerName;
    dataPlayer << ";";
    dataPlayer << level;
    dataPlayer << ";";
    dataPlayer << Score;
    dataPlayer.close();
    vector <cLoad_HighScore> list = this->datafromFile(fileName);
    for (int i = 0; i < list.size() - 1; i++) {
        for (int j = i + 1; j < list.size(); j++) {
            if (list[i].Score < list[j].Score) {
                swap(list[i], list[j]);
            }
        }
    }
    ofstream listdata;
    listdata.open(fileName, fstream::out);
    if (listdata.fail()) {
        return;
    }
    for (int i = 0; i < list.size(); i++) {
        listdata << list[i].playerName << ";" << list[i].level << ";" << list[i].Score << "\n";
    }
    listdata.close();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void cLoad_HighScore::datatoFileforLoad(string fileName) {
    ofstream dataPlayer;
    dataPlayer.open(fileName, fstream::out | fstream::app);
    if (dataPlayer.fail()) {
        return;
    }
    dataPlayer << playerName;
    dataPlayer << ";";
    dataPlayer << level;
    dataPlayer << ";";
    dataPlayer << Score << endl;
    dataPlayer.close();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void cLoad_HighScore::datatoFilewhenDelete(string fileName, vector<cLoad_HighScore> user) {
    ofstream dataPlayer;
    dataPlayer.open(fileName, fstream::out);
    if (dataPlayer.fail()) {
        return;
    }
    for (int i = 0; i < user.size(); i++)
    {
        dataPlayer << user[i].playerName;
        dataPlayer << ";";
        dataPlayer << user[i].level;
        dataPlayer << ";";
        dataPlayer << user[i].Score << endl;
    }
    dataPlayer.close();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void cLoad_HighScore::readData(const string line_inf) {
    stringstream V(line_inf);
    string temp;
    getline(V, this->playerName, ';');
    getline(V, temp, ';');
    int a = stoi(temp);
    this->level = a;
    getline(V, temp);
    a = stoi(temp);
    this->Score = a;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<cLoad_HighScore> cLoad_HighScore::datafromFile(string fileName) {
    fstream dataPlayer;
    vector<cLoad_HighScore> listdata;
    dataPlayer.open(fileName, fstream::in);
    if (dataPlayer.fail()) {
        return listdata;
    }
    string temp;
    cLoad_HighScore a;
    while (!dataPlayer.eof())
    {
        getline(dataPlayer, temp);
        if (temp != "") {
            a.readData(temp);
            listdata.push_back(a);
        }
    }
    dataPlayer.close();
    return listdata;
}

bool cLoad_HighScore::getStatus()
{
    return this->status;
}
////////////////////////////////////////////////////////////////////////////////////////////
void cLoad_HighScore::processLoadMenu(int& level, int& score) {
    background();
    int pointer = 0; // Thực hiện chức năng lên xuống mũi tên trong phần load game
    //đọc file ra và đảo từ đầu đến cuối để player mới ở trên player cũ ở dưới
    vector<cLoad_HighScore> list = this->datafromFile("load.txt");
    reverse(list.begin(), list.end());
    cConsole c;
    // Hiện danh sách cần load và con trỏ lên xuống
    int temp = 0; // Tô màu file chọn
    int count = 0;// Đếm file cần xuất ra màn hình
    int delPos = 0; // vị trí xóa
    while (temp != 13)
    {
        if (list.size() == 0)
        {
            checkListSizeZero(47, 15, 244);

        }
        if (temp == 'Q')
        {
            this->status = false;
            return;
        }
        if (temp == 80)
        {
            pointer++;
            delPos++;
            if (delPos == list.size()) delPos = 0;
        }
        if (temp == 72)
        {
            pointer--;
            delPos--;
            if (delPos == -1) delPos = list.size() - 1;
        }
        //Phần mới add vào
        if (list.size() < 8)
        {
            if (pointer == list.size())
            {
                count = 0;
                pointer = 0;
            }
            if (pointer == -1)
            {
                count = 0;
                pointer = list.size() - 1;
            }
        }
        else {
            if (pointer == 8)
            {
                if (count == list.size() - 8)
                {
                    count = 0;
                    pointer = 0;
                }
                else
                {
                    count++;
                    pointer = 7;
                }
            }
            if (pointer == -1)
            {
                if (count == 0)
                {
                    count = list.size() - 8;
                    pointer = 7;
                }
                else
                {
                    count--;
                    pointer = 0;
                }
            }
        }
        if (temp == 'D' && list.size() != 0)
        {
            list.erase(list.begin() + delPos); // xoa su dung phim d
            background();
            pointer = 0;
            count = 0;
        }
        if (list.size() < 8)
        {
            // chỉnh sửa nếu số lượng phần tử nhỏ hơn 8
            for (int i = 0; i < list.size(); i++)
            {
                if (pointer == (i - count))  c.textColor(226);
                else   c.textColor(240);
                c.gotoXY(42, 11 + (i - count) * 3);
                cout << "                                     ";
                c.gotoXY(45, 11 + (i - count) * 3);
                cout << i + 1 << ". " << list[i].getPlayerName();
                c.textColor(15);
            }
        }
        else {
            for (int i = count; i < list.size() && i < count + 8; i++)
            {
                if (pointer == (i - count))  c.textColor(226);
                else   c.textColor(240);
                c.gotoXY(42, 11 + (i - count) * 3);
                cout << "                                     ";
                c.gotoXY(45, 11 + (i - count) * 3);
                cout << i + 1 << ". " << list[i].getPlayerName();
                c.textColor(15);
            }
        }
        this->datatoFilewhenDelete("load.txt", list);
        temp = toupper(_getch());
    }
    level = list[pointer].getLevel();
    score = list[pointer].getScore();
    c.textColor(15);
}
void cLoad_HighScore::processLoadinGame(int& level, int& score) {
    baseBackground(25, 6, 50, 28, 0);
    int pointer = 0; // Thực hiện chức năng lên xuống mũi tên trong phần load game
    //đọc file ra và đảo từ đầu đến cuối để player mới ở trên player cũ ở dưới
    vector<cLoad_HighScore> list = this->datafromFile("load.txt");
    reverse(list.begin(), list.end());
    cConsole c;
    // Hiện danh sách cần load và con trỏ lên xuống
    int temp = 0; // Tô màu file chọn
    int count = 0;// Đếm file cần xuất ra màn hình
    int delPos = 0;
    while (temp != 13)
    {
        if (list.size() == 0)
        {
            checkListSizeZero(37, 14, 228);
        }
        if (temp == 80)
        {
            pointer++;
            delPos++;
            if (delPos == list.size()) delPos = 0;
        }
        if (temp == 72)
        {
            pointer--;
            delPos--;
            if (delPos == -1) delPos = list.size() - 1;
        }
        //Phần mới add vào
        if (list.size() < 8)
        {
            if (pointer == list.size())
            {
                count = 0;
                pointer = 0;
            }
            if (pointer == -1)
            {
                count = 0;
                pointer = list.size() - 1;
            }
        }
        else {
            if (pointer == 8)
            {
                if (count == list.size() - 8)
                {
                    count = 0;
                    pointer = 0;
                }
                else
                {
                    count++;
                    pointer = 7;
                }
            }
            if (pointer == -1)
            {
                if (count == 0)
                {
                    count = list.size() - 8;
                    pointer = 7;
                }
                else
                {
                    count--;
                    pointer = 0;
                }
            }
        }
        if (temp == 'D' && list.size() != 0)
        {
            list.erase(list.begin() + delPos); // xoa su dung phim d
            baseBackground(25, 6, 50, 28, 0);
            count = 0;
            pointer = 0;
            // lỗi khi xóa phần tử lớn hơn 8
        }
        if (list.size() < 8)
        {
            // chỉnh sửa nếu số lượng phần tử nhỏ hơn 8
            for (int i = 0; i < list.size(); i++)
            {
                if (pointer == (i - count))  c.textColor(244);
                else   c.textColor(226);
                c.gotoXY(32, 11 + (i - count) * 3);
                cout << "                                    ";
                c.gotoXY(35, 11 + (i - count) * 3);
                cout << i + 1 << ". " << list[i].getPlayerName();
                c.textColor(15);
            }
        }
        else {
            for (int i = count; i < list.size() && i < count + 8; i++)
            {
                if (pointer == (i - count))  c.textColor(244);
                else   c.textColor(226);
                c.gotoXY(32, 11 + (i - count) * 3);
                cout << "                                    ";
                c.gotoXY(35, 11 + (i - count) * 3);
                cout << i + 1 << ". " << list[i].getPlayerName();
                c.textColor(15);
            }
        }
        this->datatoFilewhenDelete("load.txt", list);
        temp = toupper(_getch());
    }
    level = list[pointer].getLevel();
    score = list[pointer].getScore();
    c.textColor(15);
}
string cLoad_HighScore::processSave(int level, int score) {
    cConsole c;
    string name;
    baseBackground(102, 25, 46, 14, 1);
    c.textColor(226);
    c.gotoXY(108, 30);
    cout << "Input you name: ";
    frameInputName(108, 32, 30, 2, 226);
    c.gotoXY(109, 33);
    c.textColor(228);
    c.assignFlag(true);
    c.ShowConsoleCursor();
    c.inputName(name, 109, 33);
    c.assignFlag(false);
    c.ShowConsoleCursor();
    this->setdata(name, level, score);
    this->datatoFileforLoad("load.txt");
    c.textColor(15);
    return name;
}

// Mani
void cLoad_HighScore::baseBackground(int color)
{
    cConsole console;
    for (int i = 0; i < HEIGHT_SCREEN; i++)
    {
        for (int j = 0; j < WIDTH_SCREEN; j++)
        {
            console.Draw(j, i, ' ', color);
        }
    }
}
void cLoad_HighScore::frameName(int startX, int startY)
{
    cConsole console;
    // Khung nen duoi
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 45; j++)
        {
            console.Draw(j + startX, i + startY, ' ', 175);
        }
    }
    // Lam dam phan duoi
    for (int i = 0; i < 45; i++)
    {
        console.Draw(i + startX, startY + 4, 223, 242);
    }
    // Chu
    SetConsoleOutputCP(CP_UTF8);
    console.gotoXY(startX + 5, startY + 1);
    console.textColor(175);
    cout << u8"█   █▀█ ▄▀█ █▀▄   █▀▀ ▄▀█ █▀▄▀█ █▀▀";
    console.gotoXY(startX + 5, startY + 2);
    console.textColor(175);
    cout << u8"█▄▄ █▄█ █▀█ █▄▀   █▄█ █▀█ █ ▀ █ ██▄";
    console.textColor(15);
    SetConsoleOutputCP(437);
}
void cLoad_HighScore::baseFramName(int startX, int startY, int width, int height)
{
    cConsole console;
    // To hang dau
    for (int i = 0; i < width - 4; i++)
    {
        console.Draw(i + startX + 2, startY, 220, 239);
    }
    // To hang hai
    for (int i = 0; i < width; i++)
    {
        if (i == 0 || i == width - 1)
        {
            console.Draw(i + startX, startY + 1, 220, 239);
        }
        else
        {
            console.Draw(i + startX, startY + 1, 219, 239);
        }
    }
    // To hang cuoi
    for (int i = 0; i < width - 4; i++)
    {
        console.Draw(i + startX + 2, startY + height - 1, 223, 239);
    }
    // To hang cuoi nhi
    for (int i = 0; i < width; i++)
    {
        if (i == 0 || i == width - 1)
        {
            console.Draw(i + startX, startY + height - 2, 223, 239);
        }
        else
        {
            console.Draw(i + startX, startY + height - 2, 219, 239);
        }
    }
    // To phan con lai
    for (int i = 0; i < height - 4; i++)
    {
        for (int j = 0; j < width; j++)
        {
            console.Draw(j + startX, i + startY + 2, 219, 239);
        }
    }
    SetConsoleOutputCP(CP_UTF8);
    console.textColor(244);
    console.gotoXY(40, height - 2);
    cout << "Nhan Q: Tro lai Menu ";
    console.gotoXY(62, height - 2);
    cout << "|  Nhan D: Xoa file ";
    console.textColor(15);
    SetConsoleOutputCP(437);
}
void cLoad_HighScore::background()
{
    cConsole console;
    // Nen vang
    baseBackground(238);
    // Khung nen trang
    baseFramName(38, 1, 45, 38);
    // Khung ten leaderboard
    frameName(38, 3);
}

// UI load game in game
void cLoad_HighScore::baseBackground(int startX, int startY, int width, int height, int menu)
{
    cConsole console;
    // in man hinh vang
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            console.Draw(j + startX, i + startY, ' ', 239);
        }
    }
    // in chu
    if (menu == 0) // khung load game
    {
        SetConsoleOutputCP(CP_UTF8);
        console.gotoXY(startX + 8, startY + 1);
        console.textColor(226);
        cout << u8"█   █▀█ ▄▀█ █▀▄   █▀▀ ▄▀█ █▀▄▀█ █▀▀";
        console.gotoXY(startX + 8, startY + 2);
        cout << u8"█▄▄ █▄█ █▀█ █▄▀   █▄█ █▀█ █ ▀ █ ██▄";
        console.textColor(15);
        SetConsoleOutputCP(437);
    }
    else if (menu == 1) // khung save game
    {
        SetConsoleOutputCP(CP_UTF8);
        console.gotoXY(startX + 6, startY + 1);
        console.textColor(226);
        cout << u8"█▀ ▄▀█ █ █ █▀▀   █▀▀ ▄▀█ █▀▄▀█ █▀▀";
        console.gotoXY(startX + 6, startY + 2);
        cout << u8"▄█ █▀█ ▀▄▀ ██▄   █▄█ █▀█ █ ▀ █ ██▄";
        console.textColor(15);
        SetConsoleOutputCP(437);
    }
    //█▀█ █░░ ▄▀█ █▄█   ▄▀█ █▀▀ ▄▀█ █ █▄░█ ▀█
    //█▀▀ █▄▄ █▀█ ░█░   █▀█ █▄█ █▀█ █ █░▀█ ░▄
    else if (menu == 2)// khung hoi co choi tiep khong
    {
        SetConsoleOutputCP(CP_UTF8);
        console.textColor(226);
        console.gotoXY(startX + 2, startY + 1);
        cout << u8"█▀█ █   ▄▀█ █▄█   ▄▀█ █▀▀ ▄▀█ █ █▄ █ ▀█";
        console.gotoXY(startX + 2, startY + 2);
        cout << u8"█▀▀ █▄▄ █▀█  █    █▀█ █▄█ █▀█ █ █ ▀█  ▄";
        console.gotoXY(35, 22);
        cout << "Continue(Y)";
        console.gotoXY(58, 22);
        cout << "End(N)";
        SetConsoleOutputCP(437);
    }

    //█▀ ▄▀█ █ █ █▀▀   █▀▀ ▄▀█ █▀▄▀█ █▀▀ ▀█
    //▄█ █▀█ ▀▄▀ ██▄   █▄█ █▀█ █ ▀ █ ██▄  ▄
    else if (menu == 3)
    {
        SetConsoleOutputCP(CP_UTF8);
        console.textColor(226);
        console.gotoXY(startX + 2, startY + 1);
        cout << u8" █▀ ▄▀█ █ █ █▀▀   █▀▀ ▄▀█ █▀▄▀█ █▀▀ ▀█";
        console.gotoXY(startX + 2, startY + 2);
        cout << u8" ▄█ █▀█ ▀▄▀ ██▄   █▄█ █▀█ █ ▀ █ ██▄  ▄";
        console.gotoXY(38, 22);
        cout << "Yes(Y)";
        console.gotoXY(58, 22);
        cout << "No(Q)";
        SetConsoleOutputCP(437);
    }
    //█ █▄░█ █▀█ █░█ ▀█▀   █▄░█ ▄▀█ █▀▄▀█ █▀▀ ▀
    //█ █░▀█ █▀▀ █▄█ ░█░   █░▀█ █▀█ █░▀░█ ██▄ ▄
    else if (menu == 4) {
        SetConsoleOutputCP(CP_UTF8);
        console.textColor(226);
        console.gotoXY(startX + 1, startY + 1);
        cout << u8"█ █▄ █ █▀█ █ █ ▀█▀   █▄ █ ▄▀█ █▀▄▀█ █▀▀ ";
        console.gotoXY(startX + 1, startY + 2);
        cout << u8"█ █ ▀█ █▀▀ █▄█  █    █ ▀█ █▀█ █ ▀ █ ██▄ ";
        SetConsoleOutputCP(437);
        console.textColor(226);
        frameInputName(30, 21, 40, 2, 226);
    }
}
void cLoad_HighScore::checkListSizeZero(int startX, int startY, int color)
{
    cConsole console;
    SetConsoleOutputCP(CP_UTF8);
    // No: chieu rong: 17, chieu dai 5 9 | 8
    console.gotoXY(startX + 5, startY);
    console.textColor(color);
    cout << u8"███╗  ██╗ █████╗ ";
    console.gotoXY(startX + 5, startY + 1);
    console.textColor(color);
    cout << u8"████╗ ██║██╔══██╗";
    console.gotoXY(startX + 5, startY + 2);
    console.textColor(color);
    cout << u8"██╔██╗██║██║  ██║";
    console.gotoXY(startX + 5, startY + 3);
    console.textColor(color);
    cout << u8"██║╚████║██║  ██║";
    console.gotoXY(startX + 5, startY + 4);
    console.textColor(color);
    cout << u8"██║ ╚███║╚█████╔╝";
    console.gotoXY(startX + 5, startY + 5);
    console.textColor(color);
    cout << u8"╚═╝  ╚══╝ ╚════╝ ";
    // File: chieu rong: 27, chieu dai: 5 14 | 13
    console.gotoXY(startX, startY + 6);
    console.textColor(color);
    cout << u8"███████╗██╗██╗     ███████╗";
    console.gotoXY(startX, startY + 7);
    console.textColor(color);
    cout << u8"██╔════╝██║██║     ██╔════╝";
    console.gotoXY(startX, startY + 8);
    console.textColor(color);
    cout << u8"█████╗  ██║██║     █████╗  ";
    console.gotoXY(startX, startY + 9);
    console.textColor(color);
    cout << u8"██╔══╝  ██║██║     ██╔══╝  ";
    console.gotoXY(startX, startY + 10);
    console.textColor(color);
    cout << u8"██║     ██║███████╗███████╗";
    console.gotoXY(startX, startY + 11);
    console.textColor(color);
    cout << u8"╚═╝     ╚═╝╚══════╝╚══════╝";
    console.textColor(15);
    SetConsoleOutputCP(437);
}
void cLoad_HighScore::frameInputName(int startX, int startY, int width, int height, int color)
{
    cConsole console;
    // In ra 4 goc
    // Goc trai - tren
    console.Draw(startX, startY, 201, color);
    // Goc phai tren
    console.Draw(startX + width, startY, 187, color);
    // Goc trai - duoi
    console.Draw(startX, startY + height, 200, color);
    // Goc phai - duoi
    console.Draw(startX + width, startY + height, 188, color);
    // In ra hang ngang
    for (int j = 0; j < height + 1; j += height)
    {
        for (int i = 0; i < width - 1; i++)
        {
            console.Draw(startX + i + 1, startY + j, 205, color);
        }
    }
    //// In ra hang doc
    for (int i = 0; i < width + 1; i += width)
    {
        for (int j = 0; j < height - 1; j++)
        {
            console.Draw(startX + i, startY + j + 1, 186, color);
        }
    }
    console.textColor(15);
}
// UI Leaderboard in Menu
void cLoad_HighScore::leaderboard()
{
    cConsole c;
    list = this->datafromFile("highscore.txt");
    // Nen
    baseBackground(255);
    // Khung ten
    frameNameLeaderBoard(33, 1);
    // Cup vang
    c.textColor(246);
    c.gotoXY(54, 7);
    if (list.size() >= 1)cout << list[0].playerName << " - " << list[0].Score;
    trophy(53, 8, 246, 110);
    // Cup bac
    c.textColor(248);
    c.gotoXY(36, 10);
    if (list.size() >= 2) cout << list[1].playerName << " - " << list[1].Score;
    trophy(35, 11, 248, 135);
    // Cup dong
    c.textColor(244);
    c.gotoXY(71, 10);
    if (list.size() >= 3)cout << list[2].playerName << " - " << list[2].Score;
    trophy(70, 11, 244, 76);
    baseFramNameLeaderboard(30, 21, 60, 17);
    //In danh sach 4 -> het
    if (list.size() < 9 && list.size() >= 3)
    {
        for (int i = 0; i < list.size() - 3; i++)
        {
            c.textColor(223);
            c.gotoXY(35, 24 + i * 2);
            cout << i + 4;
            c.gotoXY(45, 24 + i * 2);
            cout << list[i + 3].getPlayerName();
            c.gotoXY(75, 24 + i * 2);
            cout << list[i + 3].getScore();
            c.textColor(15);
        }
    }
    else if (list.size() >= 9)
    {
        for (int i = 0; i < 6; i++)
        {
            c.textColor(223);
            c.gotoXY(35, 24 + i * 2);
            cout << i + 4;
            c.gotoXY(45, 24 + i * 2);
            cout << list[i + 3].getPlayerName();
            c.gotoXY(75, 24 + i * 2);
            cout << list[i + 3].getScore();
            c.textColor(15);
        }
    }
    cConsole console;
    console.gotoXY(47, 38);
    console.textColor(253);
    cout << " Press Q: Return Menu ";
    char choice;
    do {
        choice = toupper(_getch());
    } while (choice != 'Q');
}
void cLoad_HighScore::trophy(int startX, int startY, int colorFrame, int colorMain)
{
    cConsole console;
    SetConsoleOutputCP(CP_UTF8);
    console.textColor(colorFrame);
    console.gotoXY(startX, startY);     cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
    console.gotoXY(startX, startY + 1);  cout << u8"█  █      █  █";
    console.gotoXY(startX, startY + 2); cout << u8"█  █      █  █";
    console.gotoXY(startX, startY + 3); cout << u8" █ █      █ █ ";
    console.gotoXY(startX, startY + 4); cout << u8"  ██      ██  ";
    console.gotoXY(startX, startY + 5); cout << u8"    █    █    ";
    console.gotoXY(startX, startY + 6); cout << u8"     █  █     ";
    console.gotoXY(startX, startY + 7); cout << u8"   ▄▄█▄▄█▄▄   ";
    // To lai o ben trong
    console.textColor(colorMain);
    console.gotoXY(startX + 4, startY + 1);     cout << u8"██████";
    console.gotoXY(startX + 4, startY + 2);     cout << u8"██████";
    console.gotoXY(startX + 4, startY + 3);     cout << u8"██████";
    console.gotoXY(startX + 4, startY + 4);     cout << u8"██████";
    console.gotoXY(startX + 5, startY + 5);     cout << u8"████";
    console.gotoXY(startX + 6, startY + 6);     cout << u8"██";
    console.gotoXY(startX + 6, startY + 7);     cout << u8"▀▀";
    console.textColor(15);
    SetConsoleOutputCP(437);
}
void cLoad_HighScore::frameNameLeaderBoard(int startX, int startY)
{
    cConsole console;
    // Khung nen duoi
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 53; j++)
        {
            console.Draw(j + startX, i + startY, ' ', 223);
        }
    }
    // Lam dam phan duoi
    for (int i = 0; i < 53; i++)
    {
        console.Draw(i + startX, startY + 4, 223, 245);
    }
    // Chu
    SetConsoleOutputCP(CP_UTF8);
    console.gotoXY(startX + 5, startY + 1);
    console.textColor(223);
    cout << u8"█   █▀▀ ▄▀█ █▀▄ █▀▀ █▀█ █▄▄ █▀█ ▄▀█ █▀█ █▀▄";
    console.gotoXY(startX + 5, startY + 2);
    console.textColor(223);
    cout << u8"█▄▄ ██▄ █▀█ █▄▀ ██▄ █▀▄ █▄█ █▄█ █▀█ █▀▄ █▄▀";
    console.textColor(15);
    SetConsoleOutputCP(437);
}
void cLoad_HighScore::baseFramNameLeaderboard(int startX, int startY, int width, int height)
{
    cConsole console;
    // To hang dau
    for (int i = 0; i < width - 4; i++)
    {
        console.Draw(i + startX + 2, startY, 220, 253);
    }
    // To hang hai
    for (int i = 0; i < width; i++)
    {
        if (i == 0 || i == width - 1)
        {
            console.Draw(i + startX, startY + 1, 220, 253);
        }
        else
        {
            console.Draw(i + startX, startY + 1, 219, 253);
        }
    }
    // To hang cuoi
    for (int i = 0; i < width - 4; i++)
    {
        console.Draw(i + startX + 2, startY + height - 1, 223, 253);
    }
    // To hang cuoi nhi
    for (int i = 0; i < width; i++)
    {
        if (i == 0 || i == width - 1)
        {
            console.Draw(i + startX, startY + height - 2, 223, 253);
        }
        else
        {
            console.Draw(i + startX, startY + height - 2, 219, 253);
        }
    }
    // To phan con lai
    for (int i = 0; i < height - 4; i++)
    {
        for (int j = 0; j < width; j++)
        {
            console.Draw(j + startX, i + startY + 2, 219, 253);
        }
    }
    SetConsoleOutputCP(CP_UTF8);
}