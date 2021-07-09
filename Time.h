#pragma once
#include <iostream>
#include <ctime>

using namespace std;

class Time
{
	int hour;
	int minutes;
	int seconds;
	char format[4];// am/pm (12-hours), utc (24-hours)

public:
	Time(); // Current local time
	Time(int hour, int minutes, int seconds, const char* format = "utc");
	Time(const Time& obj);
	~Time();

	void setHour(int hour);
	int getHour() const&;
	void setMinutes(int minutes);
	int getMinutes() const&;
	void setSeconds(int seconds);
	int getSeconds() const&;
	void setFormat(const char* format); // !!! to update time by the new format: utc to pm
	const char* getFormat() const&; //utc/am/pm

	bool valid(); //time check
	void tickTime(); //every tick add one second
	void tickBack(); //every tick take away one second
	void showTime(); //show time by the format

	//--------- Comparison operators ---------
	bool operator == (const Time& obj) const&;
	bool operator != (const Time& obj) const&;
	bool operator > (const Time& obj) const&;
	bool operator < (const Time& obj) const&;
	bool operator >= (const Time& obj) const&;
	bool operator <= (const Time& obj) const&;

	//--------- Assignment operators ---------
	Time& operator = (const Time& obj);
	Time& operator += (int n);
	Time& operator -= (int n);

	//--------- Arithmetic operators ---------
	Time operator + (int n);
	Time operator - (int n);

	//---------перезгрузка инкремента и дикримента
	Time& operator -- ();
	Time operator --(int n);
	Time& operator ++ ();
	Time operator ++(int n);

	//----------перегрузка ввода и ввыда-------
	friend ostream& operator << (ostream& os, const Time& t);
	friend istream& operator >> (istream& is, Time& t);
};


