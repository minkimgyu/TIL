#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

const int mapSize = 3;

struct Map
{
public:
	int arr[mapSize][mapSize];
	pair<int, int> emptyPoint;
	int time;

	bool operator==(const Map& other) const {
		for (int i = 0; i < mapSize; ++i) {
			for (int j = 0; j < mapSize; ++j) {
				if (arr[i][j] != other.arr[i][j]) return false;
			}
		}
		return true;
	}
};

// 해시 함수를 정의하기 위한 헬퍼
struct MapHasher {
	size_t operator()(const Map& m) const {
		size_t hash = 0;
		for (int i = 0; i < mapSize; ++i) {
			for (int j = 0; j < mapSize; ++j) {
				hash ^= hash * 31 + std::hash<int>()(m.arr[i][j]);
			}
		}
		return hash;
	}
};

int correct[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 0} };

const int offsetSize = 4;
pair<int, int> offsets[offsetSize] =
{
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1}
};

unordered_set<Map, MapHasher> visit;

int bfs(Map map)
{
	bool isClear = false;
	int answer = -1;

	queue<Map> queue;
	queue.push(map);
	visit.insert(map);

	while (queue.empty() == false)
	{
		Map front = queue.front();
		queue.pop();

		pair<int, int> point = front.emptyPoint;
		for (int i = 0; i < offsetSize; i++)
		{
			int x = point.first + offsets[i].first;
			int y = point.second + offsets[i].second;

			if (x < 0 || x >= mapSize || y < 0 || y >= mapSize) continue;

			Map changedMap = front;

			changedMap.emptyPoint = { x, y };

			int item1 = changedMap.arr[point.second][point.first];
			int item2 = changedMap.arr[y][x];

			changedMap.arr[point.second][point.first] = item2;
			changedMap.arr[y][x] = item1;

			bool isMatch = true;
			for (int j = 0; j < mapSize; j++)
			{
				for (int k = 0; k < mapSize; k++)
				{
					if (changedMap.arr[j][k] != correct[j][k])
					{
						isMatch = false;
						break;
					}
				}

				if (isMatch == false) break;
			}

			if (isMatch == true)
			{
				isClear = true;
				changedMap.time++;
				answer = changedMap.time;
				break;
			}


			if(visit.find(changedMap) != visit.end()) continue;

			changedMap.time++;
			queue.push(changedMap);
			visit.insert(changedMap);
		}

		if (isClear) break;
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Map map;

	for (int i = 0; i < mapSize; i++)
	{
		for (int j = 0; j < mapSize; j++)
		{
			int item;
			cin >> item;

			map.arr[i][j] = item;
			if (item != 0) continue;

			map.emptyPoint = { j, i };
			map.time = 0;
		}
	}

	bool isMatch = true;
	for (int j = 0; j < mapSize; j++)
	{
		for (int k = 0; k < mapSize; k++)
		{
			if (map.arr[j][k] != correct[j][k])
			{
				isMatch = false;
				break;
			}
		}

		if (isMatch == false) break;
	}

	if (isMatch == true)
	{
		cout << 0;
	}
	else
	{
		int result = bfs(map);
		cout << result;
	}

	return 0;
}