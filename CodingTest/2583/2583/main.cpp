#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
using namespace std;

int map[100][100];

struct Vector2
{
public:
	int _x, _y;
};

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

	T Front()
	{
		return _list.front();
	}

	T Back()
	{
		return _list.back();
	}

	int Size()
	{
		return _list.size();
	}

	bool IsEmpty()
	{
		return Size() == 0;
	}

private:
	list<T> _list;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n, k;
	cin >> m >> n >> k;

	for (int i = 0; i < k; i++)
	{
		Vector2 bottomLeft;
		Vector2 topRight;
		cin >> bottomLeft._x >> bottomLeft._y >> topRight._x >> topRight._y;

		int width = topRight._x - bottomLeft._x;
		int height = topRight._y - bottomLeft._y;

		for (int j = 0; j < width; j++)
		{
			for (int z = 0; z < height; z++)
			{
				map[bottomLeft._y + z][bottomLeft._x + j] = 1;
			}
		}
	}
	
	vector<int> sizeStorage;
	int cnt = 0;

	Queue<Vector2> queue;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Vector2 pos;
			pos._x = j;
			pos._y = i;
			
			if (map[pos._y][pos._x] == 1) continue;
			map[pos._y][pos._x] = 1; // 처음 넣을 노드 초기화

			queue.Push(pos);
			cnt++;

			int currentSize = 1;
			while (queue.Size() > 0)
			{
				Vector2 vec = queue.Front();
				queue.Pop();

				vector<Vector2> closeVecStorage;

				Vector2 left;
				left._x = vec._x - 1;
				left._y = vec._y;
				if (left._x >= 0) closeVecStorage.push_back(left);

				Vector2 right;
				right._x = vec._x + 1;
				right._y = vec._y;
				if (right._x < n) closeVecStorage.push_back(right);

				Vector2 up;
				up._x = vec._x;
				up._y = vec._y - 1;
				if (up._y >= 0) closeVecStorage.push_back(up);

				Vector2 down;
				down._x = vec._x;
				down._y = vec._y + 1;
				if (down._y < m) closeVecStorage.push_back(down);

				int size = closeVecStorage.size();
				for (int p = 0; p < size; p++)
				{
					Vector2 closePos = closeVecStorage[p];
					if (map[closePos._y][closePos._x] == 1) continue;
					

					map[closePos._y][closePos._x] = 1;
					queue.Push(closePos);
					currentSize++;
				}
			}

			sizeStorage.push_back(currentSize);
		}
	}

	sort(sizeStorage.begin(), sizeStorage.end());

	cout << cnt << "\n";
	for (int z = 0; z < cnt; z++)
	{
		if(z == cnt - 1) cout << sizeStorage[z];
		else cout << sizeStorage[z] << " ";
	}

	return 0;
}