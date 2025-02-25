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
	itemQueue.pop_front(); // pQ���� frequency, nextInputIndex �������� �������� ���ش�.
	plugIn[item.name] = false; // �÷��׸� �� �� false�� �־������
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
				inputOrder[items[i]].pop_front(); // inputOrder�� �ٽ� ����������Ѵ�.
			}
			continue; // �ش� ��ǰ�� �̹� �÷��װ� �����ִٸ� ���� X
		}

		if (plugInSize == n) // �̹� �����ִ� ������ �ִ� ũ���� ���
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