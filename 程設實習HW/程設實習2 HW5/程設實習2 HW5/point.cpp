#include<iostream>
#include<cmath>
#include"point.h"

using namespace std;

int figure::area()
{
	return 0;
}

line::line(int a, int b, int c, int d)
{
	A.x = a;
	A.y = b;
	B.x = c;
	B.y = d;
}

rectangle::rectangle(int a, int b, int c, int d)
{
	A.x = a;
	A.y = b;
	B.x = c;
	B.y = d;
}

double rectangle::area()
{
	return abs((B.x - A.x)*(B.y - A.y));
}

triangle::triangle(int a, int b, int c, int d, int e, int f)
{
	A.x = a;
	A.y = b;
	B.x = c;
	B.y = d;
	C.x = e;
	C.y = f;
}

double triangle::area()
{
	double l1, l2, l3;
	double s;
	l1 = sqrt((B.x - A.x)*(B.x - A.x) + (B.y - A.y)*(B.y - A.y));
	l2 = sqrt(((B.x - C.x)*(B.x - C.x)) + ((C.y -B.y)*(C.y - B.y)));
	l3 = sqrt(((C.x - A.x)*(C.x - A.x)) + ((C.y - A.y)*(C.y - A.y)));
	s = (l1 + l2 + l3) / 2;
	return sqrt(s*(s - l1)*(s - l2)*(s - l3));
}

circle::circle(int a, int b, int c, int d)
{
	A.x = a;
	A.y = b;
	B.x = c;
	B.y = d;
}

double circle::area()
{
	double l1;
	l1 = sqrt((B.x -A.x)*(B.x - A.x) + (B.y - A.y)*(B.y - A.y));
	return l1*l1*3.1415926;
}