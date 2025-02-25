#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int r, c;

const int maxSize = 20;
char arr[maxSize][maxSize];

bool visit[26]; // A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
int result = 0;

// 엣지 케이스: r, c 모두 1인 경우 체크

void dfs(pair<int, int> pos, int visitCount)
{
	if (pos.first < 0 || pos.second < 0 || pos.first >= r || pos.second >= c) return;

	char alpha = arr[pos.first][pos.second];
	int alphaIndex = alpha - 'A';

	if (visit[alphaIndex] == true) return;

	visitCount++;
	visit[alphaIndex] = true;

	result = max(visitCount, result);

	dfs({ pos.first + 1, pos.second + 0 }, visitCount);
	dfs({ pos.first + 0, pos.second + 1 }, visitCount);
	dfs({ pos.first - 1, pos.second + 0 }, visitCount);
	dfs({ pos.first + 0, pos.second - 1 }, visitCount);

	visitCount--;
	visit[alphaIndex] = false; // 백트래킹
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;
	cin.ignore();

	for (int i = 0; i < r; i++)
	{
		string line;
		getline(cin, line);
		for (int j = 0; j < c; j++)
		{
			arr[i][j] = line[j];
		}
	}

	if (r == 1 && c == 1)
	{
		cout << 1;
		return 0;
	}

	dfs({ 0, 0 }, 0);
	cout << result;

	return 0;
}