#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b)
{
	return a.compare(b) > 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> names;
	map<string, bool> checkEnter;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string name, isEnter;
		cin >> name >> isEnter;

		if (isEnter == "enter")
		{
			checkEnter[name] = true;
		}
		else if (isEnter == "leave")
		{
			checkEnter[name] = false;
		}
	}

	for (auto it = checkEnter.begin(); it != checkEnter.end(); it++)
	{
		if (it->second == true)
		{
			names.push_back(it->first);
		}
	}

	sort(names.begin(), names.end(), compare);

	for (int i = 0; i < names.size(); i++)
	{
		cout << names[i];
		if (i != names.size() - 1) cout << '\n';
	}

	return 0;
}