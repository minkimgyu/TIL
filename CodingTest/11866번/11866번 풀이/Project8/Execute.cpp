#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	list<int> li;
	vector<int> vec;
	int count;
	int interval;

	cin >> count >> interval;

	for (int i = 1; i <= count; i++)
	{
		li.emplace_back(i);
	}

	list<int>::iterator iter = li.begin();

	while (li.size() != 0)
	{
		int tmp = 1;
		while (tmp < interval)
		{
			if (iter == --li.end())
			{
				iter = li.begin();
			}
			else
			{
				iter++;
			}

			tmp++;
		}

		vec.emplace_back(*iter);

		if (iter == --li.end())
		{
			li.erase(iter);
			iter = li.begin();
		}
		else
		{
			iter = li.erase(iter);
		}
	}


	cout << "<";
	for (int i = 0; i < vec.size(); i++)
	{
		if (i != vec.size() - 1)
			cout << vec[i] << ", ";
		else
			cout << vec[i];
	}
	cout << ">";

	return 0;
}