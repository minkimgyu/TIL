#include <iostream>
using namespace std;

const int maxStudySize = 1000 + 500;
pair<int, int> study[maxStudySize];

// 과목수, 공부 시간
const int maxTimeSize = 10000 + 500;
int dp[maxStudySize][maxTimeSize];

int n, k;

int dfs(int count, int time)
{
	if (count == 0) return 0; // 끝에 도달한 경우 리턴
	if (dp[count][time] != -1) return dp[count][time]; // 이미 계산한 경우

	int left = 0;
	int right = 0;

	left = dfs(count - 1, time); // 선택하지 않는 경우

	if (time - study[count - 1].second >= 0) // 시간이 0보다 같거나 큰 경우
	{
		right = dfs(count - 1, time - study[count - 1].second) + study[count - 1].first; // 선택한 경우
	}

	dp[count][time] = max(left, right);
	return dp[count][time];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i <= k; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			dp[i][j] = -1;
		}
	}

	for (int i = 0; i < k; i++)
	{
		cin >> study[i].first >> study[i].second; // 중요도, 공부 시간
	}

	cout << dfs(k, n);
	return 0;
}