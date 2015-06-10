#ifndef EXCEPTION
#define EXCEPTION

class NoTrouble         //(size:1~5)
{
public:
	NoTrouble(){}
	void determination(int);
};

class Trouble:public NoTrouble    //(size:0 or >5)
{
public:
	Trouble(){}
	void determination(int);
};

class BigTrouble :public Trouble     //(size is not a number)
{
public:
	void determination(int);
};

#endif