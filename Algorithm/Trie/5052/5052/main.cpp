#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int ROOT = 1;
int unUsed = 2;

const int maxSize = 10 * 10000 + 5;
const int numSize = 10;

// �θ� ��Ʈ �ѹ�, ���� �ε��� = ���� ��Ʈ �ѹ�
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

	unUsed = ROOT + 1; // tc�� ��������� �̰͵� �ʱ�ȭ ������Ѵ�.
}

int cToi(char s) { return s - '0'; }

void insert(string s)
{
	int cur = ROOT;
	for (int i = 0; i < s.size(); i++)
	{
		if (nxt[cur][cToi(s[i])] == -1)
			nxt[cur][cToi(s[i])] = unUsed++;
		
		// �θ� ��Ʈ �ѹ��� �������ش�.
		cur = nxt[cur][cToi(s[i])];
	}
}

bool find(string s)
{
	int cur = ROOT;
	for (int i = 0; i < s.size(); i++)
	{
		if (nxt[cur][cToi(s[i])] == -1) return false; // �� ã�� ���

		// �θ� ��Ʈ �ѹ��� �������ش�.
		cur = nxt[cur][cToi(s[i])];
	}

	return true;

	//return false; // chk[cur];
	// ���������� Ž���� ��� ���λ簡 ���� ������ �Ǵ�
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