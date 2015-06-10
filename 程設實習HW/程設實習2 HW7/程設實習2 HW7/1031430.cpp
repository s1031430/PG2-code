#include<iostream>
#include<cstdlib>

using namespace std;

template<class T>
T max(T arr[], int size)
{
	T max = arr[0]; 
	for (int i = 0; i < 10; i++)
	{
		if (arr[i]>max)
			max = arr[i];
	}
	return max;
}

int main()
{
	int grade[10] = { 78, 44, 89, 55, 45, 75, 94, 74, 83, 65 };
	float height[10] = { 178.3, 164.6, 189.4, 155.8, 158.3, 175.0, 169.6, 174.2, 183.1, 165.9 };
	cout << "The best score is " << max(grade,10) << endl;
	cout << "The maximum height is " << max(height,10) << endl;
	system("pause");
	return 0;
}
