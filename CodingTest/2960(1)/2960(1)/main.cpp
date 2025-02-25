#include <iostream>
using namespace std;

const int maxN = 1000;
int n, k;
int arr[maxN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int removeCount = 0;
	cin >> n >> k;

	for (int i = 2; i <= n; i++)
	{
		arr[i - 2] = i;
	}

	while(1)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[j] > -1)
			{
				int item = arr[j];

				for (int z = 1; z <= n; z++)
				{
					int num = item * z;
					int index = num - 2;
					if (num > n) break;

					if (arr[index] == -1) continue; // 만약 이전에 지워졌다면 건너뛰기

					arr[index] = -1;
					removeCount++;
					if (removeCount == k)
					{
						cout << num;
						return 0;
					}
				}
			}
		}
	}

	return 0;
}