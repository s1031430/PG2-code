#ifndef Enigma_base_H
#define Enigma_base_H

#include<string>
using namespace std;

class Plugboard;
class Wheel;
class Special_Wheel;
class Reflector;


class Enigma_Files
{
public:
	void Read_file(std::string file); //< Read from a file
	void Write_file(std::string file); //< Write the string into a file

	void Push(char const& c); //< push a character on the tail(end) of string
	char const& operator [] (size_t const& i); //< get specific character

	std::string Data(); //< get data
	size_t Length(); //< get length of data

protected:
	std::string data;
};

class Enigma_Component
{
public:
	Enigma_Component();

	//Input a character and return a encoded one (use this function to invoke "Encoding" function)
	char Input_signal(char c);

	//[optional] This function is optional for Linked List
	void Link(Enigma_Component & n);

	friend class Plugboard;
	friend class Wheel;
	friend class Special_Wheel;
	friend class Reflector;

protected:
	//[optional] This two pointer is optional for Linked List
	Enigma_Component* link_next;
	Enigma_Component* link_previous;

	//A function of encode messenge (It should be overrided by derived classes)
	virtual size_t Encoding(size_t i) = 0;

	//Read a mapping table from file to setup current component (It should be overrided by derived classes)
	void Read_table(std::string f);

	//Spin current component (It should be overrided by derived classes)
	virtual void Spin() {}
	string data;
	char start;
	char arrow;

	bool a = true;   
};
#endif