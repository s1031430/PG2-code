#include<iostream>
#include"exception.h"
using namespace std;

int main()
{
	NoTrouble n1;
	int size = -1;
	cout << "Please input a size of array:\n";
	cin >> size;
	n1.determination(size);
	system("pause");
	return 0;
}