#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int ROOT = 1;
int unUsed = 2;

const int maxSize = 10 * 10000 + 5;
const int numSize = 10;

// 부모 루트 넘버, 숫자 인덱스 = 본인 루트 넘버
int nxt[maxSize][numSize];

void resetNxt()
{
	for (int i = 0; i < maxSize; i++)
	{
		for (int j = 0; j < numSize; j++)
		{
			nxt[i][j] = -1;
		}
	}

	/*for (int i = 0; i < maxSize; i++)
	{
		chk[i] = false;
	}*/

	unUsed = ROOT + 1; // tc가 여러개라면 이것도 초기화 해줘야한다.
}

int cToi(char s) { return s - '0'; }

void insert(string s)
{
	int cur = ROOT;
	for (int i = 0; i < s.size(); i++)
	{
		if (nxt[cur][cToi(s[i])] == -1)
			nxt[cur][cToi(s[i])] = unUsed++;
		
		// 부모 루트 넘버를 갱신해준다.
		cur = nxt[cur][cToi(s[i])];
	}
}

bool find(string s)
{
	int cur = ROOT;
	for (int i = 0; i < s.size(); i++)
	{
		if (nxt[cur][cToi(s[i])] == -1) return false; // 못 찾는 경우

		// 부모 루트 넘버를 갱신해준다.
		cur = nxt[cur][cToi(s[i])];
	}

	return true;

	//return false; // chk[cur];
	// 마지막까지 탐색한 경우 접두사가 없는 것으로 판단
}

bool compare(string a, string b)
{
	return a.size() > b.size();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		resetNxt();

		int n;
		cin >> n;

		bool consistency = true;
		vector<string> vec;

		for (int j = 0; j < n; j++)
		{
			string s;
			cin >> s;

			vec.push_back(s);
		}

		sort(vec.begin(), vec.end(), compare);

		for (int j = 0; j < n; j++)
		{
			bool canFind = find(vec[j]);
			if (canFind == true)
			{
				consistency = false;
				break;
			}
			else
			{
				insert(vec[j]);
			}
		}

		if (consistency == true) cout << "YES";
		else cout << "NO";

		if(i != t - 1) cout << '\n';
	}

	return 0;
}