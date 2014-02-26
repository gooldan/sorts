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

	srand(time(&ltime));
	int len = (int)pow(2, rand() % 14 + 3); //+ rand() % 2 - 2;
	int *a = new int[len];
	for (int i = 0; i < len; ++i)
	{
		a[i] = rand() % 12031;
	}
	f(a, len);
	for (int i = 0; i < len - 1; ++i)
	if (a[i]>a[i + 1])
		return false;
	for (int i = 0; i < len; ++i)
	{
		a[i] = len - i;
	}
	f(a, len);
	for (int i = 0; i < len - 1; ++i)
	if (a[i]>a[i + 1])
		return false;
	f(a, len);
	for (int i = 0; i < len - 1; ++i)
	if (a[i]>a[i + 1])
		return false;
	int t = rand() % (len - 1);
	swap(a[t], a[t + 1]);
	f(a, len);
	for (int i = 0; i < len - 1; ++i)
	if (a[i]>a[i + 1])
		return false;
	delete[]a;
	return true;
}
void countingSort(int a[], int len,int m)
{
	int *bas = new int[m + 1];
	for (int i = 0; i < m+1; ++i)
		bas[i] = 0;
	for (int i = 0; i < len; ++i)
		bas[a[i]]++;
	int j = 0;
	for (int i = 0; i < m+1;++i)
	if (bas[i] != 0)
	{
		a[j++] = i;
		bas[i--]--;
	}
	delete[]bas;
		
}
int main()
{
	int a[14] = { 12, 6, 27, 2, 5, 29, 11, 14, 7, 8, 16, 13, 28, 17 };
	countingSort(a, 14, 29);
	int i;
	for (int i = 0; i < 14; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << test<int>(countingSort())
	cin >> i;
}