#ifndef ENIGMA_H
#define ENIGMA_H
#include<iostream>
#include "s1031430_Enigma_Base.h"

#include<string>
using namespace std;

class Plugboard : public Enigma_Component
{
public:
	Plugboard(string);
	size_t Encoding(size_t i);
};

//a derived class for the ordinary wheel (Rotor I and III)
class Wheel : public Enigma_Component
{
public:
	Wheel(){}
	Wheel(string,char,char);
	void Spin();
	size_t Encoding(size_t i);
	static int buttom;
};

//a derived class for the special version of wheel (Rotor II)
class Special_Wheel : public Wheel
{
public:
	Special_Wheel(string,char,char);
	void Spin();
	size_t Encoding(size_t i);
};

//a derived class for reflector
class Reflector : public Enigma_Component
{
public:
	Reflector(string);
	size_t Encoding(size_t i);
};
#endif