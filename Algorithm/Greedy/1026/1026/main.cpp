#include <iostream>
#include <algorithm>
using namespace std;

const int maxSize = 50 + 5;
int arrA[maxSize];
int arrB[maxSize]; // value, index

bool compare(int a, int b)
{
	return a > b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arrA[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> arrB[i];
	}

	sort(arrA, arrA + n, compare);
	sort(arrB, arrB + n);

	int result = 0;

	for (int i = 0; i < n; i++)
	{
		result += arrA[i] * arrB[i];
	}

	cout << result;
	return 0;
}