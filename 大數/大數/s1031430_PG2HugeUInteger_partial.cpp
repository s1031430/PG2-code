#include "s1031430_PG2Vector.h"
#include "s1031430_PG2HugeUInteger.h" // include definition of class HugeInteger 
#include<cstdlib>
#include<ctime>
#include<iostream>
// default constructor (all digi = 0)
HugeUInteger::HugeUInteger(size_t size)
: integer()
{
	integer.resize(size);
	for (unsigned int i = 0; i < size; i++)
		integer[i] = 0;
}

// copy constructor
HugeUInteger::HugeUInteger(HugeUInteger &integerToCopy)
: integer(integerToCopy.integer)
{
	
}

HugeUInteger::~HugeUInteger()
{
	
}

// randomly generate an integer
HugeUInteger HugeUInteger::random(size_t size)
{
	HugeUInteger Ans(size);

	Ans.integer[size - 1] = 1 + rand() % 9;
	for (unsigned int i = 0; i < size; i++)
		Ans.integer[i] = rand() % 10;
	
	return Ans;
}

// zero this number (size = 1)  
HugeUInteger HugeUInteger::zero()
{
	HugeUInteger Ans(1);
	Ans.integer[0] = 0;

	return Ans;
}

HugeUInteger HugeUInteger::operator=(const HugeUInteger &right)
{
	for (int i = 0; i < right.integer.size(); i++)
	{
		this->integer[i] = right.integer[i];
	}
	return *this;
}

bool HugeUInteger::operator==(const HugeUInteger &right)
{
	for (int i = 0; i < right.integer.size(); i++)
	{
		if (integer[i] != right.integer[i])
			return false;
	}
	return true;
}

bool HugeUInteger::operator!=(const HugeUInteger &right)
{
	for (int i = 0; i < right.integer.size(); i++)
	{
		if (integer[i] == right.integer[i])
			return false;
	}
	return true;
}

bool HugeUInteger::operator<(const HugeUInteger &right)
{
	
	for (int i = right.integer.size() - 1; i >= 0; i--)
	{
		if (right.integer[i] < integer[i])
			return false;
	}
	return true;
}

bool HugeUInteger::operator>(const HugeUInteger &right)
{

	for (int i = this->integer.size() - 1; i >= 0; i--)
	{
		if (integer[i] < right.integer[i])
			return false;
	}
	return true;
}

HugeUInteger HugeUInteger::operator+(const HugeUInteger &right)
{
	HugeUInteger x;
	int carry = 0;
	int step;
	x.integer[0] = integer[0] + right.integer[0];
	if (x.integer[0] >= 10)
	{
		step = 1;
		x.integer[1] = x.integer[0] % 10;
		x.integer[0] = 1;
	}
	else
		step = 0;
	for (int i = 1; i < digit; i++)
	{
		x.integer[i + step] = integer[i + step] + right.integer[i + step];
		if (x.integer[i + step] >= 10)
		{

			carry = x.integer[i + step] / 10;
			x.integer[i + step] %= 10;
			x.integer[i + step - 1]++;
		}
	}
	if (carry)
		x.digit++;
	return x;
}

HugeUInteger HugeUInteger::operator-(const HugeUInteger &right)
{
	HugeUInteger x;
	int borrow = 0;
	for (int i = 0; i < digit; i++)
	{
		x.integer[i] = integer[i] - right.integer[i];
		if (x.integer[i] < 0 && i != 0)
		{
			borrow = 1;
			x.integer[i - 1] --;
			x.integer[i] += 10;
		}
		else
		{
			borrow = 0;
		}
	}
	return x;
}

HugeUInteger HugeUInteger::operator*(const HugeUInteger &right)
{
	HugeUInteger x;
	int carry = 0;
	for (int i = 0; i < digit; i++)
	{
		for (int j = 0, k = i; j < right.digit; j++, k++)
		{
			x.integer[k] += integer[j] * right.integer[i];
		}
		for (i = 0; i < x.digit; i++)
		{
			if (x.integer[i] >= 10)
			{
				carry = x.integer[i] / 10;
				x.integer[i] %= 10;
				x.integer[i + 1] += carry;
			}
		}
	}
	if (!x.integer[x.digit - 1])
		x.digit--;

	return x;
}

HugeUInteger HugeUInteger::operator/(const HugeUInteger &right)
{
	HugeUInteger x;
	HugeUInteger copy = *this;
	if (digit < right.digit)
	{
		x.integer[0] = 0;
		return x;
	}
	else
		x.digit = digit - right.digit + 1;
	int index;
	for (int i = 1;; i++)
	{
		copy = copy - right;
		if (copy<right)
		{
			index = i;
			break;
		}
	}
	int timer = 0;
	for (int i = 0; i < x.digit; i++)
	{
		timer++;
		x.integer[i] = i % 10;
		i /= 10;
	}

	x.digit = timer;

	return x;
}

HugeUInteger HugeUInteger::operator%(const HugeUInteger &right)
{
	HugeUInteger x;
	HugeUInteger copy = *this;
	if (digit < right.digit)
	{
		x.integer[0] = 0;
		return x;
	}
	else
		x.digit = digit - right.digit + 1;
	int index;
	for (int i = 1;; i++)
	{
		copy = copy - right;
		if (copy<right)
		{
			index = i;
			break;
		}
	}
	return copy;
}

ostream &operator<<(ostream &output, const HugeUInteger &in)
{
	unsigned int size = in.integer.size();
	if (size == 0)
	{
		output << 0;
		return output;
	}
		
	else //if(!sign) cout << "-";
	for (int i = size - 1; i >= 0; i--)
		output << in.integer[i]; // << " ";

	return output; // enables cout << x << y;
}