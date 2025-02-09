#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxSize = 50 + 5;
int newMap[maxSize][maxSize];

vector<pair<int, int>> chickenPoints;
vector<pair<int, int>> housePoints;

int n, m;
int result = 0;

void combine()
{
	int chickenPointSize = chickenPoints.size();

	for (int i = 0; i < (1 << chickenPointSize); i++) // 3개의 경우 2 * 2 * 2 -> 0 0 0
	{
		vector<int> items;

		for (int j = 0; j < chickenPointSize; j++)
		{
			if (i & (1 << j))
			{
				// 집에서 돌려야 함 -> 인덱스에 맞는 치킨집을 찾는 경우를 택해야 한다.
				items.push_back(j);
			}
		}

		int totalLength = 0;
		
		if (items.size() == m)
		{
			for (int k = 0; k < housePoints.size(); k++)
			{
				int length = 100;

				for (int z = 0; z < items.size(); z++)
				{
					length = min(length, abs(chickenPoints[items[z]].first - housePoints[k].first) + abs(chickenPoints[items[z]].second - housePoints[k].second));
				}

				totalLength += length;
			}

			result = min(result, totalLength);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int item;
			cin >> item;

			if (item == 1) housePoints.push_back({ i, j });
			else if (item == 2) chickenPoints.push_back({ i, j });
		}
	}

	result = (50 + 50) * 100;
	combine();

	cout << result;
	return 0;
}