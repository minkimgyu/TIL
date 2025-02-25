#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000][3];

int main()
{
	int n;
	cin >> n;

	int maxFirst, maxSecond, maxThird;
	int minFirst, minSecond, minThird;

	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			int first, second, third;
			cin >> first >> second >> third;

			maxFirst = minFirst = first;
			maxSecond = minSecond = second;
			maxThird = minThird = third;
		}
		else
		{
			int tmpFirst, tmpSecond, tmpThird;

			// 기존 Max값
			tmpFirst = maxFirst;
			tmpSecond = maxSecond;
			tmpThird = maxThird;

			int first, second, third;
			cin >> first >> second >> third;

			maxFirst = max(tmpFirst + first, tmpSecond + first);
			maxSecond = max(max(tmpFirst + second, tmpSecond + second), tmpThird + second);
			maxThird = max(tmpSecond + third, tmpThird + third);

			// 기존 Max값
			tmpFirst = minFirst;
			tmpSecond = minSecond;
			tmpThird = minThird;

			minFirst = min(tmpFirst + first, tmpSecond + first);
			minSecond = min(min(tmpFirst + second, tmpSecond + second), tmpThird + second);
			minThird = min(tmpSecond + third, tmpThird + third);
		}
	}

	cout << max(max(maxFirst, maxSecond), maxThird);
	cout << " ";
	cout << min(min(minFirst, minSecond), minThird);
	return 0;
}


//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int arr[100000][3];
//
//int maxDP[100000][3];
//int minDP[100000][3];
//
//int main()
//{
//	int n;
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			int item;
//			cin >> item;
//
//			arr[i][j] = item;
//
//			if (i == 0)
//			{
//				minDP[i][j] = item;
//				maxDP[i][j] = item;
//			}
//			else
//			{
//				minDP[i][j] = 900000;
//				maxDP[i][j] = 0;
//			}
//		}
//	}
//
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			int left, current, right;
//
//			switch (j)
//			{
//			case 0:
//
//				current = 0;
//				right = 1;
//
//				maxDP[i + 1][current] = max(maxDP[i][j] + arr[i + 1][current], maxDP[i + 1][current]);
//				maxDP[i + 1][right] = max(maxDP[i][j] + arr[i + 1][right], maxDP[i + 1][right]);
//
//				minDP[i + 1][current] = min(minDP[i][j] + arr[i + 1][current], minDP[i + 1][current]);
//				minDP[i + 1][right] = min(minDP[i][j] + arr[i + 1][right], minDP[i + 1][right]);
//				break;
//
//			case 1:
//				left = 0;
//				current = 1;
//				right = 2;
//
//				maxDP[i + 1][left] = max(maxDP[i][j] + arr[i + 1][left], maxDP[i + 1][left]);
//				maxDP[i + 1][current] = max(maxDP[i][j] + arr[i + 1][current], maxDP[i + 1][current]);
//				maxDP[i + 1][right] = max(maxDP[i][j] + arr[i + 1][right], maxDP[i + 1][right]);
//
//				minDP[i + 1][left] = min(minDP[i][j] + arr[i + 1][left], minDP[i + 1][left]);
//				minDP[i + 1][current] = min(minDP[i][j] + arr[i + 1][current], minDP[i + 1][current]);
//				minDP[i + 1][right] = min(minDP[i][j] + arr[i + 1][right], minDP[i + 1][right]);
//
//				break;
//
//			case 2:
//				left = 1;
//				current = 2;
//
//				maxDP[i + 1][left] = max(maxDP[i][j] + arr[i + 1][left], maxDP[i + 1][left]);
//				maxDP[i + 1][current] = max(maxDP[i][j] + arr[i + 1][current], maxDP[i + 1][current]);
//
//				minDP[i + 1][left] = min(minDP[i][j] + arr[i + 1][left], minDP[i + 1][left]);
//				minDP[i + 1][current] = min(minDP[i][j] + arr[i + 1][current], minDP[i + 1][current]);
//				break;
//			}
//		}
//	}
//
//	cout << max(max(maxDP[n - 1][0], maxDP[n - 1][1]), maxDP[n - 1][2]) << " ";
//	cout << min(min(minDP[n - 1][0], minDP[n - 1][1]), minDP[n - 1][2]);
//	return 0;
//}