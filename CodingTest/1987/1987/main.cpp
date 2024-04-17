#include <iostream>
#include <vector>
using namespace std;

class Node;

const int mapSize = 20;
Node* map[mapSize][mapSize];

class Node
{
public:
	char _icon;
	int _xIndex, _yIndex;
};

bool abc[26]{ 0 };
int r, c;

void dfs(int x, int y, int* cnt, int* maxCnt)
{
	Node* node = map[y][x];

	int index = node->_icon - 'A';
	if (abc[index] == true) return; // 이미 방문한 경우
	
	*cnt += 1;
	if (*cnt > *maxCnt) *maxCnt = *cnt;
	abc[index] = true;

	if (x > 0) dfs(x - 1, y, cnt, maxCnt);
	if (x < c - 1) dfs(x + 1, y, cnt, maxCnt);
	if (y > 0) dfs(x, y - 1, cnt, maxCnt);
	if (y < r - 1) dfs(x, y + 1, cnt, maxCnt);

	abc[index] = false;
	*cnt -= 1;
	// 백트래킹 시 값을 빼주자
}

// 첫 DFS 문제.. 어렵네

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;
	cin.ignore();

	for (int i = 0; i < r; i++)
	{
		char* arr = new char[mapSize + 1];
		cin.getline(arr, mapSize + 1);
		for (int j = 0; j < c; j++)
		{
			Node* node = new Node();
			node->_yIndex = i;
			node->_xIndex = j;
			node->_icon = arr[j];

			map[i][j] = node;
		}
	}

	int passCnt = 0;
	int maxPassCnt = 0;
	dfs(0, 0, &passCnt, &maxPassCnt);

	cout << maxPassCnt;

	return 0;
}