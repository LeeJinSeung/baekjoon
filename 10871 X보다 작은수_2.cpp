#include<iostream>
using namespace std;

int main()
{

	int n, x;
	cin >> n >> x;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int t = 0; t <n; t++)
	{
		if (a[t]<x)
		{
			cout << a[t] << " ";
		}
	}
	delete[] a;

	system("pause >> null");
	return 0;
}