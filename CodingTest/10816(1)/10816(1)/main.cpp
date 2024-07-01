//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
// 
// 
// https://www.acmicpc.net/board/view/11061
//int dp[20000001];
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int n;
//	cin >> n;
//
//	int* arr = new int[n];
//	for (int i = 0; i < n; i++)
//	{
//		int tmp;
//		cin >> tmp;
//
//		if (dp[tmp + 10000000] > 0)
//		{
//			dp[tmp + 10000000] += 1;
//		}
//		else
//		{
//			arr[i] = tmp;
//			dp[tmp + 10000000] = 1;
//		}
//	}
//
//	int m;
//	cin >> m;
//
//	for (int i = 0; i < m; i++)
//	{
//		int findNum;
//		cin >> findNum;
//
//		cout << dp[findNum + 10000000];
//		if(i != m) cout << " ";
//	}
//
//	return 0;
//}

//#include <iostream>
//#include <map>
//using namespace std;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int n;
//	cin >> n;
//
//	map<int, int> dp;
//
//	for (int i = 0; i < n; i++)
//	{
//		int tmp;
//		cin >> tmp;
//
//		dp[tmp] += 1;
//	}
//
//	int m;
//	cin >> m;
//
//	for (int i = 0; i < m; i++)
//	{
//		int findNum;
//		cin >> findNum;
//
//		cout << dp[findNum];
//		if (i != m) cout << " ";
//	}
//
//	return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[500000]{0, };

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

	sort(arr, arr + n);

	int m;
	cin >> m;

	int* results = new int[m] {0, };

	for (int i = 0; i < m; i++)
	{
		int findNum;
		cin >> findNum;

		int lower, upper;

		int start = 0;
		int end = n;

		while (end > start)
		{
			int mid = (start + end) / 2;

			if (arr[mid] >= findNum)
			{
				end = mid;
			}
			else
			{
				start = mid + 1;
			}
		}

		lower = start;

		start = 0;
		end = n;

		while (end > start)
		{
			int mid = (start + end) / 2;

			if (arr[mid] > findNum)
			{
				end = mid;
			}
			else
			{
				start = mid + 1;
			}
		}

		upper = start;
		results[i] = upper - lower;
	}

	for (int i = 0; i < m; i++)
	{
		cout << results[i];
		if (i != m) cout << " ";
	}

	return 0;
}