#ifndef List_h
#define List_h

#include"Box.h"

class Package
{
public:
	Package(Box*);
	Box *getBox()const;
	Package *getNext()const;
	void setNext(Package*);
private:
	Box *pBox;
	Package *pNext;
};

class Truckload
{
public:
	Truckload(Box* = 0, int = 1);
	Box *getFirstBox();
	Box *getNextBox();
	void addBox(Box*);
private:
	Package *head;
	Package *now;
	Package *tail;

};
#endif