#include <iostream>
using namespace std;

int n, k;
bool arr[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	int count = 0;
	while (1)
	{
		for (int j = 2; j <= n; j++)
		{
			if (arr[j] == false)
			{
				for (int z = 1; z < 1000; z++)
				{
					if (arr[j * z] == true) continue;
					if (j * z > n) break;
					arr[j * z] = true;
					count++;

					if (count == k)
					{
						cout << j * z;
						return 0;
					}
				}
			}
		}
	}

	return 0;
}