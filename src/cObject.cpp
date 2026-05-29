#include "cObject.h"

void cObject::assignX(int X)
{
	x = X;
}
void cObject::assignY(int Y)
{
	y = Y;
}
void cObject::assignWidth(int W)
{
	width = W;
}
void cObject::assignHeight(int H)
{
	height = H;
}
void cObject::assignConstWidth(int W)
{
	const_width = W;
}
void cObject::assignConstHeight(int H)
{
	const_height = H;
}
void cObject::assignStatus(int s)
{
	status = s;
}
void cObject::assignSign(int s)
{
	sign = s;
}

int cObject::getSign()
{
	return sign;
}
int cObject::getX()
{
	return x;
}
int cObject::getY()
{
	return y;
}
int cObject::getWidth()
{
	return width;
}
int cObject::getHeight()
{
	return height;
}
int cObject::getConstHeight()
{
	return const_height;
}
int cObject::getConstWidth()
{
	return const_width;
}
int cObject::getStatus()
{
	return status;
}
char cObject::getPoint(int x, int y)
{
	return a[y][x];
}
cObject::cObject(const cObject& temp) {
	x = temp.x;
	y = temp.y;
	const_width = temp.const_width;
	const_height = temp.const_height;
	width = temp.width;
	height = temp.height;
	status = temp.status;
	rand_shape = temp.rand_shape;
	sign = temp.sign;
	for (int i = 0; i < const_height; i++) {
		for (int j = 0; j < const_width; j++) {
			a[i][j] = temp.a[i][j];
		}
	}
}
void cObject::shape() {
	cConsole console;
	console.textColor(192);
	if (status == 4) // Vẽ xe chui vào bên trái
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = const_width - 1; j >= const_width - 1 - width; j--)
			{
				if (x + j > 0 && 100 - x + j > 0)
				{
					console.gotoXY(x + j, y + i);
					checkColor(i, j);
				}
			}
		}
	}
	else // Vẽ xe chui vào bên phải hoặc các trường hợp xe di chuyển bình thường
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (x + j > 0 && 100 - x - j > 0)
				{
					console.gotoXY(x + j, y + i);
					checkColor(i, j);
				}
			}
		}
	}
	// Xóa đuôi xe
	for (int i = 0; i < const_height; i++)
	{
		if ((status == 0 || status == 3) && x - 1 < 100 && x - 1 > 0)
		{
			console.gotoXY(x - 1, y + i);
			console.textColor(119);
			cout << " ";
		}
		else
			if (x + const_width < 100 && x + const_width > 0)
			{
				console.gotoXY(x + const_width, y + i);
				console.textColor(119);
				cout << " ";
			}
	}
	console.textColor(15);
}