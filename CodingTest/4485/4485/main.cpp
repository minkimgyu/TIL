#include <iostream>
#include <vector>
using namespace std;

const int mapSize = 125;
int arr[mapSize][mapSize];
int dp[mapSize][mapSize];

int offset[2]{ -1, 1 };

vector<pair<int, int>> ReturnCloseNode(pair<int, int> pos, int n)
{
	vector<pair<int, int>> closeNodes;

	for (int i = 0; i < 2; i++)
	{
		pair<int, int> point;
		point.first = pos.first + offset[i];
		point.second = pos.second;

		if (point.first < 0 || point.second < 0 || point.first >= n || point.second >= n) continue;

		closeNodes.push_back(point);
	}

	for (int i = 0; i < 2; i++)
	{
		pair<int, int> point;
		point.first = pos.first;
		point.second = pos.second + offset[i];

		if (point.first < 0 || point.second < 0 || point.first >= n || point.second >= n) continue;

		closeNodes.push_back(point);
	}

	return closeNodes;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	const int size = 125;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tmp; 
			cin >> tmp;

			arr[i][j] = tmp;
			dp[i][j] = 2000;
		}
	}

	pair<int, int> startPos;
	startPos.first = 0;
	startPos.second = 0;
	dp[startPos.second][startPos.first] = arr[startPos.second][startPos.first];

	int totalSum = arr[startPos.second][startPos.first]; // 시작 값 넣기

	while (1)
	{
		vector<pair<int, int>> closeNodes = ReturnCloseNode(startPos, n);

		pair<int, int> storedPos;
		int storedSum = 2000;

		int size = closeNodes.size();
		for (int i = 0; i < size; i++)
		{
			int sum = dp[startPos.second][startPos.first] + arr[closeNodes[i].second][closeNodes[i].first];

			if (sum < dp[closeNodes[i].second][closeNodes[i].first])
				dp[closeNodes[i].second][closeNodes[i].first] = sum;

			if (closeNodes[i].first == n - 1 && closeNodes[i].second == n - 1)
			{
				cout << dp[closeNodes[i].second][closeNodes[i].first];
				return 0;
			}

			if (storedSum > sum)
			{
				storedSum = sum;
				storedPos = closeNodes[i];
			}
		}

		startPos = storedPos;
	}


	return 0;
}