#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
template <class T>
bool test(void(f)(T[], int))
{
	f(0, 0);
	int b[1] = { 12 };
	f(b, 1);
	time_t ltime;
	bool res = true;
	srand(time(&ltime));
	int len = (int)pow(2, rand() % 14 + rand() % 2 - 1)+1;
	int *a = new int[len];
	for (int i = 0; i < len; ++i)
	{
		a[i] = rand() % 12031;
	}
	f(a, len);
	for (int i = 0; i < len - 1; ++i)
	if (a[i]>a[i + 1])
		res=false;
	for (int i = 0; i < len; ++i)
	{
		a[i] = len - i;
	}
	f(a, len);
	for (int i = 0; i < len - 1; ++i)
	if (a[i]>a[i + 1])
		res=false;
	f(a, len);
	for (int i = 0; i < len - 1; ++i)
	if (a[i]>a[i + 1])
		res=false;
	int t = rand() % (len - 1);
	swap(a[t], a[t + 1]);
	f(a, len);
	for (int i = 0; i < len - 1; ++i)
	if (a[i]>a[i + 1])
		res=false;
	delete[]a;
	return res;
}
template <class T>
void merge(T *c, int inda, int indb, int lena, int lenb)
{
	T *a = new T[lena + lenb];
	int k = inda, n = indb;

	for (int i = 0; i < lena + lenb; ++i)
	{
		if (k - inda >= lena)
		{
			for (int j = n; j < indb + lenb; ++j)
				a[i++] = c[j];
			break;
		}
		else
		if (n - indb >= lenb)
		{
			for (int j = k; j < inda + lena; ++j)
				a[i++] = c[j];
			break;
		}
		if (c[k] < c[n])
		{
			a[i] = c[k++];
		}
		else
			a[i] = c[n++];
	}
	for (int i = inda; i < inda + lena + lenb; ++i)
	{
		c[i] = a[i - inda];

	}
	delete[] a;
}
template <class T>
void sort(T a[], int lena)
{
	int i = 1;
	while (i < lena)
	{
		int j = 0;
		while (j < lena)
		{
			int tail = i;
			if (j + i >= lena) break;
			if (j + i * 2>lena)
				tail = lena - j - i;
			merge(a, j, j + i, i, tail);
			j += i * 2;
		}
		i *= 2;
	}
}
int main()
{
	
		cout << test<int>(sort) << ' ';
	int i;
	cin >> i;
}