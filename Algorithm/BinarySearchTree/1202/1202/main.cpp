//#include <iostream>
//#include <algorithm>
//#include <queue>
//using namespace std;
//
//bool compare(pair<int, int> a, pair<int, int> b)
//{
//	return a.first < b.first; // ���� ������ ����
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int n, k;
//	cin >> n >> k;
//
//	long long int maxValue = 0;
//
//	priority_queue<int> maxQ;
//	vector<pair<int, int>> items;
//
//	for (int i = 0; i < n; i++)
//	{
//		int m, v;
//		cin >> m >> v;
//		items.push_back({m, v});
//	}
//
//	sort(items.begin(), items.end(), compare);
//
//	vector<int> bags;
//	for (int i = 0; i < k; i++)
//	{
//		int kg;
//		cin >> kg;
//		bags.push_back(kg);
//	}
//
//	sort(bags.begin(), bags.end());
//
//	int itemIndex = 0;
//
//	for (int i = 0; i < bags.size(); i++)
//	{
//		while (itemIndex < items.size() && items[itemIndex].first <= bags[i])
//		{
//			maxQ.push(items[itemIndex].second);
//			itemIndex++;
//		}
//
//		if (maxQ.empty() == true) continue; // ť�� ��� �����ϴ� ���� �ƴ϶� ���� ������ �����Ѵ�.
//
//		int front = maxQ.top(); maxQ.pop();
//		maxValue += front;
//	}
//
//	cout << maxValue;
//	return 0;
//}

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first; // ���� ������ ����
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	long long int maxValue = 0;

	multiset<int> multiSet;
	vector<pair<int, int>> items;

	for (int i = 0; i < n; i++)
	{
		int m, v;
		cin >> m >> v;
		items.push_back({ m, v });
	}

	sort(items.begin(), items.end(), compare);

	vector<int> bags;
	for (int i = 0; i < k; i++)
	{
		int kg;
		cin >> kg;
		bags.push_back(kg);
	}

	sort(bags.begin(), bags.end());

	int itemIndex = 0;

	for (int i = 0; i < bags.size(); i++)
	{
		while (itemIndex < items.size() && items[itemIndex].first <= bags[i])
		{
			multiSet.insert(items[itemIndex].second);
			itemIndex++;
		}

		if (multiSet.empty() == true) continue;

		// �׻� multiSet.end()�� �ϳ� �� iterator�� ���������� �������

		int endItem = *--multiSet.end(); 
		multiSet.erase(--multiSet.end());

		maxValue += endItem;
	}

	cout << maxValue;
	return 0;
}