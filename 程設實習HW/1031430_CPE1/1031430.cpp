#include<iostream>
#include<cmath>

using namespace std;
int main()
{
	int a,b[10],c=0,d,e=0;    //a���ƼơAb���s�J�C�Ʀ��X�Ӫ��}�C�Ac���Ҧ��j�����`�M�Ad�������ơAe���p�ƾ�(�������ʴX��) 
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
