#include "cListObject.h"
int cListObject::numberObject = 7;
int cListObject::orderObject = 0; // Số lượng vật cản
vector<cObject*> cListObject::list = {};
cListObject::~cListObject() {
	cObject* temp;
	for (int i = 0; i < list.size(); i++) {
		temp = list[list.size()-1];
		list.pop_back();
		delete temp;
		temp = NULL;
		i = -1;
	}
}
void cListObject::setNumberObject(int num) {
	this->numberObject = num;
}
void cListObject::setOrderObject(int num){
	this->orderObject = num;
}
void cListObject::Creat_Object()
{
	int Distance_Y = 6; // Gán tọa độ Y cho vật thể
	int Distance_Plus = 3;// Khoảng cách bù thêm giữa các xe để tạo nên điểm dừng ở trên dưới
	int sign_Stop_Or_Move = 0;// Tín hiệu nhận biết xe đang ở làn nào để xử lý với đèn giao thông làn đó
	for (int i = 0; i < list.size(); i++)
	{
		int Distance_X = 0;
		if (Distance_Y > 30) // Cập nhật lại biến thành làn đầu tiên khi biến đã chạm làn cuối cùng
		{
			Distance_Y = 6;
			sign_Stop_Or_Move = 0;
		}
		for (int j = 0; j < i; j++)
		{
			if (Distance_Y == list[j]->getY())
			{
				Distance_X++; // Khi đã có xe ở vị trí x định gán thì lùi xe về sau;
			}
		}
		if (Distance_Plus == 3) // Nhận biết có tạo điểm dừng chân cho người chơi
		{
			list[i]->assignX(-list[i]->getWidth() - 1 - Distance_X * 50); // Gán tọa x độ cho vật thể 
			list[i]->assignY(Distance_Y);// Gán tọa y độ cho vật thể 
			Distance_Y = Distance_Y + Distance_Plus + list[i]->getHeight(); // Tăng tọa độ Y cho vật thể ương ứng vị trí làn kế tiếp để gán cho vật thể tiếp theo
			Distance_Plus = 1; // Nhận biết không tạo điểm dừng chân cho người chơi hay không
			list[i]->assignStatus(0); // Nhận biết vật thể di chuyển sang phải
		}
		else
		{
			list[i]->assignX(100 + list[i]->getWidth() - 1 + Distance_X * 50); // Gán tọa x độ cho vật thể 
			list[i]->assignY(Distance_Y);// Gán tọa y độ cho vật thể 
			Distance_Y = Distance_Y + Distance_Plus + list[i]->getHeight();// Tăng tọa độ Y cho vật thể ương ứng vị trí làn kế tiếp để gán cho vật thể tiếp theo
			Distance_Plus = 3;// Nhận biết có tạo điểm dừng chân cho người chơi hay không
			list[i]->assignStatus(1);// Nhận biết vật thể di chuyển sang trái
		}
		list[i]->assignSign(sign_Stop_Or_Move); // Gán tín hiệu nhận biết đèn giao thông ở làn đó
		list[i]->create(list[i]->getStatus());
		sign_Stop_Or_Move++;// Tăng thêm tín hiệu nhận biết xe đang ở làn nào để xử lý với đèn giao thông làn đó
	}
	while (orderObject < numberObject)
	{
		int Distance_X = 0; // biến tạo khoảng cách giữa các xe chung làn
		int randShape = rand() % 4;
		cObject* temp = NULL;
		if (Distance_Y > 30) // Cập nhật lại biến thành làn đầu tiên khi biến đã chạm làn cuối cùng
		{
			Distance_Y = 6;
			sign_Stop_Or_Move = 0;
		}
		if (Distance_Y >= 5 && Distance_Y < 12) {
			temp = new cCar;
		}
		else if (Distance_Y >= 12 && Distance_Y < 19) {
			temp = new cTruck;
		}
		else if (Distance_Y >= 19 && Distance_Y < 26) {
			temp = new cDino;
		}
		else {
			temp = new cBird;
		}
		temp->assignInitSize();
		for (int i = 0; i < list.size(); i++)
		{
			if (Distance_Y == list[i]->getY())
			{
				Distance_X++; // Khi đã có xe ở vị trí x định gán thì lùi xe về sau;
			}
		}
		if (Distance_Plus == 3) // Nhận biết có tạo điểm dừng chân cho người chơi
		{
			temp->assignX(-temp->getWidth() - 1 - Distance_X * 50); // Gán tọa x độ cho vật thể 
			temp->assignY(Distance_Y);// Gán tọa y độ cho vật thể 
			Distance_Y = Distance_Y + Distance_Plus + temp->getHeight(); // Tăng tọa độ Y cho vật thể ương ứng vị trí làn kế tiếp để gán cho vật thể tiếp theo
			Distance_Plus = 1; // Nhận biết không tạo điểm dừng chân cho người chơi hay không
			temp->assignStatus(0); // Nhận biết vật thể di chuyển sang phải
		}
		else
		{
			temp->assignX(100 + temp->getWidth() - 1 + Distance_X * 50); // Gán tọa x độ cho vật thể 
			temp->assignY(Distance_Y);// Gán tọa y độ cho vật thể 
			Distance_Y = Distance_Y + Distance_Plus + temp->getHeight();// Tăng tọa độ Y cho vật thể ương ứng vị trí làn kế tiếp để gán cho vật thể tiếp theo
			Distance_Plus = 3;// Nhận biết có tạo điểm dừng chân cho người chơi hay không
			temp->assignStatus(1);// Nhận biết vật thể di chuyển sang trái
		}

		temp->assignSign(sign_Stop_Or_Move); // Gán tín hiệu nhận biết đèn giao thông ở làn đó
		temp->create(temp->getStatus());
		list.push_back(temp);// Đưa vật thể vào vector
		orderObject++;// Tăng biến đếm số lượng vật thể
		sign_Stop_Or_Move++;// Tăng thêm tín hiệu nhận biết xe đang ở làn nào để xử lý với đèn giao thông làn đó
	}
}
vector<cObject*> cListObject::getList() {
	vector<cObject*> temp;
	for (int i = 0; i < this->list.size(); i++) {
		cObject* ob(list[i]);
		temp.push_back(ob);
	}
	return temp;
}
