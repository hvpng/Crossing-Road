#include "cMenu.h"
#include "cConsole.h"
#include "cMap.h"
#include "cSettings.h"
#include "cEnd.h"
#include "cIntro.h"
int main() {
	cConsole console;
	console.assignHeight(1250); // Gán chiều cao màn hình
	console.assignWidth(1250);// Gán chiều rộng màn hình
	console.resizeConsole();// chỉnh sửa kích thước màn hình
	console.FixConsoleWindow(); // Cố định màn hình
	console.assignFlag(false); // Ra lệnh tắt cont trỏ nhấp nháy
	console.ShowConsoleCursor();// Tắt cont trỏ nhấp nháy
	//hiệu ứng intro
	cIntro intro;
	cSettings settings;
	Sleep(5000);
	PlaySound(TEXT("sounds\\bg.wav"), NULL, SND_SYNC || SND_LOOP);
	Sleep(1000);
	intro.runIntro();
	Sleep(1000);
	// gọi hàm nhạc nền
	cMenu a;
BEGIN:
	
	console.textColor(15);
	system("cls");
	if (settings.getContinuosStatus() == false)	// Nếu không liên tục thì bật lại bài hát
	{
		if (settings.getSoundStatus() == true)
			a.playMusic();
		else
			a.stopMusic();
	}
	int check= a.runMenu();
	if (check == 1) {// chọn new game
		system("cls");
		bool soundCheck = settings.getSoundStatus();
		a.stopMusic();
		if(settings.getContinuosStatus() == true)
			settings.changeContinuosStatus();
		cMap start;
		thread t1(&cMap::threadFunc, start);
		HANDLE handle_t1 = t1.native_handle();
		start.output(soundCheck);
		t1.detach();
		if (start.checkFlagMenu() == true) goto BEGIN;
		// trở lại menu
	}
	if (check == 2) {// chọn load game
		//phải làm sao để bật cờ là đã có tên rồi
		system("cls");
		bool soundCheck = settings.getSoundStatus();
		if (soundCheck == true && settings.getContinuosStatus() == false)
		{
			settings.changeContinuosStatus();
		}
		int level, score;
		cLoad_HighScore a;
		a.processLoadMenu(level, score);
		if (a.getStatus() == false) goto BEGIN;
		cMap start;
		PlaySound(NULL, NULL, NULL);
		if (settings.getContinuosStatus() == true)
			settings.changeContinuosStatus();
		start.setLevel(level);
		start.setScore(score);
		system("cls");
		thread t1(&cMap::threadFunc, start);
		HANDLE handle_t1 = t1.native_handle();
		start.output(soundCheck);
		t1.detach();
		if (start.checkFlagMenu() == true) goto BEGIN;
	}
	if (check == 5) {
		system("cls");
		// hiệu ứng kết thúc game
		cEnd endgame;
		endgame.runEnd();
		return 0;
	}
	if (check == 3)//setting
	{
		bool soundCheck = settings.getSoundStatus();
		if (soundCheck == true && settings.getContinuosStatus() == false)
		{
			settings.changeContinuosStatus();
		}
		settings.runSettings();
		goto BEGIN;
	}
	if (check == 4)//highscore
	{
		cLoad_HighScore lb;
		bool soundCheck = settings.getSoundStatus();
		if (soundCheck == true && settings.getContinuosStatus() == false)
		{
			settings.changeContinuosStatus();
		}
		lb.leaderboard();
		goto BEGIN;
	}
	return 0;
}