#include <iostream>
#include <vector>
using namespace std;

void dfs(int index, int* arr, bool* list)
{
	if (list[index] == true) return;

	list[index] = true;
	dfs(arr[index] - 1, arr, list);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> cycleArr;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int cnt;
		cin >> cnt;
		int* arr = new int[cnt];
		bool* list = new bool[cnt]{ false };
		for (int j = 0; j < cnt; j++)
		{
			cin >> arr[j];
		}

		int cycleCnt = 0;

		for (int z = 0; z < cnt; z++)
		{
			if (list[z] == true) continue;

			dfs(arr[z] - 1, arr, list);
			cycleCnt++;
		}

		cycleArr.push_back(cycleCnt);
	}

	int size = cycleArr.size();
	for (int i = 0; i < size; i++)
	{
		if(i == size - 1) cout << cycleArr[i];
		else cout << cycleArr[i] << '\n';
	}

	return 0;
}