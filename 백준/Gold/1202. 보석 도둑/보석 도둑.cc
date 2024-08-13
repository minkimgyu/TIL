#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, k;

long long int result = 0;
priority_queue<long long int> pQ;

bool compareJu(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	int* bags = new int[k];
	pair<int, int>* ju = new pair<int, int>[n];

	for (int i = 0; i < n; i++)
	{
		cin >> ju[i].first >> ju[i].second;
	}

	for (int i = 0; i < k; i++)
	{
		cin >> bags[i];
	}

	sort(bags, bags + k);
	sort(ju, ju + n, compareJu);

	int juIndex = 0;

	for (int i = 0; i < k; i++)
	{
		while (juIndex < n && ju[juIndex].first <= bags[i])
		{
			pQ.push(ju[juIndex].second);
			juIndex++;
		}

		if (pQ.empty() == true) continue;

		result += pQ.top();
		pQ.pop();
	}
	
	cout << result;

	delete[] bags;
	delete[] ju;
	return 0;
}