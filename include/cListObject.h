#pragma once
#include "cObject.h"
#include "cCar.h"
#include "cTruck.h"
#include "cBird.h"
#include "cDino.h"
#include <vector>
class cListObject
{
private:
	static vector<cObject*> list;
	static int numberObject;
	static int orderObject;
public:
	~cListObject();
	void Creat_Object(); // Tạo ra danh sách vật cản
	vector<cObject*> getList();
	void setNumberObject(int num);
	void setOrderObject(int num);
};

