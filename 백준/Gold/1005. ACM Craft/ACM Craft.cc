#include <iostream>
#include <queue>
using namespace std;

const int maxSize = 1000 + 5;
vector<int> input[maxSize];
int inter[maxSize];
bool clear[maxSize];
int timeCost[maxSize];

int dp[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);

	int t;
	cin >> t;

	for (int z = 0; z < t; z++)
	{
		int n, k;
		cin >> n >> k;

		for (int i = 1; i <= n; i++)
		{
			cin >> timeCost[i];
		}

		for (int i = 0; i < k; i++)
		{
			int start, end;
			cin >> start >> end;
			input[start].push_back(end);
			inter[end]++;
		}

		int w;
		cin >> w;

		queue<int> q;
		for (int i = 1; i <= n; i++)
		{
			if (inter[i] == 0 && clear[i] == false)
			{
				clear[i] = true;
				q.push(i);
				dp[i] = timeCost[i];
			}
		}

		bool canClear = false;

		while (q.empty() == false)
		{
			int index = q.front(); q.pop();
			for (int j = 0; j < input[index].size(); j++)
			{
				inter[input[index][j]]--;
				dp[input[index][j]] = max(dp[input[index][j]], dp[index] + timeCost[input[index][j]]); // max 값으로 초기화
			}

			if (index == w)
			{
				canClear = true;
				break;
			}

			for (int i = 1; i <= n; i++)
			{
				if (inter[i] == 0 && clear[i] == false)
				{
					clear[i] = true;
					q.push(i);
				}
			}
		}

		cout << dp[w];
		if (z != t - 1)
		{
			cout << '\n';
			for (int i = 0; i < maxSize; i++)
			{
				input[i].clear();
				inter[i] = 0;
				clear[i] = false;
				timeCost[i] = 0;
				dp[i] = 0;
			}
		}
	}

	return 0;
}