#ifndef VESSEL_H
#define VESSEL_H

#include<iostream>
#include<string>

using namespace std;

class Vessel
{
public:
	virtual double volume() = 0;
	virtual string getname() =0;
	string name;
};

class Can :public Vessel
{
public:
	Can(int, int, string);
	double volume();
	string getname();
	double diameter;
	double height;
	string name;
	static double pi;
};

class Box :public Vessel
{
public:
	Box(int, int, int, string);
	double volume();
	Box();
	string getname();
	double length;
	double breadth;
	double height;
	string name;
};

class Carton :public Box
{
public:
	Carton(int, int, int, string);
	double volume();
	string getname();
};

class ToughPack :public Box
{
public:
	ToughPack(int, int, int, string);
	double volume();
	string getname();
};

#endif