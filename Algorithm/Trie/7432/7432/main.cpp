#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int ROOT = 1;
int unUsed = 2;

const int maxLocationCount = 501; // 경로 최대 개수
const int maxSize = maxLocationCount * 80 + 5; // 경로 개수 * 경로 글자 수 + offset

int nxt[maxSize][maxLocationCount];
bool visit[maxSize];

string locations[maxSize];

void insert(vector<string> vec)
{
	int cur = ROOT;
	for (int i = 0; i < vec.size(); i++)
	{
		if (locationMap[vec[i]] == 0) // 지정되지 않은 경우
		{
			locationMap[vec[i]] = locationMap.size() + 1; // 0개라면 +1 해서 1을 넣어줌
		}

		if (nxt[cur][locationMap[vec[i]]] == -1) // 지정되지 않은 경우
			nxt[cur][locationMap[vec[i]]] = unUsed++;// 새로 값을 넣는다.

		cur = nxt[cur][locationMap[vec[i]]];
	}
}

void print()
{
	int locationMapSize = locationMap.size();

	for (int i = 0; i < unUsed; i++)
	{
		for (auto j = locationMap.begin(); j != locationMap.end(); j++)
		{
			if(nxt[i][j->second] != -1) // 지정이 되어있는 경우
			{
				cout << j->first << " ";
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		stringstream ss(s);
		string token;

		vector<string> vec;

		while (getline(ss, token, '\\'))
		{
			vec.push_back(token);
		}

		insert(vec);
	}

	print();
	return 0;
}