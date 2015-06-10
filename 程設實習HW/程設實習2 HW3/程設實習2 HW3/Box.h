#ifndef _1031434_Box_h
#define _1031434_Box_h

class Box{
public:
	Box(double = 1.0, double = 1.0, double = 1.0);
	double volume();
	int compare(Box&);
	double getlength();
	double getwidth();
	double gethight();
private:
	double length;
	double width;
	double hight;
};
#endif