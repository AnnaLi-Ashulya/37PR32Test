#include "Order.h"

Order::Order()
{
	this->dateOrder = Date();
	this->timeOrder = Time();
	this->readyMinutes = 1;
	this->price = 10;
	this->discription = new char[] {"Name"};
	this->number = 0;
}

Order::Order(Date dateOrder, Time timeOrder,
	const char* discription, int readyMinutes, float price)
{
	this->dateOrder = dateOrder;
	this->timeOrder = timeOrder;
	this->readyMinutes = readyMinutes;
	this->price = price;
	this->discription = new char[strlen(discription) + 1];
	strcpy_s(this->discription, strlen(discription) + 1, discription);
	this->number = ++amount;
}

Order::~Order()
{
	delete[] discription;
}

Order::Order(const Order& obj)
{
	this->dateOrder = obj.dateOrder;
	this->timeOrder = obj.timeOrder;
	this->readyMinutes = obj.readyMinutes;
	this->price = obj.price;
	this->discription = new char[strlen(obj.discription) + 1];
	strcpy_s(this->discription, strlen(obj.discription) + 1, obj.discription);
	this->number = obj.number;
}

Order& Order::operator=(const Order& obj)
{
	this->dateOrder = obj.dateOrder;
	this->timeOrder = obj.timeOrder;
	this->readyMinutes = obj.readyMinutes;
	this->price = obj.price;
	this->discription = new char[strlen(obj.discription) + 1];
	strcpy_s(this->discription, strlen(obj.discription) + 1, obj.discription);
	this->number = obj.number;

	return *this;
}

Time Order::getReadyTime()
{
	return this->timeOrder + this->readyMinutes * 60;
}

ostream& operator<<(ostream& ot, const Order& obj)
{
	Time ready = obj.timeOrder;
	ready += (obj.readyMinutes * 60);
	ot << "Number# " << obj.number << " : "
		<< obj.discription << " - " << ready << "\n";
	return ot;
}
