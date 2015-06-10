#ifndef POINT_H
#define POINT_H
#include<iostream>
using namespace std;

class point
{
public:
	int x, y;
};

class figure
{
public:
	int area();
	point A;
	point B;
	point C;
};

class line:public figure
{
public:
	line(int, int, int, int);
};

class rectangle:public figure
{
public: 
	rectangle(int, int, int, int);
	double area();
};

class triangle:public figure
{
public:
	triangle(int, int, int, int, int, int);
	double area();
};

class circle:public figure
{
public:
	circle(int, int, int, int);
	double area();
};
#endif  POINT_H
