#include<iostream>
#include<string>
#include"Date.h"

using namespace std;

const int Date::days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 3, 30, 31, 30, 31 };

Date::Date(int m, int d, int y)
{
	setDate(m, d, y);
}

void Date::setDate(int a,int b,int c)
{
	month = (a >= 1 && a <= 12) ? a : 1;
	year = (c >= 1900 && c <= 2100) ? c : 1900;
	if (month == 2 && leapyear(year))
		day = (b >= 1 && b <= 29) ? b : 1;
	else
		day = (b >= 1 && b <= days[month]) ? b : 1;
}

Date& Date::operator++()
{
	helpIncrement();
	return *this;
}

Date Date::operator++(int)
{
	Date x= *this;
	helpIncrement();

	return x;
}

Date& Date::operator+=(int add)
{
	for (int i = 0; i < add; i++)
		helpIncrement();
		return *this;
}

bool Date::leapyear(int test)
{
	if (test % 400 == 0 || (test % 100 != 0 && test % 4 == 0))
		return true;
	else
		return false;
}

bool Date::endofMonth(int my_day) 
{
	if (month == 2 && leapyear(year))
		return my_day == 29;
	else
		return my_day == days[month];
}

void Date::helpIncrement()
{
	if (!endofMonth(day))
	{
		day++;
	}
	else
	if (month < 12)
	{
		month++;
		day = 1;
	}
	else
	{
		year++;
		month = 1;
		day = 1;
	}
}

ostream &operator<<(ostream &output, const Date &d)
{
	string name[13] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	output << name[d.month] << ' ' << d.day << ", " << d.year;
	return output;
}