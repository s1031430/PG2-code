#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
#include"ATM.h"

using namespace std;

void select(int);
vector<member> account;
vector<item> product;
vector<website> webb;
void load()
{
	string id, password, name, mail, number, address;
	string phone;
	ifstream file("member.dat", ios::in | ios::binary);
	while (!file.eof())
	{
		file >> id >> password >> name >> number >> mail >> phone >> address;
		account.push_back(member(id, password, name, number, mail, phone, address));
	}
	string pname, buyer;
	int pID, price, quantity;
	ifstream file2("commodities.dat", ios::in | ios::binary);
	while (!file2.eof())
	{
		file2 >> pname >> price >> quantity;
		product.push_back(item(pname, price, quantity));
	}
	ifstream file3("commodities.dat", ios::in | ios::binary);
	while (!file3.eof())
	{
		file3 >> pID >> pname >> price >> quantity >> name >> buyer;
		webb.push_back(website(pID, pname, price, quantity, name, buyer));
	}
}

int main()
{
	load();
	int num;
	do
	{
		cout << "Please select the action you want to perform:" << endl;
		cout << "(1)Login" << endl;
		cout << "(2)Post auction items" << endl;
		cout << "(3)Visit website commodities(press 0 to exit)" << endl;
		cout << "(0)exit" << endl;
		cin >> num;
		select(num);
	} while (num == 1 || num == 2 || num == 3 || num == 0);
	system("pause");
	return 0;
}

void select(int num)
{
	ATM A;
	switch (num)
	{
	case 1:A.excute(); break;
	case 2:A.process(); break;
	case 3:A.print(); break;
	case 0:exit(0); break;
	}
}