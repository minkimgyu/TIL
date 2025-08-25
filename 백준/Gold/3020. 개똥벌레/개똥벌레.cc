#include <iostream>
using namespace std;

int bottomSum[500000 + 5]; // 석순
int topSum[500000 + 5]; // 종유석

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, h;
	cin >> n >> h;

	for (int i = 1; i <= n; i++)
	{
		int height;
		cin >> height;

		if (i % 2 == 0)
		{
			topSum[h - height + 1] += 1;
		}
		else
		{
			bottomSum[height] += 1;
		}
	}

	for (int i = 1; i < h; i++)
	{
		topSum[i + 1] += topSum[i];
	}

	for (int i = h - 1; i > 0; i--)
	{
		bottomSum[i - 1] += bottomSum[i];
	}
	
	int result = 200000;
	int minCount = 0;

	for (int i = 1; i <= h; i++)
	{
		int sum = topSum[i] + bottomSum[i];
		if (result > sum)
		{
			result = sum;
			minCount = 1;
		}
		else if (result == sum)
		{
			minCount++;
		}
	}

	cout << result << " " << minCount;
	return 0;
}