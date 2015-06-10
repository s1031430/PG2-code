#include<iostream>
#include<cstdlib>
#include"exception.h"

using namespace std;

void NoTrouble::determination(int size)
{
		try
		{
			if (size <= 5 && size >= 1)
			{
				cout << "Trouble object caught : There's no problem\n";
			}
		}
		catch (int size)
		{
			cout << "Trouble object caught\n";
		}
}

void Trouble::determination(int size)
{
		try
		{
			if (size == 0 || size > 5)
			{
				cout << "Trouble object caught : There's a problem\n";
			}
		}
		catch (int size)
		{
			cout << "Trouble object caught\n";
		}
}

void BigTrouble::determination(int size)
{
	try
	{
		if (size < 0)
		{
			cout << "Trouble object caught : There's a big problem\n";
		}
	}
	catch (int size)
	{
		cout << "Trouble object caught\n";
	}
}