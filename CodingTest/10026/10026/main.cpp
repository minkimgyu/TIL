<<<<<<< HEAD
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n;
const int maxSize = 105;
char map[maxSize][maxSize];
char rgMap[maxSize][maxSize];

const int offsetSize = 4;
pair<int, int> offsets[4] =
{
	{0, 1},
	{0, -1},
	{1, 0},
	{-1, 0}
};

int bfs(char map[maxSize][maxSize])
{
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] != 'R' && map[i][j] != 'G' && map[i][j] != 'B') continue;

			count += 1;
			char currentChar = map[i][j];

			queue<pair<int, int>> qu;
			map[i][j] = 'C';
			qu.push({ i, j });

			while (qu.empty() == false)
			{
				pair<int, int> front = qu.front();
				qu.pop();

				for (int k = 0; k < offsetSize; k++)
				{
					pair<int, int> point;
					point.first = front.first + offsets[k].first;
					point.second = front.second + offsets[k].second;

					if (point.first < 0 || point.second < 0 || point.first >= n || point.second >= n) continue;
					if (currentChar == map[point.first][point.second])
					{
						map[point.first][point.second] = 'C';
						qu.push(point);
					}
				}
			}
		}
	}

	return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		string line;
		getline(cin, line);
		for (int j = 0; j < n; j++)
		{
			map[i][j] = line[j];
			if (line[j] == 'G') rgMap[i][j] = 'R';
			else rgMap[i][j] = line[j];
		}
	}

	cout << bfs(map) << '\n';
	cout << bfs(rgMap);

	return 0;
=======
#include <iostream>
#include <list>
#include <vector>
using namespace std;

template <typename T>
class Queue
{
public:
	void Push(T item)
	{
		_list.push_back(item);
	}

	void Pop()
	{
		_list.pop_front();
	}

	int Size()
	{
		return _list.size();
	}

	bool IsEmpty()
	{
		return Size() == 0;
	}

	T Front()
	{
		return _list.front();
	}

private:
	list<T> _list;
};

const int mapSize = 100;
int map[mapSize][mapSize]{0};
int map2[mapSize][mapSize]{0};
//bool visit[mapSize][mapSize]{false};

const int offsetSize = 4;
pair<int, int> offset[offsetSize] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

vector<pair<int, int>> ReturnClosePoints(pair<int, int> pos, int n)
{
	vector<pair<int, int>> points;
	for (int i = 0; i < offsetSize; i++)
	{
		pair<int, int> point = { pos.first + offset[i].first, pos.second + offset[i].second };
		if (point.first < 0 || point.first >= n || point.second < 0 || point.second >= n) continue;

		points.push_back(point);
	}

	return points;
}

// 방문 체크할 때 근접한 노드를 검색하는 부분에서 해야한다.
// visit 배열을 써도 되고 배열을 그냥 2개 써도 상관 없다.

// 배열을 2개 쓰면 시간 상 우위가 있고
// visit 배열을 쓰면 메모리 상 우위가 있다.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		char line[101];
		cin.getline(line, n + 1);

		for (int j = 0; j < n; j++)
		{
			int item = (int)line[j] - 65;
			map[i][j] = item;

			if (item == 17) item = 6; // R이면 G 취급해준다.
			map2[i][j] = item;
		}
	}

	int normalCnt = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//if (visit[i][j] == true) continue;
			int item = map[i][j];
			if (item == -1) continue;

			normalCnt++;

			Queue<pair<int, int>> queue;
			queue.Push({ i, j });
			//visit[i][j] = true;

			while (queue.IsEmpty() == false)
			{
				pair<int, int> pos = queue.Front();
				queue.Pop();

				vector<pair<int, int>> points = ReturnClosePoints(pos, n);
				int pointSize = points.size();

				for (int z = 0; z < pointSize; z++)
				{
					if (map[points[z].first][points[z].second] != item) continue;

					//if (visit[points[z].first][points[z].second] == true) continue;
					map[points[z].first][points[z].second] = -1;
					//visit[points[z].first][points[z].second] = true;
					queue.Push(points[z]);
				}
			}

		}
	}

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		visit[i][j] = false;
	//	}
	//}

	int notNormalCnt = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//if (visit[i][j] == true) continue;

			int item = map2[i][j];
			if (item == -1) continue;

			if (item == 17) item = 6; // R이면 G 취급해준다.
			notNormalCnt++;

			Queue<pair<int, int>> queue;
			queue.Push({ i, j });
			//visit[i][j] = true;

			while (queue.IsEmpty() == false)
			{
				pair<int, int> pos = queue.Front();
				queue.Pop();

				vector<pair<int, int>> points = ReturnClosePoints(pos, n);
				int pointSize = points.size();

				for (int z = 0; z < pointSize; z++)
				{
					int value = map2[points[z].first][points[z].second];
					if (value == 17) value = 6; // R이면 G 취급해준다.

					if (value != item) continue;

					//if (visit[points[z].first][points[z].second] == true) continue;
					map2[points[z].first][points[z].second] = -1;
					//visit[points[z].first][points[z].second] = true;
					queue.Push(points[z]);
				}
			}

		}
	}

	cout << normalCnt << " " << notNormalCnt;

	return 0;
>>>>>>> origin/main
}