#include <iostream>
#include <algorithm>
using namespace std;

class Meat
{
public:
	int _weight = 0;
	int _cost = 0;
};

bool compare(Meat a, Meat b)
{
	if (a._cost == b._cost) return a._weight > b._weight;

	return a._cost < b._cost;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	Meat* meats = new Meat[n];
	for (int i = 0; i < n; i++)
	{
		int weight, cost;
		cin >> weight >> cost;
		
		meats[i]._weight = weight;
		meats[i]._cost = cost;
	}

	sort(meats, meats + n, compare);

	bool canEvaluate = false;
	int beforeCost = 0;

	for (int i = 0; i < n; i++)
	{
		int currentCost = meats[i]._cost;
		int currentWeight = meats[i]._weight;
		int sum = 0;

		if (beforeCost != currentCost)
		{
			beforeCost = currentCost;
		
			int totalCost = 0;
			for (int j = 0; j <= i; j++)
			{
				sum += meats[j]._weight; // 다 더해준다.
				totalCost += meats[j]._cost;
			}

			int costExcludeCurrent = totalCost - currentCost;
			int weightExcludeCurrent = sum - currentWeight;

			// 같은 무게를 다 더한 경우가 목표 Weight를 넘고 cost가 더 낮을 때 이걸 출력해준다.
			if (weightExcludeCurrent >= m && costExcludeCurrent < currentCost)
			{
				cout << costExcludeCurrent;
				return 0;
			}

			if (sum >= m)
			{
				cout << currentCost;
				return 0;
			}
		}
		else
		{
			for (int j = 0; j <= i; j++)
			{
				if (meats[j]._cost < currentCost) sum += meats[j]._weight; // 다 더해준다.
			}

			if (sum + currentWeight >= m)
			{
				cout << currentCost;
				return 0;
			}
		}
	}

	cout << -1;
	return 0;
}