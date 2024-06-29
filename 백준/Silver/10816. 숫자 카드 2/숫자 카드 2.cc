#include <iostream>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<int, int> map;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;

		if (map.find(tmp) != map.end()) // 찾은 경우
		{
			map[tmp] += 1;
		}
		else
		{
			map.insert({ tmp, 1 });
		}
	}

	int m;
	cin >> m;

	int* arr = new int[m];

	for (int i = 0; i < m; i++)
	{
		int tmp;
		cin >> tmp;
		arr[i] = map[tmp];
	}

	for (int i = 0; i < m; i++)
	{
		if(i == m - 1) cout << arr[i];
		else cout << arr[i] << " ";
	}

	delete[] arr;
	return 0;
}