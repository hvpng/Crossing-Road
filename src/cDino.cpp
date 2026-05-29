#include "cDino.h"

void cDino::create(int direction) {
	a = new char* [5];
	if (direction == 0) {
		a[0] = new char[10] { ' ', ' ', ' ', ' ', (char)220, (char)220, (char)220, (char)220, (char)220, ' ' };
		a[1] = new char[10] { ' ', ' ', ' ', (char)17, (char)219, (char)219, (char)219, (char)220, (char)223, (char)223 };
		a[2] = new char[10] { ' ', ' ', ' ', (char)17, (char)219, (char)219, (char)219, (char)219, (char)223, (char)223 };
		a[3] = new char[10] { (char)17, (char)219, ' ', (char)17, (char)219, (char)219, (char)219, (char)219, (char)223, ' '};
		a[4] = new char[10] { ' ', ' ', (char)223, (char)223, (char)219, (char)219, (char)219, (char)219, (char)220, ' '};
	}
	else if (direction == 1) {
		a[0] = new char[10] { ' ', (char)220, (char)220, (char)220, (char)220, (char)220, ' ', ' ', ' ', ' '};
		a[1] = new char[10] { (char)223, (char)223, (char)220, (char)219, (char)219, (char)219, (char)16, ' ', ' ', ' '};
		a[2] = new char[10] { (char)223, (char)223, (char)219, (char)219, (char)219, (char)219, (char)16, ' ', ' ', ' ' };
		a[3] = new char[10] { ' ', (char)223, (char)219, (char)219, (char)219, (char)219, (char)16, ' ', (char)219, (char)16};
		a[4] = new char[10] { ' ', (char)220, (char)219, (char)219, (char)219, (char)219, (char)223, (char)223, ' ', ' ' };
	}
}
void cDino::assignInitSize()
{
	const_width = width = 10;
	const_height = height = 5;
}
void cDino::checkColor(int i, int j)
{
	cConsole console;
	if (a[i][j] == 16 || a[i][j] == 17)
	{
		console.textColor(114);
		cout << a[i][j];
		console.textColor(15);
	}
	else
	{
		console.textColor(125);
		cout << a[i][j];
		console.textColor(15);
	}
}

void cDino::tell() {
	PlaySound(TEXT("sounds\\Dino.wav"), NULL, SND_ASYNC || SND_LOOP);
}