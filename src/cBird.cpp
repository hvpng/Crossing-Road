#include "cBird.h"

void cBird::create(int direction) {
	a = new char* [5];
	if (direction == 0) {
		a[0] = new char[15] {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', (char)220, (char)219, (char)223, (char)219, (char)16};
		a[1] = new char[15] {' ', (char)220, (char)220, (char)219, (char)219, (char)219, (char)219, (char)219, (char)220, ' ', (char)219, (char)219, (char)223, (char)223, ' '};
		a[2] = new char [15] {(char)223, (char)219, (char)219, (char)219, (char)219, (char)219, (char)219, (char)219, (char)219, (char)219, (char)220, (char)219, (char)219, (char)220, ' '};
		a[3] = new char[15] {' ', ' ', (char)223, (char)219, (char)219, (char)219, (char)219, (char)219, (char)219, (char)219, (char)219, (char)219, (char)219, (char)223, ' '};
		a[4] = new char[15] {' ', ' ', ' ', ' ', ' ', (char)254, (char)16, ' ', ' ', (char)254, (char)16, ' ', ' ', ' ', ' '};
	}
	else if (direction == 1) {
		a[0] = new char[15] { (char)17, (char)219, (char)223, (char)219, (char)220, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
		a[1] = new char[15] { ' ', (char)223, (char)223, (char)219, (char)219, ' ', (char)220, (char)219, (char)219, (char)219, (char)219, (char)219, (char)220, (char)220, ' '};
		a[2] = new char[15] { ' ', (char)220, (char)219, (char)219, (char)220, (char)219, (char)219, (char)219, (char)219, (char)219, (char)219, (char)219, (char)219, (char)219, (char)223};
		a[3] = new char[15] { ' ', (char)223, (char)219, (char)219, (char)219, (char)219, (char)219, (char)219, (char)219, (char)219, (char)219, (char)219, (char)223, ' ', ' '};
		a[4] = new char[15] { ' ', ' ', ' ', ' ', (char)17, (char)254, ' ', ' ', (char)17, (char)254, ' ', ' ', ' ', ' ', ' '};
	}
}
void cBird::assignInitSize()
{
	const_width = width = 15;
	const_height = height = 5;
}
void cBird::checkColor(int i, int j)
{
	cConsole console;
	if (a[i][j] == 16 || a[i][j] == 17)
	{
		console.textColor(124);
		cout << a[i][j];
		console.textColor(15);
	}
	else
	{
		console.textColor(126);
		cout << a[i][j];
		console.textColor(15);
	}
}

void cBird::tell()
{
	PlaySound(TEXT("sounds\\Bird.wav"), NULL, SND_ASYNC || SND_LOOP);
}