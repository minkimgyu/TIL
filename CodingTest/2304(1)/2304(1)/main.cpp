#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int minRange = 1001;
int maxRange = -1;

map<int, int> mapArr;
int n, result = 0;

bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int pos, height;
		cin >> pos >> height;

		mapArr[pos] = height;
		if (maxRange < pos) maxRange = pos;
		if (minRange > pos) minRange = pos;
	}

	for (int i = minRange; i <= maxRange; i++)
	{
		if (i == minRange || i == maxRange)
		{
			result += mapArr[i];
		}
		else
		{
			int maxLeft = 0;
			for (int j = minRange; j < i; j++)
			{
				if (mapArr[j] > maxLeft) maxLeft = mapArr[j];
			}

			int maxRight = 0;
			for (int j = i + 1; j <= maxRange; j++)
			{
				if (mapArr[j] > maxRight) maxRight = mapArr[j];
			}

			int minHeight = min(maxLeft, maxRight);
			result += max(minHeight, mapArr[i]);
		}
	}

	cout << result;

	return 0;
}