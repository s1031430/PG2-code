#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
#include"s1031430_Enigma.h"
#include"s1031430_Enigma_base.h"

using namespace std;

void Enigma_Files::Read_file(string f)
{
	ifstream file;
	file.open(f, ios::in);
	getline(file, data);
	file.close();
}

void Enigma_Files::Write_file(string f)
{
	ofstream file;
	file.open(f, ios::out);
	file.close();
}

void Enigma_Files::Push(char const &c)
{
	data = data + c;
}

char const &Enigma_Files::operator[](size_t const& i) 
{
	return data[i];
}

string Enigma_Files::Data()
{
	return data;
}

size_t Enigma_Files::Length()
{
	return data.length();
}

Enigma_Component::Enigma_Component(){}

char Enigma_Component::Input_signal(char c)
{
	return this->Encoding(c);
}

void Enigma_Component::Link(Enigma_Component & n)
{
	link_next = &n;
	n.link_previous = this;
}

void Enigma_Component::Read_table(string f)
{
	ifstream file;
	file.open(f, ios::in);
}

Plugboard::Plugboard(string a)
{
	ifstream file;
	file.open(a, ios::in);
	file >> data;
	file.close();

	start = 65;
}

size_t Plugboard::Encoding(size_t i)
{
	if (a == true)
	{
		link_next->Spin();
		a = false;
		char code = data.at(i - 65);
		return link_next->Encoding(code);
	}
	else
	{
		a = true;
		char code = i + this->start - link_next->start;
		if (code > 90)
		{
			code -= 26;
		}
		if (code < 65)
		{
			code += 26;
		}
		char ch = data.find(code) + 65;
		return ch;
	}
}

int Wheel::buttom = 0;

Wheel::Wheel(string a,char c,char d)
{
	ifstream file;
	file.open(a, ios::in);
	file>>data;
	file.close();
	start = c;
	arrow = d;
}

void Wheel::Spin()
{	
	start++;
	if (start > 90)
	{
		start -= 26;
	}
	if (buttom == 1)
	{	
		link_next->Spin();
		buttom = 0;
	}
	if (start == arrow)
	{
		link_next->Spin();
	}
}

size_t Wheel::Encoding(size_t i)
{
	if (a == true)
	{
		a = false;
		char code = i + this->start - link_previous->start;
		if (code > 90)
		{
			code -= 26;
		}
		if (code < 65)
		{
			code += 26;
		}
		char ch = data.at(code - 65);
		return link_next->Encoding(ch);
	}
	else
	{
		a = true;
		char code = i + this->start - link_next->start;
		if (code > 90)
		{
			code -= 26;
		}
		if (code < 65)
		{
			code += 26;
		}
		char ch = data.find(code) + 65;
		return link_previous->Encoding(ch);
	}
}

Special_Wheel::Special_Wheel(string a,char c,char d)
{
	ifstream file;
	file.open(a, ios::in);
	file>>data;
	file.close();
	start = c;
	arrow = d;
	
}

void Special_Wheel::Spin()
{
	start++;
	if (start > 90)
	{
		start -= 26;
	}
	if (start == arrow)
	{
		link_next->Spin();
	}
	if (start == 69)
	{	
		buttom = 1;
	}
}

size_t Special_Wheel::Encoding(size_t i)
{
	if (a == true)
	{
		a = false;
		char code = i + this->start - link_previous->start;
		if (code > 90)
		{
			code -= 26;
		}
		if (code < 65)
		{
			code += 26;
		}
		char ch = data.at(code - 65);
		return link_next->Encoding(ch);
	}
	else
	{
		a = true;
		char code = i + this->start - link_next->start;
		if (code > 90)
		{
			code -= 26;
		}
		if (code < 65)
		{
			code += 26;
		}
		char ch = data.find(code) + 65;
		return link_previous->Encoding(ch);
	}
}

Reflector::Reflector(string a)
{
	ifstream file;
	file.open(a, ios::in);
	file>>data;
	file.close();
	start = 65;
}

size_t Reflector::Encoding(size_t i)
{	
	char code = i + this->start - link_previous->start;
	if (code > 90)
	{
		code -= 26;
	}
	if (code < 65)
	{
		code += 26;
	}
	char ch = data.at(code - 65);
	return link_previous->Encoding(ch);
}