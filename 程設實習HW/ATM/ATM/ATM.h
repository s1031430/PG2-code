#ifndef ATM_H
#define ATM_H

#include<string>
#include<vector>
#include<iostream>

using namespace std;

class member
{
public:
	member(){}
	//member(const member&); -> copy constructor
	member(string, string, string, string, string, string, string);
	static int buttom;
	string phone;
	string id, password, name, number, mail, address;
};

class item:public member
{
public:
	item(){}
	item(string, int, int);
	string pname; 
	int price, quantity;
};

class website:public item
{
public:
	website(){}
	website(int, string, int, int, string, string);
	int pID;
	string buyer = "null";
};

class ATM
{
public:
	void excute();
	void login();
	void registered();
	bool checkID(string);
	void post();
	void process();
	void sale();
	void print();
private:
	vector<member> mem;
	vector<item> it;
	vector<website> web;
};
#endif