#include<iostream>
#include<string>
#include"Vessel.h"

using namespace std;

Can::Can(int a, int b, string c)
{
	diameter = a;
	height = b;
	name = c;
}

double Can::volume()
{
	return (diameter/2)*(diameter/2)*pi*height;
}

string Can::getname()
{
	return name;
}

double Can::pi = 3.14159265;

Box::Box(){}

Box::Box(int a, int b, int c, string d)
{
	length = a;
	breadth = b;
	height = c;
	name = d;
}

double Box::volume()
{
	return length*breadth*height;
}

string Box::getname()
{
	return name;
}

Carton::Carton(int a, int b, int c, string d)
{
	length = a;
	breadth = b;
	height = c;
	name = d;
}

double Carton::volume()
{
	return (length - 0.5)*(breadth - 0.5)*(height - 0.5);
}

string Carton::getname()
{
	return name;
}

ToughPack::ToughPack(int a, int b, int c, string d)
{
	length = a;
	breadth = b;
	height = c;
	name = d;
}

double ToughPack::volume()
{
	return  0.85*length*breadth*height;
}

string ToughPack::getname()
{
	return name;
}