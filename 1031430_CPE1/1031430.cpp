#include<iostream>
#include<cmath>

using namespace std;
int main()
{
	int a,b[10],c=0,d,e=0;    //a為排數，b為存入每排有幾個的陣列，c為所有磚塊的總和，d為平均數，e為計數器(紀錄移動幾次) 
	cout<<"";
	cin>>a;
	for(int i=0;i<a;i++)
	{
	cout<<"";
	cin>>b[i];
	c=c+b[i];
	}
	d=c/a;
	for(int i=0;i<a;i++)
	{
		e=e+abs(d-b[i]);
	}
	cout<<"The minimum moves is "<<e/2;
	cout<<endl;
	system("pause");
	return 0;
}
