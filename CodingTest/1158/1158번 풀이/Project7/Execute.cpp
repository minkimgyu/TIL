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
	int numberOfPeoples;
	int count;

	cin >> numberOfPeoples >> count;

	for (int i = 1; i <= numberOfPeoples; i++)
	{
		li.emplace_back(i);
	}

	list<int>::iterator iter = li.begin();

	while (li.size() != 0)
	{
		int tmp = 1;
		while (tmp < count)
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

		if (iter == --li.end())
		{
			vec.emplace_back(*iter);
			li.erase(iter);
			iter = li.begin();
		}
		else
		{
			vec.emplace_back(*iter);
			iter = li.erase(iter);
		}
	}

	cout << "<";

	for (int i = 0; i < vec.size(); i++)
	{
		if(i == vec.size() - 1)
			cout << vec[i];
		else
			cout << vec[i] << ", ";
	}

	cout << ">";

	return 0;
}