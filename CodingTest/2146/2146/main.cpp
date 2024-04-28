#include <iostream>
#include <list>
#include <vector>
using namespace std;

int maxSize = 100;
int map[100][100];

int visit[100][100]{ 0 };

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

vector<pair<int, int>> ReturnClosePos(pair<int, int> pos, int n)
{
	vector<pair<int, int>> closePos;

	pair<int, int> leftPos;
	leftPos.first = pos.first - 1;
	leftPos.second = pos.second;
	if (leftPos.first >= 0) closePos.push_back(leftPos);

	pair<int, int> rightPos;
	rightPos.first = pos.first + 1;
	rightPos.second = pos.second;
	if (rightPos.first < n) closePos.push_back(rightPos);

	pair<int, int> upPos;
	upPos.first = pos.first;
	upPos.second = pos.second - 1;
	if (upPos.second >= 0) closePos.push_back(upPos);

	pair<int, int> downPos;
	downPos.first = pos.first;
	downPos.second = pos.second + 1;
	if (downPos.second < n) closePos.push_back(downPos);

	return closePos;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	int landCnt = 2;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] <= landCnt && map[i][j] != 1) continue;

			Queue<pair<int, int>> queue;

			pair<int, int> pos;
			pos.first = j;
			pos.second = i;
			queue.Push(pos);

			map[i][j] = landCnt;

			while (queue.Size() > 0)
			{
				pair<int, int> pos = queue.Front();
				queue.Pop();

				vector<pair<int, int>> closePos = ReturnClosePos(pos, n);
				int size = closePos.size();
				for (int z = 0; z < size; z++)
				{
					if (map[closePos[z].second][closePos[z].first] <= landCnt
						&& map[closePos[z].second][closePos[z].first] != 1) continue;

					queue.Push(closePos[z]);
					map[closePos[z].second][closePos[z].first] = landCnt;
				}
			}

			landCnt++;
		}
	}

	int currentLandIndex = 0;
	int minDistance = 30000;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 0) continue; // 0이면 continue 시켜주기 --> 시작은 땅에서 해야함

			currentLandIndex = map[i][j];

			Queue<pair<int, int>> queue;
			vector<pair<int, int>> storedVec;

			pair<int, int> pos;
			pos.first = j;
			pos.second = i;
			queue.Push(pos);
			storedVec.push_back(pos);

			visit[i][j] = 1;

			bool findRoute = false;
			while (queue.Size() > 0)
			{
				pair<int, int> pos = queue.Front();
				queue.Pop();

				vector<pair<int, int>> closePos = ReturnClosePos(pos, n);
				int size = closePos.size();
				for (int z = 0; z < size; z++)
				{
					if (visit[closePos[z].second][closePos[z].first] >= 1 || map[closePos[z].second][closePos[z].first] == currentLandIndex) continue;
					int distance = visit[pos.second][pos.first] + 1;

					// 다른 영역 지점에 도달한 경우
					if (map[closePos[z].second][closePos[z].first] != 0)
					{
						if (minDistance > distance)
						{
							minDistance = distance;
						}
						findRoute = true; 
						break;
					}

					visit[closePos[z].second][closePos[z].first] = distance;

					queue.Push(closePos[z]);
					storedVec.push_back(closePos[z]);
				}

				if (findRoute == true) break;
			}

			int storedSize = storedVec.size();
			for (int k = 0; k < storedSize; k++)
			{
				visit[storedVec[k].second][storedVec[k].first] = 0;
			}
		}
	}

	// 초기 값이 유지된 경우
	if (minDistance == 30000)
	{
		minDistance = 0;
		cout << minDistance;
	}
	else
	{
		// 처음 위치 + 끝 위치 빼주기
		cout << minDistance - 2;
	}


	return 0;
}