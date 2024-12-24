#include <iostream>
#include <sstream>
#include <vector>
#include <set>
using namespace std;

struct Compare
{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) const
	{
		if (a.second == b.second) return a.first < b.first;
		return a.second < b.second;
	}
};

int numbers[100000 + 5];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// first가 번호, second가 난이도
	multiset<pair<int, int>, Compare> multiSet;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num, difficult;
		cin >> num >> difficult;

		multiSet.insert({ num, difficult });
		numbers[num] = difficult;
	}

	int m;
	cin >> m;
	cin.ignore();

	for (int i = 0; i < m; i++)
	{
		vector<string> command;
		string input, tocken;
		getline(cin, input);

		stringstream ss(input);

		while (getline(ss, tocken, ' '))
		{
			command.push_back(tocken);
		}

		if (command[0] == "add")
		{
			multiSet.insert({ stoi(command[1]), stoi(command[2]) });
			numbers[stoi(command[1])] = stoi(command[2]);
		}
		else if (command[0] == "recommend")
		{
			if (stoi(command[1]) == 1)
			{
				cout << (*--multiSet.end()).first;
			}
			else if (stoi(command[1]) == -1)
			{
				cout << (*multiSet.begin()).first;
			}

			if (i != m - 1)  cout << '\n';
		}
		else if (command[0] == "solved")
		{
			multiSet.erase(multiSet.find({ stoi(command[1]), numbers[stoi(command[1])] }));
		}
	}
	return 0;
}