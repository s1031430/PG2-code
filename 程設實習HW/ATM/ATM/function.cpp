#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>
#include<string>
#include<iomanip>
#include"ATM.h"

using namespace std;

member::member(string a,string b,string c,string d,string e,string f,string g)
{
	id = a;
	password = b;
	name = c;
	number = d;
	mail = e;
	phone = f;
	address = g;
}

void ATM::excute()
{
	int number;
	cout << "Please select the action you want to perform" << endl;
	cout << "(1)Login" << endl;
	cout << "(2)Registered" << endl;
	cin >> number;
	if (number == 1)
		login();
	else if (number == 2)
		registered();
}

int member::buttom = 0;

void ATM::login()
{
	string ID;
	string PASS;
	cout << "Please input your ID: ";
	cin >> ID;
	for (int i = 0; i < mem.size();i++)
	if (ID == mem[i].id)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "Please input your password: ";
			cin >> PASS;
			if (PASS == mem[i].password)
			{
				cout << ID << "  ,Welcome to CSE auction system!" << endl;
				break;
			}
			else
			{
				cout << "Wrong password! Please enter again!" << endl;
				continue;
			}
		}
		cout << "Password is entered incorrectly three times\n" << "Good-Bye\n";
	}
	else
	{
		cout << "ID does not exist!!!\n" << "you need to register first!\n";
	}
	member::buttom = 1;
}

void ATM::registered()
{
	string ID,PASS,NAME,NUM,MAIL,PHONE,ADDRESS;
	ofstream file;
	file.open("member.dat", ios::out | ios::binary);
	cout << "Please input an ID you want: ";
	cin >> ID;
	for (int i = 0; i < mem.size();i++)
	if (ID == mem[i].id)
	{
		cout << "' " << ID << " ' has been used!";
		return registered();
	}
	cout << "Please input a password you want: ";
	cin >> PASS;
	cout << "Please input the name: ";
	cin >> NAME;
	cout << "Please input ID numbers: ";
	cin >> NUM;
	while (checkID(NUM) == false)
	{
		cout << "You enter the wrong ID! Please input again!" << endl;
		cout << "Please input ID numbers: ";
		cin >> NUM;
	}
	cout << "Please input E-mail: ";
	cin >> MAIL;
	cout << "Please input phone: ";
	cin >> PHONE;
	while (PHONE.size() != 10)
	{
		cout << "You enter the wrong phone! Please input again!" << endl;
		cout << "Please input phone: ";
		cin >> PHONE;
	}
	cout << "Please input address(country): ";
	cin >> ADDRESS;
	file << ID << setw(15) << PASS << setw(15) << NAME << setw(15) << NUM << setw(15) << MAIL << setw(15) << PHONE << setw(15) << ADDRESS;
	mem.push_back(member(ID, PASS, NAME, NUM, MAIL, PHONE, ADDRESS));
	cout << NAME << ",Welcome to join CSE auction system!" << endl;
	member::buttom = 1;
}

bool ATM::checkID(string ID)
{
	int head = ID[0];
	if (ID.size() != 10)
		return false;
	if (head >= 65 && head <= 90) //  A~Z ASCII範圍
	{
		if (head == 73) head = head - 39;  // I
		else if (head == 79) head = head - 44; // O
		else if (head == 87) head = head - 55; //W
		else if (head == 90) head = head - 57; //Z
		else if (head >= 65 && head <= 72) head = head - 55; //A~H
		else if (head >= 74 && head <= 78) head = head - 56; //J~N
		else if (head >= 80 && head <= 86) head = head - 57; //P~V
		else  head = head - 58; //X~Y
	}
	/* 個位數*9 + 十位數 */
	int sum = head % 10;
	head = head / 10;
	sum = sum * 9 + head;
	/* 將數字字元轉成數字 */
	int num[10];
	for (int i = 1; ID[i] != '\0'; i++)
		num[i] = ID[i] - '0';
	/* 運算第二碼~第九碼 */
	for (int j = 8; j >= 1; j--)
		sum = sum + (num[9 - j] * j);
	sum = sum % 10;
	if ((num[9] == 0 && sum == 0) || ((10 - sum) == num[9]))
		return true;
	else
		return false;
}

item::item(string b, int c, int d)
{
	pname = b;
	price = c;
	quantity = d;
}

website::website(int a, string b, int c, int d, string e, string f)
{
	pID = a;
	pname = b;
	price = c;
	quantity = d;
	name = e;
	buyer = f;
}

void ATM::process()
{
	int num;
	member num1;
	if (member::buttom == 1)
		post();
	else if (member::buttom == 0)
	{
		cout << "Please select the action you want to perform" << endl;
		cout << "(1)Login" << endl;
		cout << "(2)Registered" << endl;
		cin >> num;
		if (num == 1)
			login();
		else if (num == 2)
			registered();
		post();
	}
}

void ATM::post()
{
	string PNAME;
	int PRICE, QUANTITY;
	ofstream file;
	file.open("commodities.dat", ios::out | ios::binary);
	cout << "Please input the product name you want to sell: ";
	cin >> PNAME;
	cout << "Please input the price of product: ";
	cin >> PRICE;
	cout << "Please input the quantity of the product: ";
	cin >> QUANTITY;
	file << PNAME << setw(10) << PRICE << setw(5) << QUANTITY;
	it.push_back(item(PNAME, PRICE, QUANTITY));
}

void ATM::print()
{
	cout << "ProductID" << setw(20) << "ProductName" << setw(10) << "Price" << setw(10) << "Quantity" << setw(10) << "Seller" << setw(10) << "Buyer" << endl;
	for (int i = 1; i <= web.size();i++)
		cout << setw(5) << web[i].pID << setw(25) << web[i].pname << setw(10) << web[i].price << setw(10) << web[i].quantity << setw(10) << web[i].name << setw(10) << web[i].buyer << endl;
	sale();
}

void ATM::sale()
{
	int PID, QUANTITY;
	cout << "Please choose the productID you want to buy: ";
	cin >> PID;
	if (PID == 0)
		exit(0);
	if (web[PID-1].quantity == 0)
	{
		cout << "Product has been sold!!!" << endl;
	}
	else
	{
		cout << "Successful purchase!!!" << endl;
		web[PID-1].quantity--;
		web[PID-1].buyer = web[PID-1].name;
	}
}