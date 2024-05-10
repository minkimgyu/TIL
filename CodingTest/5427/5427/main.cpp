#include <iostream>
#include <list>
#include <vector>
using namespace std;

pair<int, int> offset[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

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

vector<pair<char, pair<int, int>>> ReturnCloseNodes(pair<char, pair<int, int>> item, char** arr, int r, int c)
{
	vector<pair<char, pair<int, int>>> closeItems;

	pair<int, int> pos = item.second;
	char icon = item.first;
	for (int i = 0; i < 4; i++)
	{
		pair<int, int> closePos = { pos.first + offset[i].first, pos.second + offset[i].second };

		// 범위를 벗어나는 경우
		if (closePos.first >= c || closePos.second >= r || closePos.first < 0 || closePos.second < 0) continue; // 범위를 벗어나는 경우

		if (icon == arr[closePos.second][closePos.first] || arr[closePos.second][closePos.first] == '#') continue; // 같거나 벽이면 continue

		if (icon == '@' && arr[closePos.second][closePos.first] == '*') continue; // 본인이 @이고 주변이 *인 경우 Pass
		if (icon == '*' && arr[closePos.second][closePos.first] == '@') continue; // 본인이 *이고 주변이 @인 경우 Pass --> 이 경우도 추가해주자
		closeItems.push_back({ arr[closePos.second][closePos.first] , closePos });
	}

	return closeItems;
}

bool CanExit(pair<char, pair<int, int>> item, int r, int c)
{
	if (item.first != '@') return false;

	pair<int, int> pos = item.second;
	for (int i = 0; i < 4; i++)
	{
		pair<int, int> closePos = { pos.first + offset[i].first, pos.second + offset[i].second };

		// @이고 범위를 벗어나는 경우
		if (closePos.first >= c || closePos.second >= r || closePos.first < 0 || closePos.second < 0)
		{
			// 이 경우 루프를 끝냄
			return true;
		}
	}

	return false;
}

// 불을 먼저 옮겨주고 그 다음에 플레이어를 옮겨주는 방식으로 진행해준다.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> results;

	for (int i = 0; i < n; i++)
	{
		int r, c;
		cin >> c >> r;

		Queue<pair<char, pair<int, int>>> fireQueue;
		Queue<pair<char, pair<int, int>>> personQueue;
		char** arr = new char* [r + 1];
		for (int j = 0; j < r; j++)
		{
			arr[j] = new char[c + 1];
			for (int k = 0; k < c; k++)
			{
				char tmp;
				cin >> tmp;

				arr[j][k] = tmp;


				if (tmp == '@')
				{
					pair<char, pair<int, int>> item = { tmp, {k, j} };
					personQueue.Push(item);
				}

				if (tmp == '*')
				{
					pair<char, pair<int, int>> item = { tmp, {k, j} };
					fireQueue.Push(item);
				}
			}
		}

		int result = 0;
		bool exitLoop = false;

		while (fireQueue.IsEmpty() == false || personQueue.IsEmpty() == false)
		{
			result++;
			int queueSize = fireQueue.Size();
			for (int l = 0; l < queueSize; l++)
			{
				pair<char, pair<int, int>> front = fireQueue.Front();
				fireQueue.Pop();

				vector<pair<char, pair<int, int>>> closeNodes = ReturnCloseNodes(front, arr, r, c);
				int size = closeNodes.size();
				for (int z = 0; z < size; z++)
				{
					pair<int, int> closePos = closeNodes[z].second;
					arr[closePos.second][closePos.first] = front.first;
					fireQueue.Push({ arr[closePos.second][closePos.first], closePos });
				}
			}

			queueSize = personQueue.Size();
			for (int l = 0; l < queueSize; l++)
			{
				pair<char, pair<int, int>> front = personQueue.Front();
				personQueue.Pop();

				bool canExit = CanExit(front, r, c);
				if (canExit == true)
				{
					results.push_back(result);
					exitLoop = true;
				}
				if (exitLoop) break;

				vector<pair<char, pair<int, int>>> closeNodes = ReturnCloseNodes(front, arr, r, c);
				int size = closeNodes.size();
				for (int z = 0; z < size; z++)
				{
					pair<int, int> closePos = closeNodes[z].second;
					arr[closePos.second][closePos.first] = front.first;
					personQueue.Push({ arr[closePos.second][closePos.first], closePos });
				}
			}

			if (exitLoop) break;
		}

		if(exitLoop == false) results.push_back(-1);

		for (int j = 0; j < r; j++)
		{
			delete[] arr[j];
		}
		delete[] arr;
	}

	int resultSize = results.size();
	for (int i = 0; i < resultSize; i++)
	{
		if (results[i] == -1)
		{
			cout << "IMPOSSIBLE";
		}
		else
		{
			cout << results[i];
		}

		if (i != resultSize - 1) cout << '\n';
	}

	return 0;
}