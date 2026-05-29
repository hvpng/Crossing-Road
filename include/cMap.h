#pragma once
#include "cConsole.h"
#include "cPeople.h"
#include "cListObject.h"
#include "cLoad_HighScore.h"
#include "time.h"
class cMap
{
private:
	cPeople people;
	static int level, score;
	vector<cObject*> listObject;
	bool flagMove = false;
	int flagHighScore = 0;
	static int MOVING_CHARACTER;
	static int speed;
	static bool flagMenu;
	static bool flagLoad;
	static bool flagSave;
	static int flagStop;
	string playerName;
	int sign[4] = { 1 };
	clock_t start, end;
	double timeUse = 0;
	static bool flagCreateObject;
	static cListObject temp;
public:
	bool checkFlagMenu();
	void setLevel(int);
	void setScore(int);
	void Yard();
	void output(bool Sound);
	void threadFunc();
	void light(int startX, int startY, int colorVang, int colorXam);
	void redrawTrafficLight();
	void processMovePeople(bool Sound);
	bool redrawEnd(bool Sound);
	void redrawLine();
	void redrawObject();
	void redrawStartAndPeople();
	void processEnd();
	void subScreen(int startX, int startY, int width, int height, int color); // In default subscreen
	void updateLight(int startX, int startY, int colorVang, int colorXam);
	void checkScore();
	void processSubScreen(); // Xu ly de in lai (level/ score)
	void miniButton(int startX, int startY, int width, int height, int colorFrame, int colorChar, char character);
	// UI text Level
	void textLevel(int startX, int startY, int level);
	void levelOne(int startX, int startY, int color);
	void levelTwo(int startX, int startY, int color);
	void levelThree(int startX, int startY, int color);
	void levelFour(int startX, int startY, int color);
};

