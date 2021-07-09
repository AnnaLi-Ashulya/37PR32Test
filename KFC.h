#pragma once
#include "Order.h"

class KFC
{
	int amountOfOrder;
	Order* arr;

public:
	KFC();
	~KFC();

	void addOrder(Order obj);
	void sortOrders();
	void showTable();
	void takeOrder();
};

