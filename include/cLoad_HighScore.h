#pragma once
#include "cConsole.h"
const int WIDTH_SCREEN = 120;
const int HEIGHT_SCREEN = 40;
class cLoad_HighScore {
private:
    string playerName; // Tên người chơi
    int level; // cấp dộ vòng game
    int Score;// Điểm
    bool status = true;
    vector<cLoad_HighScore> list;
    // UI Load Game Outside
    void baseBackground(int color);
    void frameName(int startX, int startY);
    void baseFramName(int startX, int startY, int width, int height);
    void background();
    // UI checklistsize == 0
    void checkListSizeZero(int startX, int startY, int color);
    // UI Leaderboard in Menu
    void trophy(int startX, int startY, int colorFrame, int colorMain);
    void frameNameLeaderBoard(int startX, int startY);
    void baseFramNameLeaderboard(int startX, int startY, int width, int height);
public:
    void leaderboard();
    cLoad_HighScore() {
        playerName = " ";
        level = 0;
        Score = 0;
    }// Khởi tạo mặc định vòng chởi
    // UI Load Game In Game
      // UI Save Game
    void frameInputName(int startX, int startY, int width, int height, int color);
    void baseBackground(int startX, int startY, int width, int height, int menu);
    string getPlayerName(); // Lấy tên người chơi
    int getLevel();// Lấy cấp độ vòng game
    int getScore();// Lấy điểm người chơi
    void setdata(string, int, int); // Đặt lại dữ liệu 
    void datatoFileforHighScore(string);// Dữ liệu đến highscore
    void datatoFileforLoad(string);// Dữ liệu đến load game
    void datatoFilewhenDelete(string fileName, vector<cLoad_HighScore>); // Khởi tạo lại danh sách khi xóa
    vector<cLoad_HighScore> datafromFile(string); // Danh sách người chơi
    void readData(string line_inf);// Đọc dữ liệu
    void processLoadMenu(int&, int&);
    void processLoadinGame(int&, int&);
    string processSave(int, int);
    bool getStatus();
};



