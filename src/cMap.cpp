#include "cMap.h"
int cMap::MOVING_CHARACTER = 0;
int cMap::level = 1;
int cMap::score = 0;
int cMap::speed = 30;
int cMap::flagStop = 0;
bool cMap::flagLoad = false;
bool cMap::flagSave = false;
bool cMap::flagMenu = false;
bool cMap::flagCreateObject = false;
cListObject cMap::temp = {};
bool cMap::checkFlagMenu() {
	return this->flagMenu;
}
void cMap::setLevel(int lev) {
	this->level = lev;
}
void cMap::setScore(int sco) {
	this->score = sco;
}
void cMap::Yard() {
	cConsole c;
	//c.textColor();
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 38; j++)
		{
			c.Draw(i, j, ' ', 127);
		}
	}

	// Duong di
	for (int i = 5; i < 39; i += 7)
	{
		for (int j = 1; j < 100; j += 2)
		{
			if (j % 2 != 0)
			{
				c.Draw(j, i, 205, 118);
			}
		}
		cout << endl;
	}
	// Phan ket thuc
	for (int i = 0; i < 100; i += 2)
	{
		for (int j = 1; j < 5; j++)
		{
			if (j % 2 == 0)
			{
				c.Draw(i + 1, j, 219, 15);
				if (i < 99)
				{
					c.Draw(i + 2, j, ' ', 15);
				}
			}
			else
			{
				c.Draw(i, j, 219, 15);
				if (i < 100)
				{
					c.Draw(i + 1, j, ' ', 15);
				}
			}
		}
	}

	// Phan mo dau
	c.textColor(116);
	SetConsoleOutputCP(CP_UTF8);
	c.gotoXY(36, 34);
	cout << u8".▄▄ · ▄▄▄▄▄ ▄▄▄· ▄▄▄  ▄▄▄▄▄";
	c.gotoXY(36, 35);
	cout << u8"▐█ ▀. •██  ▐█ ▀█ ▀▄ █·•██  ";
	c.gotoXY(36, 36);
	cout << u8"▄▀▀▀█▄ ▐█.▪▄█▀▀█ ▐▀▀▄  ▐█.▪";
	c.gotoXY(36, 37);
	cout << u8"▐█▄▪▐█ ▐█▌·▐█ ▪▐▌▐█•█▌ ▐█▌·";
	c.gotoXY(36, 38);
	cout << u8"▀▀▀▀  ▀▀▀  ▀  ▀ .▀  ▀ ▀▀▀ ";
	SetConsoleOutputCP(437);

	// Khung ngoai
	c.Draw(0, 0, 201, 119);
	c.Draw(100, 0, 187, 238);
	for (int i = 1; i < 100; i++)
	{
		c.Draw(i, 0, 205, 119);
	}
	for (int i = 1; i < 39; i++)
	{
		c.Draw(0, i, 186, 119);
		c.Draw(100, i, 186, 238);
	}
	c.Draw(0, 38, 200, 119);
	c.Draw(100, 38, 188, 238);
	for (int i = 1; i < 100; i++)
	{
		c.Draw(i, 38, 205, 119);
	}
	cout << endl;
	for (int i = 0; i < 4; i++)
	{
		if (sign[i] != 0) sign[i] = rand() % 2;
		else sign[i] = 1;
	}
	for (int i = 0; i < 4; i++)
	{
		if (sign[i] == 1) // Den do
		{
			light(100, 7 * (i + 1) - 1, 234, 122);
		}
		else if (sign[i] == 0) // Den xanh
		{
			light(100, 7 * (i + 1) - 1, 236, 114);
		}
	}
}
void cMap::subScreen(int startX, int startY, int width, int height, int color)
{
	cConsole console;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			console.Draw(j + startX, i + startY, ' ', color);
		}
	}
	// Level
	textLevel(109, 1, 1);
	//processSubScreen();
	// Hang ngang 1
	for (int i = 0; i < 47; i++)
	{
		console.Draw(101 + i, 13, 196, 234);
	}
	// Diem
	checkScore();
	// Hang ngang 2
	for (int i = 0; i < 47; i++)
	{
		console.Draw(101 + i, 23, 196, 234);
	}
	// In button
	console.textColor(233);
	console.gotoXY(113, 26); cout << "Enter T: Save Game";
	console.gotoXY(113, 29); cout << "Enter L: Load Game";
	console.gotoXY(113, 32); cout << "Enter Y: Continue Game";
	console.gotoXY(113, 35); cout << "Enter Q: Quit Game";
}
void cMap::updateLight(int startX, int startY, int colorVang, int colorXam)
{
	//if (color == 0) color = 4;
	//else color = 2;
	cConsole c;
	SetConsoleOutputCP(CP_UTF8);
	c.textColor(colorVang);
	c.gotoXY(startX, startY);      cout << u8"██";
	c.gotoXY(startX, startY + 1);  cout << u8"██";
	c.gotoXY(startX, startY + 2);  cout << u8"██";
	c.gotoXY(startX, startY + 3);  cout << u8"██";
	c.gotoXY(startX, startY + 4);  cout << u8"██";
	c.gotoXY(startX, startY + 5);  cout << u8"██";
	c.textColor(15);
	SetConsoleOutputCP(437);
}
void cMap::textLevel(int startX, int startY, int level)
{
	cConsole c;
	SetConsoleOutputCP(CP_UTF8);
	// Goc Level
	{
		c.textColor(224);
		c.gotoXY(startX, startY);      cout << u8"█      ████   █    █   ████   █";
		c.gotoXY(startX, startY + 1);  cout << u8"█      █      █    █   █      █";
		c.gotoXY(startX, startY + 2);  cout << u8"█      ███    █    █   ███    █";
		c.gotoXY(startX, startY + 3);  cout << u8"█      █       █  █    █      █";
		c.gotoXY(startX, startY + 4);  cout << u8"████   ████     █      ████   ████";
	}
	// Vien trai
	{
		c.textColor(233);
		// Vien trai - Hang 1
		{
			c.gotoXY(startX - 1, startY); cout << u8"▐";
			c.gotoXY(startX + 6, startY); cout << u8"▐";
			c.gotoXY(startX + 13, startY); cout << u8"▐";
			c.gotoXY(startX + 18, startY); cout << u8"▐";
			c.gotoXY(startX + 22, startY); cout << u8"▐";
			c.gotoXY(startX + 29, startY); cout << u8"▐";
		}
		// Vien trai - Hang 2
		{
			c.gotoXY(startX - 1, startY + 1); cout << u8"▐";
			c.gotoXY(startX + 6, startY + 1); cout << u8"▐";
			c.gotoXY(startX + 13, startY + 1); cout << u8"▐";
			c.gotoXY(startX + 18, startY + 1); cout << u8"▐";
			c.gotoXY(startX + 22, startY + 1); cout << u8"▐";
			c.gotoXY(startX + 29, startY + 1); cout << u8"▐";
		}
		// Vien trai - Hang 3
		{
			c.gotoXY(startX - 1, startY + 2); cout << u8"▐";
			c.gotoXY(startX + 6, startY + 2); cout << u8"▐";
			c.gotoXY(startX + 13, startY + 2); cout << u8"▐";
			c.gotoXY(startX + 18, startY + 2); cout << u8"▐";
			c.gotoXY(startX + 22, startY + 2); cout << u8"▐";
			c.gotoXY(startX + 29, startY + 2); cout << u8"▐";
		}
		// Vien trai - Hang 4
		{
			c.gotoXY(startX - 1, startY + 3); cout << u8"▐";
			c.gotoXY(startX + 6, startY + 3); cout << u8"▐";
			c.gotoXY(startX + 14, startY + 3); cout << u8"▐";
			c.gotoXY(startX + 17, startY + 3); cout << u8"▐";
			c.gotoXY(startX + 22, startY + 3); cout << u8"▐";
			c.gotoXY(startX + 29, startY + 3); cout << u8"▐";
		}
		// Vien trai - Hang 5
		{
			c.gotoXY(startX - 1, startY + 4); cout << u8"▐";
			c.gotoXY(startX + 6, startY + 4); cout << u8"▐";
			c.gotoXY(startX + 15, startY + 4); cout << u8"▐";
			c.gotoXY(startX + 22, startY + 4); cout << u8"▐";
			c.gotoXY(startX + 29, startY + 4); cout << u8"▐";
		}
	}
	// Vien phai
	{
		c.textColor(236);
		// Vien phai - Hang 1
		{
			c.gotoXY(startX + 1, startY); cout << u8"▌";
			c.gotoXY(startX + 11, startY); cout << u8"▌";
			c.gotoXY(startX + 15, startY); cout << u8"▌";
			c.gotoXY(startX + 20, startY); cout << u8"▌";
			c.gotoXY(startX + 27, startY); cout << u8"▌";
			c.gotoXY(startX + 31, startY); cout << u8"▌";
		}
		// Vien phai - Hang 2
		{
			c.gotoXY(startX + 1, startY + 1); cout << u8"▌";
			c.gotoXY(startX + 8, startY + 1); cout << u8"▌";
			c.gotoXY(startX + 15, startY + 1); cout << u8"▌";
			c.gotoXY(startX + 20, startY + 1); cout << u8"▌";
			c.gotoXY(startX + 24, startY + 1); cout << u8"▌";
			c.gotoXY(startX + 31, startY + 1); cout << u8"▌";
		}
		//// Vien phai - Hang 3
		{
			c.gotoXY(startX + 1, startY + 2); cout << u8"▌";
			c.gotoXY(startX + 10, startY + 2); cout << u8"▌";
			c.gotoXY(startX + 15, startY + 2); cout << u8"▌";
			c.gotoXY(startX + 20, startY + 2); cout << u8"▌";
			c.gotoXY(startX + 26, startY + 2); cout << u8"▌";
			c.gotoXY(startX + 31, startY + 2); cout << u8"▌";
		}
		//// Vien phai - Hang 4
		{
			c.gotoXY(startX + 1, startY + 3); cout << u8"▌";
			c.gotoXY(startX + 8, startY + 3); cout << u8"▌";
			c.gotoXY(startX + 16, startY + 3); cout << u8"▌";
			c.gotoXY(startX + 19, startY + 3); cout << u8"▌";
			c.gotoXY(startX + 24, startY + 3); cout << u8"▌";
			c.gotoXY(startX + 31, startY + 3); cout << u8"▌";
		}
		//// Vien phai - Hang 5
		{
			c.gotoXY(startX + 4, startY + 4); cout << u8"▌";
			c.gotoXY(startX + 11, startY + 4); cout << u8"▌";
			c.gotoXY(startX + 17, startY + 4); cout << u8"▌";
			c.gotoXY(startX + 27, startY + 4); cout << u8"▌";
			c.gotoXY(startX + 34, startY + 4); cout << u8"▌";
		}
	}
	levelOne(104, 7, 231);
	levelTwo(115, 7, 231);
	levelThree(126, 7, 231);
	levelFour(137, 7, 231);
	processSubScreen();
	c.textColor(15);
	SetConsoleOutputCP(437);
}
void cMap::levelOne(int startX, int startY, int color)
{
	cConsole c;
	SetConsoleOutputCP(CP_UTF8);
	c.textColor(color);
	c.gotoXY(startX, startY);      cout << u8"████▀▀███";
	c.gotoXY(startX, startY + 1);  cout << u8"███▄  ███";
	c.gotoXY(startX, startY + 2);  cout << u8"████  ███";
	c.gotoXY(startX, startY + 3);  cout << u8"████▄▄███";
	c.textColor(15);
	SetConsoleOutputCP(437);
}
void cMap::levelTwo(int startX, int startY, int color)
{
	cConsole c;
	SetConsoleOutputCP(CP_UTF8);
	c.textColor(color);
	c.gotoXY(startX, startY);      cout << u8"██▀▀▀▀███";
	c.gotoXY(startX, startY + 1);  cout << u8"███▀▀▀▄██";
	c.gotoXY(startX, startY + 2);  cout << u8"██ ██████";
	c.gotoXY(startX, startY + 3);  cout << u8"███▄▄▄▄██";
	c.textColor(15);
	SetConsoleOutputCP(437);
}
void cMap::levelThree(int startX, int startY, int color)
{
	cConsole c;
	SetConsoleOutputCP(CP_UTF8);
	c.textColor(color);
	c.gotoXY(startX, startY);      cout << u8"██▀▀▀▀███";
	c.gotoXY(startX, startY + 1);  cout << u8"███▀▀▀▄██";
	c.gotoXY(startX, startY + 2);  cout << u8"██████ ██";
	c.gotoXY(startX, startY + 3);  cout << u8"██▄▄▄▄███";
	c.textColor(15);
	SetConsoleOutputCP(437);
}
void cMap::levelFour(int startX, int startY, int color)
{
	cConsole c;
	SetConsoleOutputCP(CP_UTF8);
	c.textColor(color);
	c.gotoXY(startX, startY);      cout << u8"██▀▀█████";
	c.gotoXY(startX, startY + 1);  cout << u8"██  █  ██";
	c.gotoXY(startX, startY + 2);  cout << u8"██  ▀  ██";
	c.gotoXY(startX, startY + 3);  cout << u8"█████▄▄██";
	c.textColor(15);
	SetConsoleOutputCP(437);
}
void cMap::processSubScreen()
{
	// Level
	if (level == 1)
	{
		levelOne(104, 7, 233);
		levelTwo(115, 7, 231);
		levelThree(126, 7, 231);
		levelFour(137, 7, 231);
	}
	else if (level == 2)
	{
		levelOne(104, 7, 231);
		levelTwo(115, 7, 237);
		levelThree(126, 7, 231);
		levelFour(137, 7, 231);
	}
	else if (level == 3)
	{
		levelOne(104, 7, 231);
		levelTwo(115, 7, 231);
		levelThree(126, 7, 236);
		levelFour(137, 7, 231);
	}
	else if (level == 4)
	{
		levelOne(104, 7, 231);
		levelTwo(115, 7, 231);
		levelThree(126, 7, 231);
		levelFour(137, 7, 225);
	}
	// Diem
	checkScore();
}
void cMap::checkScore()
{
	cConsole console;
	string scoreTemp = to_string(cMap::score);
	if (scoreTemp.size() == 1)
	{
		console.checkNumber('0', 111, 16, 233);
		console.checkNumber('0', 121, 16, 233);
		console.checkNumber(scoreTemp[0], 131, 16, 233);
	}
	else if (scoreTemp.size() == 2)
	{
		console.checkNumber('0', 111, 16, 233);
		console.checkNumber(scoreTemp[0], 121, 16, 233);
		console.checkNumber(scoreTemp[1], 131, 16, 233);
	}
	else if (scoreTemp.size() == 3)
	{
		console.checkNumber(scoreTemp[0], 111, 16, 233);
		console.checkNumber(scoreTemp[1], 121, 16, 233);
		console.checkNumber(scoreTemp[2], 131, 16, 233);
	}
}
void cMap::miniButton(int startX, int startY, int width, int height, int colorFrame, int colorChar, char character)
{
	cConsole console;
	// In hang ngang tren
	for (int i = 0; i < width; i++)
	{
		console.Draw(startX + i, startY, 223, colorFrame);
	}
	// In hang ngang duoi
	for (int i = 0; i < width; i++)
	{
		console.Draw(startX + i + 1, startY + height, 223, colorFrame);
	}
	// In trai
	for (int i = 0; i < height; i++)
	{
		console.Draw(startX, startY + i, 222, colorFrame);
	}
	// In phai
	for (int i = 0; i < height; i++)
	{
		console.Draw(startX + width, startY + i, 221, colorFrame);
	}
	// In chu
	console.gotoXY(width / 2, height / 2);
	console.textColor(colorChar);
	cout << character;
	console.textColor(15);
}
void cMap::light(int startX, int startY, int colorVang, int colorXam)
{
	//if (color == 0) color = 4;
	//else color = 2;
	cConsole c;
	SetConsoleOutputCP(CP_UTF8);
	c.textColor(colorVang);
	c.gotoXY(startX, startY);      cout << u8"██";
	c.gotoXY(startX, startY + 1);  cout << u8"██";
	c.gotoXY(startX, startY + 2);  cout << u8"██";
	c.gotoXY(startX, startY + 3);  cout << u8"██";
	c.gotoXY(startX, startY + 4);  cout << u8"██";
	c.gotoXY(startX, startY + 5);  cout << u8"██";
	c.textColor(15);
	SetConsoleOutputCP(437);
}
void cMap::output(bool Sound) {
flag:
	flagMenu = false;
	processSubScreen();
	if (score >= 250) speed = 2;
	else speed = 30 - (5 * (score / 50));
	if (!flagCreateObject) {
		temp.setNumberObject(5+ 2 * level);
		temp.Creat_Object();
		listObject = temp.getList();
		flagCreateObject = true;
	}
	flagLoad = false; // Gán biến nhận biết có thực hiện chức năng load là không
	flagSave = false;// Gán biến nhận biết có thực hiện chức năng save là không
	people.assignX(20);// Khởi tạo tọa độ x cho người
	people.assignY(35); // Khởi tạo tọa độ y cho người
	people.assignStatus(true); // Khởi tạo trạng thái cho người
	people.shape();// vẽ người
	start = clock();// Bắt đầu đếm thời gian
	subScreen(101,0,47,39,238);
	Yard();
	cConsole c;
	flagStop = 0;
	while (people.getStatus())
	{
		// Kiem tra va chạm
		if (!flagLoad && !flagSave && flagStop == 0) // Kiem tra xem co thuc hien tinh nang load game khong neu co cho dung vat can
		{
			if (MOVING_CHARACTER == 'Q') {
				flagMenu = true;
				people.assignStatus(false);
				MOVING_CHARACTER = 0;
				temp.~cListObject();
				temp.setOrderObject(0);
				flagCreateObject = false;
				level = 1;
				score = 0;
				break;
			}
			if (people.checkCollision(listObject))
			{
				//hiệu ứng chết
				people.effectDead();
				MOVING_CHARACTER = 0;
				people.assignStatus(false);
				cLoad_HighScore c;
				c.baseBackground(29, 16, 43, 8, 2);
				while (!(MOVING_CHARACTER == 'Y' || MOVING_CHARACTER == 'N')) {
					if (MOVING_CHARACTER != 0 && !(MOVING_CHARACTER == 'Y' || MOVING_CHARACTER == 'N')) MOVING_CHARACTER = toupper(_getch());
				}
				if (MOVING_CHARACTER == 'Y') {
					temp.~cListObject();
					temp.setOrderObject(0);
					flagCreateObject = false;
					level = 1;
					score = 0;
					goto flag;
				}
				if (MOVING_CHARACTER == 'N') {
					c.baseBackground(29, 16, 43, 8, 3);
					MOVING_CHARACTER = 0;
					while (!(MOVING_CHARACTER == 'Y' || MOVING_CHARACTER == 'Q')) {
						if (MOVING_CHARACTER != 0 && !(MOVING_CHARACTER == 'Y' || MOVING_CHARACTER == 'Q')) MOVING_CHARACTER = toupper(_getch());

					}
					if (MOVING_CHARACTER == 'Q') {
						flagMenu = true;
						temp.~cListObject();
						temp.setOrderObject(0);
						flagCreateObject = false;
						people.assignStatus(false);
						level = 1;
						score = 0;
						MOVING_CHARACTER = 0;
						break;
					}
					if (MOVING_CHARACTER == 'Y') {
						this->processEnd();
						temp.~cListObject();
						temp.setOrderObject(0);
						flagCreateObject = false;
						level = 1;
						score = 0;
						flagMenu = true;
					}
				}

			}
			else {
				processMovePeople(Sound); // Xử lý di chuyển người
				redrawLine();// Vẽ lại đường phân cách
				redrawStartAndPeople(); // Vẽ người hoặc chữ start
				redrawTrafficLight(); // Vẽ lại đèn giao thông
				redrawObject();// Vẽ vật cản
				bool check = redrawEnd(Sound);// Vẽ lại khung end
				if (check == true) {
					flagCreateObject = false;
					temp.~cListObject();
					temp.setOrderObject(0);
					people.assignStatus(false);
					system("cls");
					goto flag;
				}
				Sleep(speed); // Nghỉ 
			}
			end = clock();// Bấm thời gian kết thúc
			timeUse = (double)(end - start) / CLOCKS_PER_SEC; // Đo thời gian thực
			flagMove = false; // Gán biến di chuyển là false tương ứng người đang đứng yên
			flagStop = 0;
		}
		else {
			if (flagStop == 2) {
				flagStop = 0;
				subScreen(101, 0, 47, 39, 238);
				//processSubScreen();
			}
			else if (flagStop == 0) {
				flagStop = 1;
			} // Vật cản đã dừng
			else if (flagStop == 1 && flagLoad == false && flagSave == false) {
				flagStop = 0;
				temp.~cListObject();
				temp.setOrderObject(0);
				flagCreateObject = false;
				goto flag;
			}
		}
	}
}
void cMap::threadFunc() {
	people.assignStatus(true);
	while ((people.getStatus() || MOVING_CHARACTER != 'N' || MOVING_CHARACTER != 'Q') && flagMenu == false)
	{
		if (MOVING_CHARACTER == 'L') // Thực hiện chức năng load
		{
			flagLoad = true;
		}
		if (flagStop == 1 && flagLoad) {
			cConsole c;
			cLoad_HighScore temp;
			temp.processLoadinGame(level, score);
			c.textColor(15);
			flagLoad = false;
		} // Nhận biết thực hiện load
		if (MOVING_CHARACTER == 'T') // Xử lý save
		{
			flagSave = true;
		}
		if (flagStop == 1 && flagSave) {
			cLoad_HighScore temp;
			playerName = temp.processSave(level, score);
			flagHighScore = 1;
			flagSave = false;
			flagStop = 2;
		} // Nhận biết thực hiện save
		if (((people.getStatus() && !flagLoad && !flagSave)  || MOVING_CHARACTER == 'N') && MOVING_CHARACTER != 'Q') // Nếu không load thì di chuyển tiếp
		{
			MOVING_CHARACTER = toupper(_getch());// Láy kí tự
		}
	}
}
void cMap::redrawTrafficLight()
{
	if (timeUse >= 2 && !flagLoad) // Xử lý bật tắt đèn giao thông sau mỗi 2s
	{
		start = clock();
		for (int i = 0; i < 4; i++)
		{
			if (sign[i] != 0) sign[i] = rand() % 2;
			else sign[i] = 1;
		}
		for (int i = 0; i < 4; i++)
		{
			if (sign[i] == 1) // Den do
			{
				light(100, 7 * (i + 1) - 1, 234, 122);
			}
			else if (sign[i] == 0) // Den xanh
			{
				light(100, 7 * (i + 1) - 1, 236, 114);
			}
		}
	}
}
void cMap::processMovePeople(bool Sound)
{
	if (toupper(MOVING_CHARACTER) == 'A' && people.getX() > 1) // Xử lý di chuyển sang trái
	{
		if(Sound == true)
			PlaySound(TEXT("sounds\\step.wav"), NULL, SND_ASYNC || SND_LOOP);
		redrawEnd(Sound);
		people.MoveLeft();
		flagMove = true;
		MOVING_CHARACTER = 0;
	}
	if (toupper(MOVING_CHARACTER) == 'D' && people.getX() + people.getWidth() < 99)// Xử lý di chuyển sang phải
	{
		if (Sound == true)
			PlaySound(TEXT("sounds\\step.wav"), NULL, SND_ASYNC || SND_LOOP);
		redrawEnd(Sound);
		people.MoveRight();
		flagMove = true;
		MOVING_CHARACTER = 0;
	}
	if (toupper(MOVING_CHARACTER) == 'W' && people.getY() > 1)// Xử lý di chuyển lên
	{
		if (Sound == true)
			PlaySound(TEXT("sounds\\step.wav"), NULL, SND_ASYNC || SND_LOOP);
		redrawEnd(Sound);
		people.MoveUp();
		flagMove = true;
		MOVING_CHARACTER = 0;
	}
	if (toupper(MOVING_CHARACTER) == 'S' && people.getY() + people.getHeight() < 38)// Xử lý di chuyển xuống
	{
		if (Sound == true)
			PlaySound(TEXT("sounds\\step.wav"), NULL, SND_ASYNC || SND_LOOP);
		redrawEnd(Sound);
		people.MoveDown();
		flagMove = true;
		MOVING_CHARACTER = 0;
	}
}
bool cMap::redrawEnd(bool Sound)
{
	cConsole c;
	if (people.getY() <= 5 && flagMove) // Vẽ lại khung end và không vẽ ở vị trí con người đang đứng
	{
		for (int i = 0; i < 100; i += 2)
		{
			for (int j = 1; j < 5; j++)
			{
				if (j % 2 == 0 && (!(i >= people.getX() - 2 && i < people.getX() + people.getWidth() && j >= people.getY() && j < people.getY() + people.getHeight()) || people.getY() + people.getHeight() == 5))
				{
					c.Draw(i + 1, j, 219, 15);
					if (i < 99)
					{
						c.Draw(i + 2, j, ' ', 15);
					}
				}
				else if (((!(i >= people.getX() - 2 && i < people.getX() + people.getWidth() && j >= people.getY() && j < people.getY() + people.getHeight()))) || people.getY() + people.getHeight() == 5)
				{
					c.Draw(i, j, 219, 15);
					if (i < 100)
					{
						c.Draw(i + 1, j, ' ', 15);
					}
				}

			}
		}
		for (int j = 1; j < 100; j += 2)
		{
			if (j % 2 != 0)
			{
				c.Draw(j, 5, 205, 118);
			}
		}
		if (people.getY() + people.getHeight() == 5)// Khi người đứng hoàn toàn trong khung end thì quay lại start
		{
			if (Sound == true)
				PlaySound(TEXT("sounds\\winning.wav"), NULL, SND_ASYNC || SND_LOOP);
			if (speed > 5) {
				speed -= 5;
			}
			if (level == 4) {
				temp.~cListObject();
				temp.setOrderObject(0);
				flagCreateObject = false;
				level = 1;
			}
			else { 
				level++;
			}
			score += 50;
			people.assignX(50);
			people.assignY(35);
			return true;
		}
	}
	people.shape();
	return false;
}
void cMap::redrawLine()
{
	cConsole c;
	// Xử lý cán vạch phân cách ở tọa độ x = 12
	if ((people.getY() + people.getHeight() + 2 >= 12 && people.getY() <= 12 && flagMove) || people.getY() - 1 == 12 || people.getY() - 2 == 12 || people.getY() + people.getHeight() == 12)
	{
		for (int j = 1; j < 100; j += 2)
		{
			if (j % 2 != 0)
			{
				c.Draw(j, 12, 205, 118);
			}
		}
		flagMove = false;
	}
	// Xử lý cán vạch phân cách ở tọa độ x = 19
	if ((people.getY() + people.getHeight() + 2 >= 19 && people.getY() <= 19 && flagMove) || people.getY() - 1 == 19 || people.getY() - 2 == 19 || people.getY() + people.getHeight() == 19)
	{
		for (int j = 1; j < 100; j += 2)
		{
			if (j % 2 != 0)
			{
				c.Draw(j, 19, 205, 118);
			}
		}
		flagMove = false;
	}
	// Xử lý cán vạch phân cách ở tọa độ x = 26
	if ((people.getY() + people.getHeight() + 2 >= 26 && people.getY() <= 26 && flagMove) || people.getY() - 1 == 26 || people.getY() - 2 == 26 || people.getY() + people.getHeight() == 26)
	{
		for (int j = 1; j < 100; j += 2)
		{
			if (j % 2 != 0)
			{
				c.Draw(j, 26, 205, 118);
			}
		}
		flagMove = false;
	}
	// Xử lý cán vạch phân cách ở tọa độ x = 33
	if ((people.getY() + people.getHeight() + 2 >= 33 && people.getY() <= 33 && flagMove) || people.getY() - 1 == 33 || people.getY() - 2 == 33 || people.getY() + people.getHeight() == 33)
	{
		for (int j = 1; j < 100; j += 2)
		{
			if (j % 2 != 0)
			{
				c.Draw(j, 33, 205, 118);
			}
		}
		flagMove = false;
	}
}
void cMap::redrawObject()
{
	for (int i = 0; i < listObject.size(); i++)
	{
		// Xử lý chướng ngại vật đi sang phải
		if ((listObject[i]->getStatus() == 0 || listObject[i]->getStatus() == 3) && sign[listObject[i]->getSign()] != 0)
		{
			if (listObject[i]->getX() == 100 + listObject[i]->getConstWidth()) // Xử lý vạt thể chui vào hoàn toàn
			{
				listObject[i]->assignWidth(listObject[i]->getConstWidth());
				listObject[i]->assignStatus(0);
				listObject[i]->assignX(-listObject[i]->getConstWidth());
			}
			else
				if (listObject[i]->getX() >= 100)// Xử lý vật thể đang chui vào
				{
					listObject[i]->assignStatus(3);
					listObject[i]->assignWidth(listObject[i]->getWidth() - 1);
					listObject[i]->shape();
					listObject[i]->assignX(listObject[i]->getX() + 1);
				}
				else // Xử lý vật thể di chuyển bình thường
				{
					listObject[i]->shape();
					listObject[i]->assignX(listObject[i]->getX() + 1);
				}
		}
		else
			// Xử lý chướng ngại vật đi sang trái
			if ((listObject[i]->getStatus() == 1 || listObject[i]->getStatus() == 4) && sign[listObject[i]->getSign()] != 0)
			{
				if (listObject[i]->getX() == -(listObject[i]->getConstWidth() + 1)) // Xử lý vạt thể chui vào hoàn toàn
				{
					listObject[i]->assignWidth(listObject[i]->getConstWidth());
					listObject[i]->assignStatus(1);
					listObject[i]->assignX(100);
				}
				else
					if (listObject[i]->getX() <= 0) // Xử lý vạt thể đang chui vào 
					{
						listObject[i]->assignStatus(4);
						listObject[i]->assignWidth(listObject[i]->getWidth() - 1);
						listObject[i]->shape();
						listObject[i]->assignX(listObject[i]->getX() - 1);
					}
					else  // Xử lý vật thể di chuyển bình thường
					{
						listObject[i]->shape();
						listObject[i]->assignX(listObject[i]->getX() - 1);
					}
			}
	}
}
void cMap::redrawStartAndPeople()
{
	cConsole c;
	if (people.getChange() == 0)// Xử lý vẽ lại người hoặc chữ start khi người chơi di chuyển sang trái
	{
		c.textColor(193);// Màu sắc con người
		// Xóa phần đuôi thừa
		for (int i = 0; i < 3; i++)
		{
			c.gotoXY(people.getX() + 6, people.getY() + i);
			c.textColor(127);
			cout << " ";
			c.textColor(15);
		}
		// Vẽ lại chữ start
		if (((people.getY() + people.getHeight() >= 34 && people.getY() + people.getHeight() <= 38) || ((people.getY() <= 38 && people.getY() + people.getHeight() >= 38)) && flagMove) && people.getX() + people.getWidth() - 1 >= 36 && people.getX() <= 63)
		{
			c.textColor(116);
			SetConsoleOutputCP(CP_UTF8);
			c.gotoXY(36, 34);
			cout << u8".▄▄ · ▄▄▄▄▄ ▄▄▄· ▄▄▄  ▄▄▄▄▄";
			c.gotoXY(36, 35);
			cout << u8"▐█ ▀. •██  ▐█ ▀█ ▀▄ █·•██  ";
			c.gotoXY(36, 36);
			cout << u8"▄▀▀▀█▄ ▐█.▪▄█▀▀█ ▐▀▀▄  ▐█.▪";
			c.gotoXY(36, 37);
			cout << u8"▐█▄▪▐█ ▐█▌·▐█ ▪▐▌▐█•█▌ ▐█▌·";
			SetConsoleOutputCP(437);
			flagMove = false;
		}
		people.shape(); // Vẽ lại người
		people.assignChange(-1); // Gán thay đổi lại cho người
		c.textColor(15);
	}
	else
		if (people.getChange() == 1)	// Xử lý vẽ lại người hoặc chữ start khi người chơi di chuyển sang phải
		{
			c.textColor(193); // Màu sắc con người
			// Xóa phần đuôi thừa
			for (int i = 0; i < 3; i++)
			{
				c.gotoXY(people.getX() - 1, people.getY() + i);
				c.textColor(127);
				cout << " ";
				c.textColor(15);
			}
			// Vẽ lại chữ start
			if (((people.getY() + people.getHeight() >= 34 && people.getY() + people.getHeight() <= 38) || ((people.getY() <= 38 && people.getY() + people.getHeight() >= 38)) && flagMove) && people.getX() + people.getWidth() - 1 >= 36 && people.getX() <= 63)
			{
				c.textColor(116);
				SetConsoleOutputCP(CP_UTF8);
				c.gotoXY(36, 34);
				cout << u8".▄▄ · ▄▄▄▄▄ ▄▄▄· ▄▄▄  ▄▄▄▄▄";
				c.gotoXY(36, 35);
				cout << u8"▐█ ▀. •██  ▐█ ▀█ ▀▄ █·•██  ";
				c.gotoXY(36, 36);
				cout << u8"▄▀▀▀█▄ ▐█.▪▄█▀▀█ ▐▀▀▄  ▐█.▪";
				c.gotoXY(36, 37);
				cout << u8"▐█▄▪▐█ ▐█▌·▐█ ▪▐▌▐█•█▌ ▐█▌·";
				SetConsoleOutputCP(437);
				flagMove = false;
			}
			people.shape();// Vẽ lại người
			people.assignChange(-1);// Gán thay đổi lại cho người
			c.textColor(15);
		}
		else
			if (people.getChange() == 2)	// Xử lý vẽ lại người hoặc chữ start khi người chơi di chuyển xuống
			{
				c.textColor(193);// Màu sắc con người
				// Xóa phần đuôi thừa
				for (int i = 0; i < 8; i++)
				{
					c.gotoXY(people.getX() + i, people.getY() - 1);
					c.textColor(127);
					cout << " ";
					c.textColor(15);
				}
				// Vẽ lại chữ start
				if (((people.getY() + people.getHeight() >= 34 && people.getY() + people.getHeight() <= 38) || ((people.getY() <= 38 && people.getY() + people.getHeight() >= 38)) && flagMove) && people.getX() + people.getWidth() - 1 >= 36 && people.getX() <= 63)
				{
					c.textColor(116);
					SetConsoleOutputCP(CP_UTF8);
					c.gotoXY(36, 34);
					cout << u8".▄▄ · ▄▄▄▄▄ ▄▄▄· ▄▄▄  ▄▄▄▄▄";
					c.gotoXY(36, 35);
					cout << u8"▐█ ▀. •██  ▐█ ▀█ ▀▄ █·•██  ";
					c.gotoXY(36, 36);
					cout << u8"▄▀▀▀█▄ ▐█.▪▄█▀▀█ ▐▀▀▄  ▐█.▪";
					c.gotoXY(36, 37);
					cout << u8"▐█▄▪▐█ ▐█▌·▐█ ▪▐▌▐█•█▌ ▐█▌·";
					SetConsoleOutputCP(437);
					flagMove = false;
				}
				people.shape(); // Vẽ  lại người
				people.assignChange(-1);// Gán thay đổi lại cho người
				c.textColor(15);
			}
			else
				if (people.getChange() == 3)	// Xử lý vẽ lại người hoặc chữ start khi người chơi di chuyển lên
				{
					c.textColor(193);// Màu sắc con người
					// Xóa phần đuôi thừa
					for (int i = 0; i < 8; i++)
					{
						c.gotoXY(people.getX() + i, people.getY() + 3);
						c.textColor(127);
						cout << " ";
						c.textColor(15);
					}
					// Vẽ lại chữ start
					if (((people.getY() + people.getHeight() >= 34 && people.getY() + people.getHeight() <= 38) || ((people.getY() <= 38 && people.getY() + people.getHeight() >= 38)) && flagMove) && people.getX() + people.getWidth() - 1 >= 36 && people.getX() <= 63)
					{
						c.textColor(116);
						SetConsoleOutputCP(CP_UTF8);
						c.gotoXY(36, 34);
						cout << u8".▄▄ · ▄▄▄▄▄ ▄▄▄· ▄▄▄  ▄▄▄▄▄";
						c.gotoXY(36, 35);
						cout << u8"▐█ ▀. •██  ▐█ ▀█ ▀▄ █·•██  ";
						c.gotoXY(36, 36);
						cout << u8"▄▀▀▀█▄ ▐█.▪▄█▀▀█ ▐▀▀▄  ▐█.▪";
						c.gotoXY(36, 37);
						cout << u8"▐█▄▪▐█ ▐█▌·▐█ ▪▐▌▐█•█▌ ▐█▌·";
						SetConsoleOutputCP(437);
						flagMove = false;
					}
					people.assignChange(-1);// Gán thay đổi lại cho người
					people.shape(); // Vẽ lại người
					c.textColor(15);
				}
}
void cMap::processEnd()
{
	cConsole c;
	c.textColor(15);
	people.assignStatus(false);
	if (flagHighScore == 1) {
		cLoad_HighScore a;
		a.setdata(playerName, level, score);
		a.datatoFileforHighScore("highscore.txt");
	}
	else {
		cLoad_HighScore a;
		string name;
		a.baseBackground(29, 16, 43, 8, 4);
		c.gotoXY(31, 22);
		c.assignFlag(true);
		c.ShowConsoleCursor();
		c.inputName(name, 31, 22);
		c.assignFlag(false);
		c.ShowConsoleCursor();
		a.setdata(name, level, score);
		a.datatoFileforHighScore("highscore.txt");
		c.textColor(15);
	}
}
