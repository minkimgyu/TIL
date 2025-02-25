#include <iostream>
#include <stack>
using namespace std;

const int maxSize = 80000;
int arr[maxSize];

// 생각나는 반례
// 
// n이 1인 경우
// 
// n이 80,000인 경우 - result의 범위가 작은 경우
// 
// 
// 1, 2, 3, 4, 5, 6, 7, 8, 9 ... 80,000까지 다 더하게 된다.
// 이로써 int 범위 초과 문제가 발생함
//
//


int main()
{
	int n;
	cin >> n;

	long long int result = 0;

	stack<pair<int, long long int>> s;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = n - 1; i > -1; i--)
	{
		int item = arr[i];

		if (s.empty() == true)
		{
			s.push({ item , 0 });
		}
		else
		{
			long long int roofCount = 0;
			while (s.empty() == false && s.top().first < item)
			{
				roofCount += s.top().second + 1;
				s.pop();
			}

			s.push({ item, roofCount });
			result += roofCount;
		}
	}

	cout << result;
	return 0;
}