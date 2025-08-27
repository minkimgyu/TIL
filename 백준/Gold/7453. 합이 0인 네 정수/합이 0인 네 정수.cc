#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxSize = 4000 + 5;
int arr1[maxSize], arr2[maxSize], arr3[maxSize], arr4[maxSize];

vector<int> items1;
vector<int> items2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr1[i] >> arr2[i] >> arr3[i] >> arr4[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			items1.push_back(arr1[i] + arr2[j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			items2.push_back(arr3[i] + arr4[j]);
		}
	}

	sort(items2.begin(), items2.end());

	long long int result = 0;

	int item1Size = items1.size();
	for (int i = 0; i < item1Size; i++)
	{
		int item = -items1[i];
		long long int count = upper_bound(items2.begin(), items2.end(), item) - lower_bound(items2.begin(), items2.end(), item);
		result += count;
	}

	cout << result;
	return 0;
}