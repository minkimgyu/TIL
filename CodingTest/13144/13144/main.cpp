#include <iostream>
using namespace std;

int n;

const int maxSize = 100000;
int arr[maxSize];

bool visit[maxSize + 1]; // 1부터 100,000까지


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int start = 0;
	int end = 0;

	long long int result = 0; // 최대 경우의 수는 1부터 100,000까지 더한 것으로 값은 5,000,050,000이다.

	visit[arr[end]] = true;

	while (start < n)
	{
		if (end < n - 1 && visit[arr[end + 1]] == false) // 다음 end가 false인 경우를 보기
		{
			end++;
			visit[arr[end]] = true;
		}
		else
		{
			result += end - start + 1;
			visit[arr[start]] = false;
			start++;
		}
	}

	cout << result;

	return 0;
}