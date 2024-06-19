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
bool visit[mapSize][mapSize]{false};

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
		}
	}

	int normalCnt = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visit[i][j] == true) continue;

			int item = map[i][j];
			normalCnt++;

			Queue<pair<int, int>> queue;
			queue.Push({ i, j });
			visit[i][j] = true;

			while (queue.IsEmpty() == false)
			{
				pair<int, int> pos = queue.Front();
				queue.Pop();

				vector<pair<int, int>> points = ReturnClosePoints(pos, n);
				int pointSize = points.size();

				for (int z = 0; z < pointSize; z++)
				{
					if (map[points[z].first][points[z].second] != item) continue;

					if (visit[points[z].first][points[z].second] == true) continue;

					visit[points[z].first][points[z].second] = true;
					queue.Push(points[z]);
				}
			}

		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			visit[i][j] = false;
		}
	}

	int notNormalCnt = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visit[i][j] == true) continue;

			int item = map[i][j];
			if (item == 17) item = 6; // R이면 G 취급해준다.

			notNormalCnt++;

			Queue<pair<int, int>> queue;
			queue.Push({ i, j });
			visit[i][j] = true;

			while (queue.IsEmpty() == false)
			{
				pair<int, int> pos = queue.Front();
				queue.Pop();

				vector<pair<int, int>> points = ReturnClosePoints(pos, n);
				int pointSize = points.size();

				for (int z = 0; z < pointSize; z++)
				{
					int value = map[points[z].first][points[z].second];
					if (value == 17) value = 6; // R이면 G 취급해준다.

					if (value != item) continue;

					if (visit[points[z].first][points[z].second] == true) continue;

					visit[points[z].first][points[z].second] = true;
					queue.Push(points[z]);
				}
			}

		}
	}

	cout << normalCnt << " " << notNormalCnt;

	return 0;
}