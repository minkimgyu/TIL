#include <iostream>
using namespace std;

const int maxSize = 3000000 + 3000 + 5;
int arr[maxSize];

int visit[3000 + 5];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, d, k, c;
	cin >> n >> d >> k >> c;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	// 추가로 더 붙어주기
	for (int i = 0; i < k - 1; i++)
	{
		arr[i + n] = arr[i];
	}

	int right = 0;
	int pickCount = 0;
	int maxPickCount = 0;

	visit[c] += 1;
	pickCount = 1;

	for (int left = 0; left < n; left++)
	{
		while (right - left < k)
		{
			if (visit[arr[right]] == 0) pickCount++;
			visit[arr[right]]++;

			maxPickCount = max(maxPickCount, pickCount);
			right++;
		}
		
		if (visit[arr[left]] == 1) pickCount--;
		visit[arr[left]]--;
	}

	cout << maxPickCount;
	return 0;
}