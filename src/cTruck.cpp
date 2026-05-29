#include "cTruck.h"
void cTruck::create(int direction) {
	a = new char* [5];
	if (direction == 0) {
		a[0] = new char[16] { (char)222, (char)223, (char)223, (char)223, (char)223, (char)223, (char)223, (char)223, (char)222, (char)221, (char)220, ' ', ' ', ' ', ' ', ' ' };
		a[1] = new char[16] { (char)221, (char)177, (char)177, (char)177, (char)177, (char)177, (char)177, (char)177, (char)219, (char)221, (char)219, (char)219, (char)220, ' ', ' ', ' ' };
		a[2] = new char[16] { (char)221, (char)177, (char)177, (char)177, (char)177, (char)177, (char)177, (char)177, (char)219, (char)221, (char)219, (char)221, (char)222, (char)220, (char)220, (char)220 };
		a[3] = new char[16] { (char)222, (char)220, (char)220, (char)220, (char)220, (char)220, (char)220, (char)220, (char)219, (char)221, (char)219, (char)219, (char)219, (char)219, (char)219, (char)219 };
		a[4] = new char[16] { (char)223, (char)248, (char)248, (char)223, (char)223, (char)223, (char)223, (char)248, (char)248, (char)223, (char)223, (char)223, (char)223, (char)223, (char)248, (char)223 };
	}
	else if (direction == 1) {
		a[0] = new char[16] { ' ', ' ', ' ', ' ', ' ', (char)220, (char)221, (char)222, (char)223, (char)223, (char)223, (char)223, (char)223, (char)223, (char)223, (char)221};
		a[1] = new char[16] { ' ', ' ', ' ', (char)220, (char)219, (char)219, (char)221, (char)219, (char)177, (char)177, (char)177, (char)177, (char)177, (char)177, (char)177, (char)222};
		a[2] = new char[16] { (char)220, (char)220, (char)220, (char)221, (char)222, (char)219, (char)221, (char)219, (char)177, (char)177, (char)177, (char)177, (char)177, (char)177, (char)177, (char)222 };
		a[3] = new char[16] { (char)219, (char)219, (char)219, (char)219, (char)219, (char)219, (char)221, (char)219, (char)220, (char)220, (char)220, (char)220, (char)220, (char)220, (char)220, (char)221 };
		a[4] = new char[16] { (char)223, (char)248, (char)223, (char)223, (char)223, (char)223, (char)223, (char)248, (char)248, (char)223, (char)223, (char)223, (char)223, (char)248, (char)248, (char)223 };
	}
}
void cTruck::assignInitSize()
{
	const_width = width = 16;
	const_height = height = 5;
}
void cTruck::checkColor(int i, int j)
{
	cConsole console;
	if (a[i][j] == (char)177 || a[i][j] == (char)248)
	{
		console.textColor(112);
		cout << a[i][j];
		console.textColor(15);
	}
	else
	{
		console.textColor(121);
		cout << a[i][j];
		console.textColor(15);
	}
}

void cTruck::tell() {
	PlaySound(TEXT("sounds\\Car.wav"), NULL, SND_ASYNC || SND_LOOP);
}