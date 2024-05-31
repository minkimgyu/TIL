#include <iostream>
#include <list>
#include <vector>
using namespace std;

const int maxSize = 105;
int map[maxSize][maxSize]{ 0 };
long long int visit[maxSize][maxSize]{ 0 };

// visit[i + map[i][j]][j] += visit[i][j]; <-- 이 부분이 중요함
// 중첩될 수 있으므로 더하게끔 해야한다.

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

	visit[0][0] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == n - 1 && j == n - 1) continue;
			if (visit[i][j] == 0) continue;

			if (i + map[i][j] < n)
			{
				visit[i + map[i][j]][j] += visit[i][j];
			}

			if (j + map[i][j] < n)
			{
				visit[i][j + map[i][j]] += visit[i][j];
			}
		}
	}

	cout << visit[n - 1][n - 1];

	return 0;
}