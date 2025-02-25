#include <iostream>
using namespace std;

int result = 0;
int n;

void dfs(int start, int loopCount)
{
	if (start == 10 || start == -1) return;
	if (loopCount == n)
	{
		result++;
		return;
	}

	dfs(start + 1, loopCount + 1);
	dfs(start - 1, loopCount + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= 9; i++)
	{
		dfs(i, 1);
	}

	cout << result;
	return 0;
}