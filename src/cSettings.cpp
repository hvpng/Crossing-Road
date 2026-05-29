#include "cSettings.h"

void cSettings::baseBackground(int color)
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
void cSettings::iconVolumeOn(int startX, int startY, int color)
{
	cConsole console;
	SetConsoleOutputCP(CP_UTF8);
	console.gotoXY(startX, startY);
	console.textColor(color);
	cout << u8"           ██                 ";
	console.gotoXY(startX, startY + 1);
	console.textColor(color);
	cout << u8"          ███         █       ";
	console.gotoXY(startX, startY + 2);
	console.textColor(color); 
	cout << u8"        █████      █    █     ";
	console.gotoXY(startX, startY + 3);
	console.textColor(color);
	cout << u8"█████████████       █    █    ";
	console.gotoXY(startX, startY + 4);
	console.textColor(color);
	cout << u8"█████████████   █    █   █    ";
	console.gotoXY(startX, startY + 5);
	console.textColor(color);
	cout << u8"█████████████    █   █   █    ";
	console.gotoXY(startX, startY + 6);
	console.textColor(color);
	cout << u8"█████████████   █    █   █    ";
	console.gotoXY(startX, startY + 7);
	console.textColor(color);
	cout << u8"█████████████       █    █    ";
	console.gotoXY(startX, startY + 8);
	console.textColor(color);
	cout << u8"        █████      █    █     ";
	console.gotoXY(startX, startY + 9);
	console.textColor(color);
	cout << u8"          ███          █      ";
	console.gotoXY(startX, startY + 10);
	console.textColor(color);
	cout << u8"           ██                 ";
	console.textColor(15);
	SetConsoleOutputCP(437);
//           ██                  
//          ███         █      
//		  █████      █    █  
//█████████████       █    █ 
//█████████████   █    █   █
//█████████████    █   █   █ 
//█████████████   █    █   █
//█████████████       █    █
//        █████      █    █ 
//          ███          █  
//           ██             
}
void cSettings::iconVolumeOff(int startX, int startY, int color)
{
	cConsole console;
	SetConsoleOutputCP(CP_UTF8);
	console.gotoXY(startX, startY);
	console.textColor(color);
	cout << u8"           ██               ";
	console.gotoXY(startX, startY + 1);
	console.textColor(color);
	cout << u8"          ███               ";
	console.gotoXY(startX, startY + 2);
	console.textColor(color);
	cout << u8"        █████               ";
	console.gotoXY(startX, startY + 3);
	console.textColor(color);
	cout << u8"█████████████     ██      ██";
	console.gotoXY(startX, startY + 4);
	console.textColor(color);
	cout << u8"█████████████       ██  ██  ";
	console.gotoXY(startX, startY + 5);
	console.textColor(color);
	cout << u8"█████████████         ██    ";
	console.gotoXY(startX, startY + 6);
	console.textColor(color);
	cout << u8"█████████████       ██  ██  ";
	console.gotoXY(startX, startY + 7);
	console.textColor(color);
	cout << u8"█████████████     ██      ██";
	console.gotoXY(startX, startY + 8);
	console.textColor(color);
	cout << u8"        █████               ";
	console.gotoXY(startX, startY + 9);
	console.textColor(color);
	cout << u8"          ███               ";
	console.gotoXY(startX, startY + 10);
	console.textColor(color);
	cout << u8"           ██               ";
	console.textColor(15);
	SetConsoleOutputCP(437);
//           ██               
//          ███               
//		  █████               
//█████████████     ██      ██
//█████████████       ██  ██  
//█████████████         ██    
//█████████████       ██  ██  
//█████████████     ██      ██
//        █████               
//          ███               
//           ██               
}
void cSettings::iconRight(int startX, int startY, int color)
{
	cConsole console;
	SetConsoleOutputCP(CP_UTF8);
	console.gotoXY(startX, startY);
	console.textColor(color);
	cout << u8"      █████  ";
	console.gotoXY(startX, startY + 1);
	console.textColor(color);
	cout << u8"█████████████ ";
	console.gotoXY(startX, startY + 2);
	console.textColor(color);
	cout << u8"███████████████";
	console.gotoXY(startX, startY + 3);
	console.textColor(color);
	cout << u8"█████████████ ";
	console.gotoXY(startX, startY + 4);
	console.textColor(color);
	cout << u8"      █████   ";
	console.textColor(15);
	SetConsoleOutputCP(437);
}
void cSettings::iconLeft(int startX, int startY, int color)
{
	cConsole console;
	SetConsoleOutputCP(CP_UTF8);
	console.gotoXY(startX, startY);
	console.textColor(color);
	cout << u8"    █████      ";
	console.gotoXY(startX, startY + 1);
	console.textColor(color);
	cout << u8"  █████████████";
	console.gotoXY(startX, startY + 2);
	console.textColor(color);
	cout << u8"███████████████";
	console.gotoXY(startX, startY + 3);
	console.textColor(color);
	cout << u8"  █████████████";
	console.gotoXY(startX, startY + 4);
	console.textColor(color);
	cout << u8"    █████       ";
	console.textColor(15);
	SetConsoleOutputCP(437);
}
void cSettings::runSettings()
{
	// To mau nen phia duoi -> 51: mau xanh
	baseBackground(51);
	frameNameSettings(41,2); 
	// Hai button trai phai
	iconLeft(24,17, 50);
	iconRight(80,17,50);
	// Dieu kien sound off hay sound on (khi bam nut return)
	if(sound == "on")
		iconVolumeOn(46, 14, 63);
	else
		iconVolumeOff(46, 14, 63);
	cConsole console;
	console.gotoXY(47, 34);
	console.textColor(71);
	cout << " Press Q: Return Menu ";
	//iconVolumeOn(52, 10, 63);
	do
	{
		if (_kbhit)
		{
			char choice = toupper(_getch());
			if (choice == 'Q') {
				break;
			}
			// Neu bam nut sang trai hay sang phai
			if (choice == 77 || choice == 75)
			{
				if (sound == "on")
				{
					iconVolumeOff(46, 14, 63);
					sound = "off";
					statusSound = false;
					checkContinuous = false;	// tắt liên tục để bài hát bật lại
					PlaySound(NULL, NULL, NULL);
				}
				else if (sound == "off")
				{
					iconVolumeOn(46, 14, 63);
					sound = "on";
					statusSound = true;
					checkContinuous = true;
					PlaySound(TEXT("sounds\\bg.wav"), NULL, SND_SYNC || SND_LOOP);
				}
			}
		}
	} while (true);
}
void cSettings::frameNameSettings(int startX, int startY)
{
	cConsole console;
	// Khung nen duoi
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 38; j++)
		{
			console.Draw(j + startX, i + startY, ' ', 119);
		}
	}
	// Lam dam phan duoi
	for (int i = 0; i < 38; i++)
	{
		console.Draw(i + startX, startY + 4, 223, 56);
	}
	// Chu
	SetConsoleOutputCP(CP_UTF8);
	console.gotoXY(startX + 5, startY + 1);
	console.textColor(113);
	cout << u8"█▀ █▀▀ ▀█▀ ▀█▀ █ █▄ █ █▀▀ █▀";
	console.gotoXY(startX + 5, startY + 2);
	console.textColor(113);
	cout << u8"▄█ ██▄  █   █  █ █ ▀█ █▄█ ▄█";
	console.textColor(15);
	SetConsoleOutputCP(437);
}
bool cSettings::getSoundStatus() {
	return this->statusSound;
}
bool cSettings::getContinuosStatus() {
	return this->checkContinuous;
}
void cSettings::changeContinuosStatus() {
	this->checkContinuous = !this->checkContinuous;
}
// 219 █ 221 ▌ 222 ▐ 220 ▄ 223 ▀ 16 ► 17 ◄ 248 ° 30 ▲ 31 ▼ 92 \ 47 / 254 ■

//           ██               
//          ███               
//		  █████               
//█████████████     ██      ██
//█████████████       ██  ██  
//█████████████         ██    
//█████████████       ██  ██  
//█████████████     ██      ██
//        █████               
//          ███               
//           ██               


   
//       █████  
//█████████████  
//██████████████  
//█████████████ 
//       ████   
   
//    █████      
//  █████████████
// ██████████████ 
//  █████████████
//    ████       