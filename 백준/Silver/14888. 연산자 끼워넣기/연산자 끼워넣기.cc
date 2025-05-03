#include <iostream>
#include <algorithm>
using namespace std;

const int maxSize = 11 + 5;
int arr[maxSize];

int currentHaveCount[4 + 5];

int maxResult = -1000000005;
int minResult = 1000000005;

void add(int value, int index, int length);
void subtract(int value, int index, int length);
void multiply(int value, int index, int length);
void divide(int value, int index, int length);

void dfs(int value, int index, int length)
{
	if (index == length) return;

	if (index == length - 1) // 마지막 연산까지 끝난 경우
	{
		maxResult = max(maxResult, value);
		minResult = min(minResult, value);
	}

	add(value, index, length);
	subtract(value, index, length);
	multiply(value, index, length);
	divide(value, index, length);
}

void add(int value, int index, int length)
{
	if (currentHaveCount[0] == 0) return;

	currentHaveCount[0]--;
	value = value + arr[++index];

	dfs(value, index, length);
	currentHaveCount[0]++;
}

void subtract(int value, int index, int length)
{
	if (currentHaveCount[1] == 0) return;

	currentHaveCount[1]--;
	value = value - arr[++index];

	dfs(value, index, length);
	currentHaveCount[1]++;
}

void multiply(int value, int index, int length)
{
	if (currentHaveCount[2] == 0) return;

	currentHaveCount[2]--;
	value = value * arr[++index];

	dfs(value, index, length);
	currentHaveCount[2]++;
}

void divide(int value, int index, int length)
{
	if (currentHaveCount[3] == 0) return;

	currentHaveCount[3]--;
	value = value / arr[++index];

	dfs(value, index, length);
	currentHaveCount[3]++;
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
		cin >> arr[i];
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> currentHaveCount[i];
	}

	dfs(arr[0], 0, n);

	cout << maxResult << '\n';
	cout << minResult;

	return 0;
}