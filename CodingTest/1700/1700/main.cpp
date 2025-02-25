#include <iostream>
#include <queue>
#include <list>
#include <functional>
#include <algorithm>
using namespace std;

int n, k;

int items[101];
int frequency[101];
list<int> inputOrder[101];

bool plugIn[101];
int plugInSize = 0;

int result = 0;

struct Item
{
public:
	int name;
	int frequency;
	int nextInputIndex;

	bool operator<(const Item& a)
	{
		int myFrontIndex;
		if (inputOrder[name].empty() == false)
		{
			myFrontIndex = inputOrder[name].front();
		}
		else
		{
			myFrontIndex = 1000000000;
		}

		int aFrontIndex;
		if (inputOrder[a.name].empty() == false)
		{
			aFrontIndex = inputOrder[a.name].front();
		}
		else
		{
			aFrontIndex = 1000000000;
		}

		return myFrontIndex > aFrontIndex;

		//if (frequency == a.frequency)
		//{
		//	
		//}
		//else
		//{
		//	return frequency < a.frequency;
		//}
	}
};

list<Item> itemQueue;

void PlugInItem(int i)
{
	plugIn[items[i]] = true;

	int nextInputIndex;
	if (inputOrder[items[i]].empty() == false)
	{
		nextInputIndex = inputOrder[items[i]].front();
		inputOrder[items[i]].pop_front();
	}
	else
	{
		nextInputIndex = 1000000000;
	}
	
	itemQueue.push_back({ items[i], frequency[items[i]], nextInputIndex });
}

void PlugOutItem()
{
	itemQueue.sort();

	Item item = itemQueue.front();
	itemQueue.pop_front(); // pQ에서 frequency, nextInputIndex 기준으로 아이템을 빼준다.
	plugIn[item.name] = false; // 플러그를 뺄 때 false를 넣어줘야함
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int item;
		cin >> item;

		items[i] = item;
		frequency[item] += 1;
		inputOrder[item].push_back(i);
	}

	for (int i = 0; i < k; i++)
	{
		if (plugIn[items[i]] == true)
		{
			if (inputOrder[items[i]].empty() == false)
			{
				inputOrder[items[i]].pop_front(); // inputOrder를 다시 갱신해줘야한다.
			}
			continue; // 해당 제품이 이미 플러그가 꽂혀있다면 진행 X
		}

		if (plugInSize == n) // 이미 꽂혀있는 개수가 최대 크기인 경우
		{
			PlugOutItem();
			result++;
			PlugInItem(i);
		}
		else
		{
			plugInSize++;
			PlugInItem(i);
		}
	}

	cout << result;

	return 0;
}