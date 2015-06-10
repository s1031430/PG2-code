#include"Box.h"
#include"List.h"
#include<cstdlib>

Box::Box(double x, double y, double z){
	length = x;
	width = y;
	hight = z;
}

double Box::volume(){
	return length*width*hight;
}

int Box::compare(Box &becmp){
	return this->volume() > becmp.volume() ? 1 : -1;
}

double Box::gethight(){
	return hight;
}

double Box::getlength(){
	return length;
}

double Box::getwidth(){
	return width;
}

Package::Package(Box *pNewBox){
	pBox = pNewBox;
	pNext = NULL;
}

Box* Package::getBox()const{
	return pBox;
}

Package* Package::getNext()const{
	return pNext;
}

void Package::setNext(Package* Next){
	Next = Next->pNext;
}


Truckload::Truckload(Box* pBox, int count){
	if (!count){
		head = NULL;
		now = NULL;
		tail = NULL;
		count = 1;
	}
	else
	for (int i = 1; i < count; i++)
		addBox(pBox);
}

Box* Truckload::getFirstBox(){
	return head->getBox();
}

Box* Truckload::getNextBox(){
	if (now->getNext() != NULL){
		now = now->getNext();
		return now->getBox();
	}
	else
		return NULL;
}

void Truckload::addBox(Box* pBox){
	if (head == NULL){
		head = new Package(pBox);
		now = head;
		tail = head;
	}
	else
	{
		Package *pPoint;
		pPoint = new Package(pBox);
		now = head;
		if (now->Package::getNext() != 0){
			now->setNext(pPoint);
			now = now->getNext();
		}
		now = pPoint;
		tail = now;
	}
}