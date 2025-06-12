#include <iostream>
#include <string>
#include <deque>
using namespace std;

const int maxSize = 50 + 5;
int arr[maxSize][maxSize];
int changeArr[maxSize][maxSize];

int n;
pair<int, int> offset[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

bool InRange(pair<int, int> pos)
{
	if (pos.first < 0 || pos.second < 0 || pos.first >= n || pos.second >= n) return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			changeArr[i][j] = maxSize * maxSize;
		}
	}

	deque<pair<int, pair<int, int>>> dq;
	dq.push_back({ 0, { 0, 0 } });
	changeArr[0][0] = 0;

	while (dq.empty() == false)
	{
		pair<int, pair<int, int>> front = dq.front(); dq.pop_front();

		for (int i = 0; i < 4; i++)
		{
			pair<int, int> nearPos = { front.second.first + offset[i].first, front.second.second + offset[i].second };
			if (InRange(nearPos) == false) continue;

			if (arr[nearPos.first][nearPos.second] == 0 && changeArr[nearPos.first][nearPos.second] > front.first + 1)
			{
				changeArr[nearPos.first][nearPos.second] = front.first + 1;
				dq.push_front({ front.first + 1, nearPos });
			}
			else if (arr[nearPos.first][nearPos.second] == 1 && changeArr[nearPos.first][nearPos.second] > front.first)
			{
				changeArr[nearPos.first][nearPos.second] = front.first;
				dq.push_front({ front.first, nearPos });
			}
		}
	}

	cout << changeArr[n - 1][n - 1];
	return 0;
}