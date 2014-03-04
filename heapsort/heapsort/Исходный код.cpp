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
	int len = (int)pow(2, rand() % 14 + 3); //+ rand() % 2 - 2;
	int *a = new int[len];
	for (int i = 0; i < len; ++i)
	{
		a[i] = rand() % 12031;
	}
	f(a, len);
	for (int i = 0; i < len - 1; ++i)
	if (a[i]>a[i + 1])
		res= false;
	for (int i = 0; i < len; ++i)
	{
		a[i] = len - i;
	}
	f(a, len);
	for (int i = 0; i < len - 1; ++i)
	if (a[i]>a[i + 1])
		res= false;
	f(a, len);
	for (int i = 0; i < len - 1; ++i)
	if (a[i]>a[i + 1])
		res= false;
	int t =rand() % (len - 1);
	swap(a[t], a[t + 1]);
	f(a, len);
	for (int i = 0; i < len - 1; ++i)
	if (a[i]>a[i + 1])
		res= false;
	delete[]a;
	return res;
}
template <class T>
void sinking(T a[], int ind, int len)
{
	int worse = 0;
	if (2 * ind + 2 >= len)
	if (2 * ind + 1 >= len)
		return;
	else
		worse = 2 * ind + 1;
	else
		worse = a[2 * ind + 1] < a[2 * ind + 2] ? 2 * ind + 2 : 2 * ind + 1;
	if (a[ind] < a[worse])
	{
		swap(a[ind], a[worse]);
		sinking(a, worse, len);
	}
}
template <class T>
void HeapSort(T a[], int len)
{
	for (int i = len / 2 - 1; i >= 0; --i)
		sinking(a, i, len);
	int i = 0;
	while (i < len)
	{
		swap(a[0], a[len - i - 1]);
		sinking(a, 0, len - i - 1);
		i++;
	}

}
int main()
{

	int i;

	cout << test<int>(HeapSort);

	cin >> i;
}