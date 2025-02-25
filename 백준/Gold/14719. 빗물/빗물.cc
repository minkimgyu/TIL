#include <iostream>
#include <algorithm>
using namespace std;

int h, w, result = 0;

const int maxSize = 500;
int blockHeights[maxSize];

int main()
{
	cin >> h >> w;

	for (int i = 0; i < w; i++)
	{
		int blockHeight;
		cin >> blockHeight;
		blockHeights[i] = blockHeight;
	}

	for (int i = 0; i < w; i++)
	{
		int leftMax = -1;
		int rightMax = -1;

		for (int j = i; j >= 0; j--)
		{
			if (blockHeights[j] > leftMax) leftMax = blockHeights[j];
		}

		for (int j = i; j < w; j++)
		{
			if (blockHeights[j] > rightMax) rightMax = blockHeights[j];
		}

		int height = min(leftMax, rightMax);

		if (height > blockHeights[i]) result += height - blockHeights[i];

	}

	cout << result;

	return 0;
}