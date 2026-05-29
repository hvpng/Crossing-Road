#pragma once
#include "cConsole.h"
class cSettings
{
private:
	const int WIDTH_SCREEN = 120;
	const int HEIGHT_SCREEN = 40;
	bool statusSound = true;
	bool checkContinuous = true;
	string sound = "on";
	void baseBackground(int color);
	void iconVolumeOn(int startX, int startY, int color);
	void iconVolumeOff(int startX, int startY, int color);
	void iconLeft(int startX, int startY, int color);
	void iconRight(int startX, int startY, int color);
public:
	void runSettings();
	bool getSoundStatus();
	bool getContinuosStatus();
	void changeContinuosStatus();
	void frameNameSettings(int startX, int startY);
};

