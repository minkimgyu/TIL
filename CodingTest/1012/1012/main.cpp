#include <iostream>
#include <list>
#include <vector>
using namespace std;

const int mapSize = 55;
const int closeCnt = 4;
pair<int, int> closePos[closeCnt] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

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

	T Back()
	{
		return _list.back();
	}

private:
	list<T> _list;
};

vector<pair<int, int>> ReturnClosePos(int** map, pair<int, int> pos, int m, int n)
{
	vector<pair<int, int>> allClosePos;

	for (int i = 0; i < closeCnt; i++)
	{
		pair<int, int> newPos;

		// first - x, second - y
		newPos.first = pos.first + closePos[i].first;
		newPos.second = pos.second + closePos[i].second;

		if (newPos.first >= 0 && newPos.first < m && newPos.second >= 0 && newPos.second < n)
		{
			allClosePos.push_back(newPos);
		}
	}

	return allClosePos;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> outputs; 

	int cnt;
	cin >> cnt;

	for (int z = 0; z < cnt; z++)
	{
		int m, n, k;
		cin >> m >> n >> k;

		int result = 0;

		int** map = new int* [mapSize];
		for (int i = 0; i < mapSize; i++)
		{
			map[i] = new int[mapSize];
		}

		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m; x++)
			{
				map[y][x] = 0;
			}
		}

		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;

			map[y][x] = 1;
		}

		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m; x++)
			{
				if (map[y][x] == 0) continue;

				Queue<pair<int, int>> queue;

				pair<int, int> currentPos = { x, y };
				map[currentPos.second][currentPos.first] = 0;

				queue.Push(currentPos);
				result += 1;

				while (queue.IsEmpty() == false)
				{
					pair<int, int> pos = queue.Front();
					queue.Pop();

					vector<pair<int, int>> closePos = ReturnClosePos(map, pos, m, n);

					int size = closePos.size();
					for (int j = 0; j < size; j++)
					{
						if (map[closePos[j].second][closePos[j].first] == 0) continue;
						map[closePos[j].second][closePos[j].first] = 0;

						queue.Push(closePos[j]);
					}
				}
			}
		}

		outputs.push_back(result);
	}
	
	int outputSize = outputs.size();
	for (int i = 0; i < outputSize; i++)
	{
		cout << outputs[i];
		if (i != outputSize - 1) cout << "\n";
	}

	return 0;
}