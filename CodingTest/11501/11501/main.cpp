#include <iostream>
#include <list>
using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

// 백트래킹을 해서 뒤에서부터 큰 수를 리스트에 넣어서 보면 쉽다.
// 처음에는 정렬로 접근했지만 앞에서 나온 수가 리스트에서 빠져야 하는데 이것이 불가능해서 틀렸다.
// 
// 이런 문제 보면 가장 큰 수가 나올 때 까지 더하고 빼므로 뒤에서부터 큰 수를 모아온다고 생각해야할 것 같다.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	long long int* output = new long long int[t];

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		int* arr = new int[n];

		for (int j = 0; j < n; j++)
		{
			int tmp;
			cin >> tmp;
			arr[j] = tmp;
		}

		long long int benefit = 0;
		list<int> backTracking;

		int tmpMax = 0;
		for (int z = n - 1; z >= 0; z--)
		{
			if (tmpMax <= arr[z])
			{
				tmpMax = arr[z];
				backTracking.push_front(tmpMax);
			}
		}

		list<int>::iterator iter = backTracking.begin();
		//int maxIndex = 0; // 최대값이 지나면 하나씩 뒤로 돌린다.

		long long int cnt = 0; // 몇개가 모였는지 판단.
		long long int sum = 0; // 모인 값의 총합

		for (int k = 0; k < n; k++)
		{
			if (arr[k] == *iter) // 마지막인 경우는 무조건 빼야지 이득임
			{
				benefit += arr[k] * cnt - sum;
				cnt = 0;
				sum = 0;
				iter++;
			}
			else
			{
				cnt++;
				sum += arr[k];
			}
		}

		output[i] = benefit;
	}

	for (int i = 0; i < t; i++)
	{
		if(i == t - 1) cout << output[i];
		else cout << output[i] << '\n';
	}

	return 0;
}