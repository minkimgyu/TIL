#include <iostream>
#include <string>
using namespace std;

long long int states[10 + 5];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string name, playable;
		cin >> name >> playable;

		for (int j = 0; j < m; j++)
		{
			states[i] = (states[i] << 1) | (playable[j] == 'Y');
		}
	}

	long long int storedState = 0;
	int result = -1;

	for (int i = 0; i < (1 << n); i++)
	{
		long long int state = 0;
		int pickCount = 0;

		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				state |= states[j];
				pickCount++;
			}
		}

		if (storedState < state) // 플레이 할 수 있는 곡 수가 더 많다면
		{
			storedState = state;
			result = pickCount;
		}
		else if(storedState == state && pickCount < result)
		{
			result = pickCount;
		}
	}

	cout << result;

	return 0;
}