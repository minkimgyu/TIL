#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

const int maxSize = 1000 + 5;
string people[maxSize];
unordered_map<string, vector<string>> connections;
unordered_map<string, bool> visit;
unordered_map<string, int> indegree;

vector<string> firstPeople;
unordered_map<string, vector<string>> results;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> people[i];
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;

		connections[s2].push_back(s1);
		indegree[s1]++;
	}

	queue<string> q;
	for (int i = 0; i < n; i++)
	{
		if (indegree[people[i]] == 0 && visit[people[i]] == false)
		{
			q.push(people[i]);
			visit[people[i]] = true;
			firstPeople.push_back(people[i]);
		}
	}

	while (q.empty() == false)
	{
		string name = q.front(); q.pop();

		for (int i = 0; i < connections[name].size(); i++)
		{
			string to = connections[name][i];
			indegree[to]--;

			if (indegree[to] == 0) // 직계 자손의 경우
			{
				results[name].push_back(to);
			}
		}

		for (int i = 0; i < n; i++)
		{
			if (indegree[people[i]] == 0 && visit[people[i]] == false)
			{
				q.push(people[i]);
				visit[people[i]] = true;
			}
		}
	}

	int firstPeopleSize = firstPeople.size();
	sort(firstPeople.begin(), firstPeople.end());

	cout << firstPeopleSize << '\n';
	for (int i = 0; i < firstPeopleSize; i++)
	{
		cout << firstPeople[i] << " ";
	}

	cout << "\n";

	sort(people, people + n);
	
	for (int i = 0; i < n; i++)
	{
		cout << people[i] << " ";

		int directSize = results[people[i]].size();
		cout << directSize << " ";

		sort(results[people[i]].begin(), results[people[i]].end());

		for (int j = 0; j < directSize; j++)
		{
			cout << results[people[i]][j] << " ";
		}

		cout << '\n';
	}

	return 0;
}