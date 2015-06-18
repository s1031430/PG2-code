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
			else
			{
				throw size;
			}
				
		}
		catch (int num)
		{
			Trouble T1;
			T1.determination(num);
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
			else
				throw size;
		}
		catch (int num)
		{
			BigTrouble B1;
			B1.determination(num);
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
		else
			throw "Over Loading";
	}
	catch (const char *c)
	{
		cout << "Trouble object caught\n";
	}
}