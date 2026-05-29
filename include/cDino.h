#pragma once
#include "cObject.h"
class cDino : public cObject
{
public:
	void create(int);
	void assignInitSize();
	void checkColor(int i, int j);
	void tell();
};

