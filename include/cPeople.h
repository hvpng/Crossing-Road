#pragma once
#include "cConsole.h"
#include "cObject.h"
class cPeople
{
    int x, y; // Tọa dộ của con người
    int height, width; // Chiều cao, chiều rộng của con người
    static bool status;// Trạng thái chết hay sống của con người
    int change;// Nhận biết thay đổi di chuyển của con người lên xuống qua lại để vẽ lại
    char** a; // Tạo con người
public:
    void effectDead();
    bool checkCollision(vector<cObject*>);
    void MoveLeft(); // Di chuyển sang trái
    void MoveRight();// Di chuyển sang phải
    void MoveDown();// Di chuyển xuống
    void MoveUp();// Di chuyển lên
    void shape();// Tọa hình cho con người
    void sound();// Xử lý âm thanh
    cPeople(); // Tạo hình cho người(khoi tao)
    void cDltPeople(char**);// Xóa người
    void assignX(int); // Gán tọa độ x cho người
    void assignY(int);// Gán tọa độ y cho người
    void assignStatus(bool);// Gán trạng thái cho người
    void assignChange(int);// Gán thay đổi cho người
    int getX();// lấy tọa độ x của người
    int getY();// lấy tọa độ y của người
    int getHeight();// lấy chiều cao của người
    int getWidth();// lấy chiều rộng của người
    int getChange();// lấy thay đổi của người
    bool getStatus();// lấy trạng thái của người
};

