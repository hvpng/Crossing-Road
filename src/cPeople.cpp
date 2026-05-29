#include "cPeople.h"
bool cPeople::status = 0;
bool cPeople::checkCollision(vector<cObject*> c) {
	for (int i = 0; i < c.size(); i++)
	{
		//Xử lý va chạm bên dưới phai
		if (getY() == c[i]->getY() + c[i]->getConstHeight() - 1 && getX() >= c[i]->getX() && getX() <= c[i]->getX() + c[i]->getConstWidth() - 1)
		{
			for (int j = getX() - c[i]->getX() + 1; j < c[i]->getConstWidth() && j < getX() - c[i]->getX() + getWidth() - 2; j++)
			{
				if (!(c[i]->getPoint(j, c[i]->getConstHeight() - 1) == NULL || c[i]->getPoint(j, c[i]->getConstHeight() - 1) == ' ')) {
					c[i]->tell();
					return true;
				}
			}
		}
		else
		//Xử lý va chạm bên dưới trai
		if (getY() == c[i]->getY() + c[i]->getConstHeight() - 1 && getX() < c[i]->getX() && getX() + getWidth() - 1 >= c[i]->getX())
		{
			for (int j = 0; j < (getWidth() - (c[i]->getX() - getX())) && j < c[i]->getConstWidth() && j < getWidth() - 2; j++)
			{
				if (!(c[i]->getPoint(j, c[i]->getConstHeight() - 1) == NULL || c[i]->getPoint(j, c[i]->getConstHeight() - 1) == ' ')) {
					c[i]->tell();
					return true;
				}
			}
		}
		else
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//Xử lý va chạm bên trên phai
		if (getY() + getHeight() - 1 == c[i]->getY() && getX() >= c[i]->getX() && getX() <= c[i]->getX() + c[i]->getConstWidth() - 1)
		{
			for (int j = getX() - c[i]->getX() + 1; j < c[i]->getConstWidth() && j < getX() - c[i]->getX() + getWidth() - 2; j++)
			{
				if (!(c[i]->getPoint(j, 0) == NULL || c[i]->getPoint(j, 0) == ' ')) {
					c[i]->tell();
					return true;
				}
			}
		}
		else
		//Xử lý va chạm bên trên trai
		if (getY() + getHeight() - 1 == c[i]->getY() && getX() < c[i]->getX() && getX() + getWidth() - 1 >= c[i]->getX())
		{
			for (int j = 0; j < (getWidth() - (c[i]->getX() - getX())) && j < c[i]->getConstWidth() && j < getWidth() - 2; j++)
			{
				if (!(c[i]->getPoint(j, 0) == NULL || c[i]->getPoint(j, 0) == ' ')) {
					c[i]->tell();
					return true;
				}
			}
		}
		else
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//Xử lý va chạm bên trái dưới
		if (c[i]->getX() > getX() && getX() + getWidth() - 1>= c[i]->getX() && getX() < c[i]->getX() + c[i]->getConstWidth() && getY() > c[i]->getY() && getY() <= c[i]->getY() + c[i]->getConstHeight() - 1)
		{
			for (int j = getY() - c[i]->getY(); j < c[i]->getConstHeight(); j++)
			{
				if (!(c[i]->getPoint(abs(getX() + getWidth() - 1 - c[i]->getX()), j) == NULL || c[i]->getPoint(abs(getX() + getWidth() - 1 - c[i]->getX()), j) == ' ')) {
					c[i]->tell();
					return true;
				}
			}
		}
		else
		//Xử lý va chạm bên trái trên
		if (c[i]->getX() > getX() && getX() + getWidth() - 1>= c[i]->getX() && getX() < c[i]->getX() + c[i]->getConstWidth() && getY() <= c[i]->getY() && getY() + getHeight() - 1 >= c[i]->getY())
		{
			for (int j = 0; j < c[i]->getConstHeight() && j < getHeight() - (c[i]->getY() - getY()); j++)
			{
				if (!(c[i]->getPoint(abs(getX() + getWidth() - 1 - c[i]->getX()), j) == NULL || c[i]->getPoint(abs(getX() + getWidth() - 1 - c[i]->getX()), j) == ' '))
				{
					c[i]->tell();
					return true;
				}
			}
		}
		else
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//Xử lý va chạm bên phải tren
		if (getX() >= c[i]->getX() && getX() <= c[i]->getX() + c[i]->getConstWidth() - 1 && getX() + getWidth() >= c[i]->getX() && getY() <= c[i]->getY() && getY() + getHeight() - 1 >= c[i]->getY())
		{
			for (int j = 0; j < c[i]->getConstHeight() && j < getHeight() - (c[i]->getY() - getY()); j++)
			{
				if (!(c[i]->getPoint(abs(getX() - c[i]->getX()), j) == NULL || c[i]->getPoint(abs(getX() - c[i]->getX()), j) == ' '))
				{
					c[i]->tell();
					return true;
				}
			}
		}
		else
		//Xử lý va chạm bên phải duoi
		if (getX() >= c[i]->getX() && getX() <= c[i]->getX() + c[i]->getConstWidth() - 1 && getX() + getWidth() >= c[i]->getX() && getY() >= c[i]->getY() && getY() <= c[i]->getY() + c[i]->getConstHeight() - 1)
		{
			for(int j = getY() - c[i]->getY(); j < c[i]->getConstHeight(); j++)
			{
				if (!(c[i]->getPoint(abs(getX() - c[i]->getX()), j) == NULL || c[i]->getPoint(abs(getX() - c[i]->getX()), j) == ' ')) {
					c[i]->tell();
					return true;
				}
			}
		}
	}
	return false;
}
void cPeople::sound()
{
	//PlaySound(TEXT("SoundCar.wav"), NULL, SND_ASYNC);
}
 cPeople::cPeople()
{
	height = 3;
	width = 6;
	a = new char* [height];
	a[0] = new char[width] { ' ', (char)221, (char)223, (char)223, (char)222, ' ' };
	a[1] = new char[width] { (char)223, (char)219, (char)219, (char)219, (char)219, (char)223 };
	a[2] = new char[width] { ' ', (char)223, ' ', ' ', (char)223, ' '};
}
void cPeople::cDltPeople(char** car)
{
	for (int i = 0; i < 4; i++)
	{
		delete[]car[i];
	}
	delete[]car;
}
void cPeople::shape()
{
	cConsole c;
	c.textColor(113);
	
	//Vẽ con người
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			c.gotoXY(x + j, y + i);
			cout << a[i][j];
		}
	}
}
void cPeople::effectDead()
{
	cConsole c;
	c.textColor(113);
	SetConsoleOutputCP(CP_UTF8);
	for (int i = 0; i < 3; i++)
	{
		c.gotoXY(x, y);
		cout << u8"▄▄█▄▄ " << endl;
		c.gotoXY(x, y + 1);
		cout << u8" ██ ▐ " << endl;
		c.gotoXY(x, y + 2);
		cout << u8"▀▀█▀▀ " << endl;
		Sleep(300);
		c.gotoXY(x, y);
		cout << u8"      " << endl;
		c.gotoXY(x, y + 1);
		cout << u8"      " << endl;
		c.gotoXY(x, y + 2);
		cout << u8"      " << endl;
		Sleep(50);
	}
	c.textColor(65);
	c.gotoXY(x - 1, y);      cout << u8" ▄▄█▄▄  " << endl;
	c.gotoXY(x - 1, y + 1);  cout << u8"  ██ ▐ " << endl;
	c.gotoXY(x - 1, y + 2);  cout << u8" ▀▀█▀▀ " << endl;
	c.gotoXY(x - 1, y + 3);  cout << u8"       " << endl;
	c.gotoXY(x - 2, y + 1);  cout << u8" " << endl;
	c.gotoXY(x, y - 1); cout << u8" " << endl;
	c.gotoXY(x + 3, y - 1); cout << u8" " << endl;
	Sleep(200);
	c.textColor(116);
	c.gotoXY(x - 2, y + 3);  cout << u8"█▀█▀█▀█▀█ " << endl;
	Sleep(200);
	c.gotoXY(x - 2, y + 4);  cout << u8"█ █ █ █ ▀" << endl;
	Sleep(200);
	c.gotoXY(x - 2, y + 5);  cout << u8"█ ▀ █ " << endl;
	Sleep(200);
	c.gotoXY(x - 2, y + 6);  cout << u8"    █ " << endl;
	c.textColor(15);
}
void cPeople::assignX(int X)
{
	x = X;
}
void cPeople::assignY(int Y)
{
	y = Y;
}
void cPeople::assignChange(int c)
{
	change = c;
}
void cPeople::assignStatus(bool s)
{
	status = s;
}
int cPeople::getX()
{
	return x;
}
int cPeople::getChange()
{
	return change;
}
int cPeople::getY()
{
	return y;
}
int cPeople::getHeight()
{
	return height;
}
int cPeople::getWidth()
{
	return width;
}
bool cPeople::getStatus()
{
	return status;
}
void cPeople::MoveLeft()
{
	x--;
	change = 0;
}
void cPeople::MoveRight()
{
	x++;
	change = 1;
}
void cPeople::MoveDown()
{
	y++;
	change = 2;
}
void cPeople::MoveUp()
{
	y--;
	change = 3;
}