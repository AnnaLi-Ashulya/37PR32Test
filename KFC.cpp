#include "KFC.h"

KFC::KFC()
{
	this->amountOfOrder = 0;
	this->arr = NULL;
}

KFC::~KFC()
{
	if (arr != NULL) {
		delete[] arr;
	}
}

void KFC::addOrder(Order obj)
{
	//Order* tmp = new Order[++amountOfOrder];
	if (amountOfOrder == 0) {
		amountOfOrder = 1;
		arr = new Order[1];
		arr[0] = obj;
	}
	else {
		Order* tmp = new Order[++amountOfOrder];
		int pos = amountOfOrder - 1;
		for (int i = 0; i < amountOfOrder-1; i++) {
			if (obj.getReadyTime() < arr[i].getReadyTime()) {
				pos = i;//сохран€ем положение дл€ добавлени€ элемента
				break;
			}
		}
		for (int i = 0; i < amountOfOrder; i++) {
			if (i < pos) {
				tmp[i] = arr[i];
			}
			else if (i == pos) {
				tmp[i] = obj;
			}
			else {
				tmp[i] = arr[i - 1];
			}
		}
		delete[]arr;
		arr = tmp;
	}
}

void KFC::sortOrders()
{
}

void KFC::showTable()
{
	for (int i = 0; i < amountOfOrder; i++) {
		cout << arr[i] << "\n";
	}
}

void KFC::takeOrder()
{
	if (amountOfOrder == 0) {
		cout << "List of orders is empty!\n";
	}
	else {
		cout << "Your order: " << arr[0] << "\n";
		Order* tmp = new Order[--amountOfOrder];
		for (int i = 0; i < amountOfOrder; i++) {
			tmp[i] = arr[i + 1];
		}
		if (arr != NULL) {
			delete[]arr;
		}
		arr = tmp;
	}
}
