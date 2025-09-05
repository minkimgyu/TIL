#include <iostream>
using namespace std;

const int maxSize = 250000 + 5;
int arr[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x;
	cin >> n >> x;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int right = 0;

	int result = 0;
	int sum = 0;
	int sameCount = 0;

	for (int left = 0; left < n; left++)
	{
		while (right < n && right - left < x)
		{
			sum += arr[right];

			if (result == sum)
			{
				sameCount++;
			}
			else if (result < sum)
			{
				result = sum;
				sameCount = 1;
			}

			right++;
		}

		sum -= arr[left];
	}

	if (result == 0) cout << "SAD";
	else
	{
		cout << result << '\n';
		cout << sameCount;
	}
	
	return 0;
}