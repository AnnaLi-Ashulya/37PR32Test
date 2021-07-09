#pragma once
#include "Date.h"
#include "Time.h"

class Order
{
	Date dateOrder;
	Time timeOrder;
	char* discription;
	int readyMinutes;
	float price;
	int number;

	static int amount;

public:
	Order();
	Order(Date dateOrder, Time timeOrder, const char* discription, int readyMinutes,
		float price);
	~Order();
	Order(const Order& obj);
	Order& operator =(const Order& obj);

	friend ostream & operator << (ostream & ot, const Order& obj);

	Time getReadyTime();
};

