#include <iostream>
#include <list>
#include <vector>
using namespace std;

struct Vector2
{
public:
	int _x, _y;
};

class Queue
{
public:
	void Push(Vector2 vec)
	{
		_list.push_back(vec);
	}

	void Pop()
	{
		_list.pop_front();
	}

	Vector2 Front()
	{
		return _list.front();
	}

	Vector2 Back()
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
	list<Vector2> _list;
};

const int maxSize = 500;
int map[maxSize][maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int r, c;
	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> map[i][j];
		}
	}

	int visit = 2;

	int cnt = 0;
	int maxArtSize = 0;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			Vector2 start;
			start._y = i;
			start._x = j;

			int artSize = 0;

			if (map[start._y][start._x] == 0 || map[start._y][start._x] == visit) continue;
			map[start._y][start._x] = visit;

			artSize++;
			if (artSize > maxArtSize) maxArtSize = artSize;

			cnt++;

			Queue queue;
			queue.Push(start);

			while (!queue.IsEmpty())
			{
				Vector2 vec = queue.Front();
				queue.Pop();

				vector<Vector2> closePos;
				Vector2 left = vec;
				left._x--;
				if (left._x >= 0) closePos.push_back(left);

				Vector2 right = vec;
				right._x++;
				if (right._x < c) closePos.push_back(right);

				Vector2 up = vec;
				up._y--;
				if (up._y >= 0) closePos.push_back(up);

				Vector2 down = vec;
				down._y++;
				if (down._y < r) closePos.push_back(down);

				int closeNodeSize = closePos.size();
				for (int z = 0; z < closeNodeSize; z++)
				{
					if (map[closePos[z]._y][closePos[z]._x] == 0 ||
						map[closePos[z]._y][closePos[z]._x] == visit) continue;

					map[closePos[z]._y][closePos[z]._x] = visit;
					queue.Push(closePos[z]);

					artSize++;
					if (artSize > maxArtSize) maxArtSize = artSize;
				}
			}

		}
	}

	cout << cnt << '\n';
	cout << maxArtSize;

	return 0;
}