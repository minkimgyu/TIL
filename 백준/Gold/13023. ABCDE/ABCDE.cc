#include <iostream>
#include <vector>
using namespace std;

int n, m;

const int maxCorrectSize = 5;

const int maxSize = 2000 + 5;
int arr[maxSize];
bool visit[maxSize]; // true가 되는 경우가 A, B, C, D, E -> 총 5개 되면 됨

vector<int> connections[maxSize];

bool canFind = false;

void dfs(int idx, int loopCnt)
{
	if (loopCnt == maxCorrectSize)
	{
		canFind = true;
		return;
	}

	for (int i = 0; i < connections[idx].size(); i++)
	{
		int nxt = connections[idx][i];

		if (visit[nxt] == true) continue;
		visit[nxt] = true;

		dfs(nxt, loopCnt + 1);

		visit[nxt] = false;
	}
}

// 0 -> 1
// 1 -> 0 -> 2



// 0 -> 1
// 1 -> 2
// 2 -> 3

// 3 -> 2 -> 1 -> 4

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int start, end;
		cin >> start >> end;

		connections[start].push_back(end);
		connections[end].push_back(start);
	}

	for (int i = 0; i < n; i++)
	{
		visit[i] = true;
		dfs(i, 1);
		visit[i] = false;

		if (canFind == true) break;
	}

	if (canFind == true) cout << 1;
	else cout << 0;

	return 0;
}