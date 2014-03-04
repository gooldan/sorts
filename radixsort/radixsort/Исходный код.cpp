#include <iostream>
#include <cstdlib>

using namespace std;
void RadixSort(int a[], int len)
{
	int **bas= new int*[10];
	for (int i = 0; i < 10; ++i)
		bas[i] = new int[len];
	bool working = true;
	int *ind=new int [10];
	
	bool stillw = true;
	int lev = 0;
	while (working)
	{
		for (int i = 0; i < 10; ++i)
		{
			ind[i] = 0;
		}
		stillw = true;
		for (int i = 0; i < len; ++i)
		{
			int ln = 0;
			int t = a[i];
			for (int j = 0; j < lev; ++j)
				a[i] /= 10;
			ln = a[i] % 10;
			if (stillw && ln == 0) working = false;
			else
			{
				stillw = false;
				working = true;
			}
			a[i] = t;
		}
		if (!working) break;
		for (int i = 0; i < len; ++i)
		{
			int ln = 0;
			int t = a[i];
			for (int j = 0; j < lev; ++j)
				t /= 10;
			ln = t % 10;
			bas[ln][ind[ln]] = a[i];
			ind[ln]++;
		}
		int k = 0;
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < ind[i]; ++j)
			{
				a[k] = bas[i][j];
				bas[i][j] = 0;
				k++;
			}
		}
		lev++;
	}
	for (int k = 0; k < 10; k++)
		delete[] bas[k];
	delete[] bas;
	delete[] ind;
	
}
int main()
{
	int a[14] = { 12, 6, 27, 2, 5, 222, 311, 14, 127, 8, 16263, 13, 28, 0 };//
	RadixSort(a, 14);
	int i;
	for (int i = 0; i < 14; ++i)
	{
		cout << a[i] << ' ';
	}
	cin >> i;
}