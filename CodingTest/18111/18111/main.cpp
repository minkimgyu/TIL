#include <iostream>
using namespace std;

const int maxSize = 500;
int arr[maxSize][maxSize]{ 0 };

long long int ReturnTime(int n, int m, long long int blockHeight)
{
	int time = 0;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			long long int height = blockHeight - arr[x][y];
			if (height > 0)
			{
				time += height;
			}
			else
			{
				time += height * -2;
			}
		}
	}

	return time;
}

// min 값과 max 값을 찾고 그 사이를 순회하는 문제
// 위 범위 밖으로 벗어날 이유가 없기 때문에 min, max 값을 선정할 수 있음
// 
// 단위가 커보이지만 2500 * 256이라서 실제 연산은 얼마 안 된다.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, b;
	cin >> n >> m >> b;

	int size = n * m;

	int bottomBlockHeight = -1;
	int topBlockHeight = -1;
	int sum = 0;
	

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			cin >> arr[x][y];

			if (x == 0 && y == 0)
			{
				bottomBlockHeight = topBlockHeight = arr[x][y];
			}
			else
			{
				if (bottomBlockHeight > arr[x][y]) bottomBlockHeight = arr[x][y];
				else if(topBlockHeight < arr[x][y]) topBlockHeight = arr[x][y];
			}

			sum += arr[x][y];
		}
	}

	sum += b;

	int maxBlockHeight;
	maxBlockHeight = sum / size; // 분배해서 모든 블록을 쓴다는 가정하에 만들 수 있는 높이 --> 이 경우에는 가장 높은 블록보다 높게 나올 수 있음
	if (maxBlockHeight > topBlockHeight) maxBlockHeight = topBlockHeight; // 그래서 max보다 크면 줄여줘야함

	long long int minTime = 0;
	int height = 0;

	for (int i = bottomBlockHeight; i <= maxBlockHeight; i++)
	{
		if (i == bottomBlockHeight)
		{
			minTime = ReturnTime(n, m, i);
			height = i;
		}
		else
		{
			int time = ReturnTime(n, m, i);
			if (time <= minTime)
			{
				minTime = time;
				height = i; // 시간이 같은 경우 땅 높이가 더 큰 값을 구하기 때문
			}
		}
	}

	cout << minTime << " " << height;

	return 0;
}