#include "Time.h"

Time::Time()
{
	time_t NOW = time(NULL);
	tm obj;
	localtime_s(&obj, &NOW);
	this->hour = obj.tm_hour;
	this->minutes = obj.tm_min;
	this->seconds = obj.tm_sec;
	strcpy_s(this->format, 4, "24h");
}

Time::Time(int hour, int minutes, int seconds, const char* format)
{
	strcpy_s(this->format, 4, format);
	if (valid()) {
		this->hour = hour;
		this->minutes = minutes;
		this->seconds = seconds;
	}
}

Time::Time(const Time& obj)
{
	strcpy_s(this->format, 4, obj.format);
	this->hour = obj.hour;
	this->minutes = obj.minutes;
	this->seconds = obj.seconds;
}

Time::~Time(){}

void Time::setHour(int hour)
{
	if (valid()) 
		this->hour = hour;
}

int Time::getHour() const&
{
	return this->hour;
}

void Time::setMinutes(int minutes)
{
	if (valid()) 
		this->minutes = minutes;
}

int Time::getMinutes() const&
{
	return this->minutes;
}

void Time::setSeconds(int seconds)
{
	if (valid()) 
		this->seconds = seconds;
}

int Time::getSeconds() const&
{
	return this->seconds;
}

void Time::setFormat(const char* format)
{
	strcpy_s(this->format, 4, format);
	if (format == "12h") {
		if (hour == 0)hour = 12;
		else if (hour > 12)hour -= 12;
	}
}

const char* Time::getFormat() const&
{
	return this->format;
}

bool Time::valid()
{
	if (format == "24h") {
		if (hour >= 0 && hour < 24 && minutes >= 0 && minutes < 60 && 
			seconds >= 0 && seconds < 60)
			return true;
		else 
			return false;
	}
	if (format == "12h") {
		if (hour > 0 && hour <= 12 && minutes >= 0 && minutes < 60 && 
			seconds >= 0 && seconds < 60)
			return true;
		else 
			return false;
	}
}

void Time::tickTime()
{
	if (strcmp(this->format, "24h")==0) {
		if (hour == 23 && minutes == 59 && seconds == 59) {
			hour = 0;
			minutes = 0;
			seconds = 0;
		}
		else if (minutes == 59 && seconds == 59) {
			minutes = 0;
			seconds = 0;
			hour++;
		}
		else if (seconds == 59) {
			minutes++;
			seconds = 0;
		}
		else seconds++;
	}
	if (strcmp(this->format, "12h")==0) {
		if (hour == 12 && minutes == 59 && seconds == 59) {
			hour = 1;
			minutes = 0;
			seconds = 0;
		}
		else if (minutes == 59 && seconds == 59) {
			minutes = 0;
			seconds = 0;
			hour++;
		}
		else if (seconds == 59) {
			minutes++;
			seconds = 0;
		}
		else seconds++;
	}
}

void Time::tickBack()
{
	if (this->format == "24h") {
		if (hour == 0 && minutes == 0 && seconds == 0) {
			hour = 23;
			minutes = 59;
			seconds = 59;
		}
		else if (minutes == 0 && seconds == 0) {
			minutes = 59;
			seconds = 59;
			hour--;
		}
		else if (seconds == 0) {
			minutes--;
			seconds = 59;
		}
		else seconds--;
	}
	if (this->format == "12h") {
		if (hour == 12 && minutes == 0 && seconds == 0) {
			hour = 11;
			minutes = 59;
			seconds = 59;
		}
		else if (minutes == 0 && seconds == 0) {
			minutes = 59;
			seconds = 59;
			hour--;
		}
		else if (seconds == 0) {
			minutes--;
			seconds = 59;
		}
		else seconds--;
	}
}

void Time::showTime()
{
	cout << "Format= " << this->format << "   ";
	cout << hour / 10 << hour % 10 << ":" << minutes / 10 << minutes % 10 
		<< ":" << seconds / 10 << seconds % 10 << endl;
}

bool Time::operator==(const Time& obj) const&
{
	return (this->hour == obj.hour && this->minutes == obj.minutes && 
		this->seconds == obj.seconds && this->format == obj.format);
}

bool Time::operator!=(const Time& obj) const&
{
	return !(*this == obj);
}

bool Time::operator>(const Time& obj) const&
{
	if (this->hour > obj.hour)
		return true;
	else if (this->hour == obj.hour && this->minutes > obj.minutes)
		return true;
	else if (this->hour == obj.hour && this->minutes == obj.minutes && 
		this->seconds > obj.seconds)
		return true;
	else 
		return false;
}

bool Time::operator<(const Time& obj) const&
{
	return !(*this > obj) && *this != obj;
}

bool Time::operator>=(const Time& obj) const&
{
	return !(*this < obj);
}

bool Time::operator<=(const Time& obj) const&
{
	return !(*this > obj);
}

Time& Time::operator=(const Time& obj)
{
	strcpy_s(this->format, 4, obj.format);
	this->hour = obj.hour;
	this->minutes = obj.minutes;
	this->seconds = obj.seconds;
	return *this;
}

Time& Time::operator+=(int n)
{
	for (int i = 0; i < n; i++) {
		this->tickTime();
	}
	return *this;
}

Time& Time::operator-=(int n)
{
	for (int i = 0; i < n; i++) {
		this->tickBack();
	}
	return *this;
}

Time Time::operator+(int n)
{
	Time tmp = *this;
	for (int i = 0; i < n; i++) {
		tmp.tickTime();
	}
	return tmp;
}

Time Time::operator-(int n)
{
	Time tmp = *this;
	for (int i = 0; i < n; i++) {
		tmp.tickBack();
	}
	return tmp;
}

Time& Time::operator--()
{
	this->tickBack();
	return*this;
}

Time Time::operator--(int n)
{
	Time tmp = *this;
	this->tickBack();
	return tmp;
}

Time& Time::operator++()
{
	this->tickTime();
	return*this;
}

Time Time::operator++(int n)
{
	Time tmp = *this;
	this->tickTime();
	return tmp;
}

ostream& operator<<(ostream& os, const Time& t)
{
	os << t.hour/10 << t.hour % 10 << ":" << t.minutes / 10 << t.minutes % 10 << "\n";
	return os;
}

istream& operator>>(istream& is, Time& t)
{
	do {
		cout << "hh ";
		is >> t.hour;
		cout << "mm ";
		is >> t.minutes;
		cout << "ss ";
		is >> t.seconds;
		if (!t.valid()) cout << "Error\n";
	} while (!t.valid());
	return is;
}
