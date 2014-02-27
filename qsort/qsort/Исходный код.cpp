#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
template <class T>
bool test(void(f)(T[], int,int))
{
	f(0, 0,0);
	int b[1] = { 12 };
	f(b, 0,0);
	time_t ltime;

	srand(time(&ltime));
	int len = (int)pow(2, rand() % 14 + 3); //+ rand() % 2 - 2;
	int *a = new int[len];
	for (int i = 0; i < len; ++i)
	{
		a[i] = rand() % 12031;
	}
	f(a, 0,len-1);
	for (int i = 0; i < len - 1; ++i)
	if (a[i]>a[i + 1])
		return false;
	for (int i = 0; i < len; ++i)
	{
		a[i] = len - i;
	}
	f(a, 0, len - 1);
	for (int i = 0; i < len - 1; ++i)
	if (a[i]>a[i + 1])
		return false;
	f(a, 0, len - 1);
	for (int i = 0; i < len - 1; ++i)
	if (a[i]>a[i + 1])
		return false;
	int t = rand() % (len - 1);
	swap(a[t], a[t + 1]);
	f(a, 0, len - 1);
	for (int i = 0; i < len - 1; ++i)
	if (a[i]>a[i + 1])
		return false;
	delete[]a;
	return true;
}
template <class T>
void qsort(T a[], int l, int r)
{
	if (l == r) return;
	T x = a[rand() % (r - l + 1) + l];
	int i = l;
	int j = r;
	while (i <= j)
	{
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (i < r)
		qsort(a, i, r);
	if (l < j)
		qsort(a, l, j);
}
int main()
{
	cout << test<int>(qsort);
	int i;
	cin >> i;
}
