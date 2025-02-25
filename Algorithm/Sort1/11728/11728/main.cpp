#include <iostream>
using namespace std;

const int maxSize = 1000000 + 5;

int arrA[maxSize];
int arrB[maxSize];

int result[maxSize * 2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> arrA[i];
	}

	for (int i = 0; i < m; i++)
	{
		cin >> arrB[i];
	}

	int aIndex = 0;
	int bIndex = 0;
	int index = 0;

	while (1)
	{
		if (aIndex == n && bIndex == m)
		{
			break;
		}
		else if (aIndex == n)
		{
			result[index] = arrB[bIndex];
			bIndex++;
		}
		else if(bIndex == m)
		{
			result[index] = arrA[aIndex];
			aIndex++;
		}
		else
		{
			if (arrA[aIndex] > arrB[bIndex])
			{
				result[index] = arrB[bIndex];
				bIndex++;
			}
			else
			{
				result[index] = arrA[aIndex];
				aIndex++;
			}
		}

		index++;
	}

	for (int i = 0; i < index; i++)
	{
		cout << result[i];
		if (i != index - 1) cout << " ";
	}

	return 0;
}