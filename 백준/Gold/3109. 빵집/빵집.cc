#include <iostream>
#include <string>
using namespace std;

const int row = 10000 + 5;
const int col = 500 + 5;

int arr[row][col];
int visit[row][col];

pair<int, int> nearPoints[3] = { {-1, 1}, {0, 1}, {1, 1} }; // 오른쪽 위로 밀착시키기
int r, c;
int result = 0;

bool findPath(pair<int, int> start)
{
	arr[start.first][start.second] = 1;
	if (start.second == c - 1) // 마지막 열에 도착한 경우
	{
		result++;
		return true;
	}

	for (int i = 0; i < 3; i++)
	{
		pair<int, int> nearPoint = { start.first + nearPoints[i].first, start.second + nearPoints[i].second };

		if (nearPoint.first >= 0 && nearPoint.first < r && arr[nearPoint.first][nearPoint.second] == 0)
		{
			if (findPath(nearPoint))
			{
				return true;
			}
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;
	cin.ignore();

	for (int i = 0; i < r; i++)
	{
		string s;
		getline(cin, s);

		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == '.')
			{
				arr[i][j] = 0;
			}
			else if(s[j] == 'x')
			{
				arr[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < r; i++)
	{
		findPath({ i, 0 });
	}

	cout << result;
	return 0;
}