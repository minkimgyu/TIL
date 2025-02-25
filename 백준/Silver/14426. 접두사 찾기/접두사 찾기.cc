#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int ROOT = 1;
int unUsed = 2; // 사용되지 않은 넘버링
const int maxSize = 500 * 10000 + 5;

const int alphaSize = 26;

// 부모 루트 넘버, 알파벳 인덱스 = 본인 루트 넘버
int nxt[maxSize][alphaSize]; // 트리
bool chk[maxSize]; // 방문 횟수

int cToi(char c)
{
	return c - 'a';
}

void insert(string s)
{
	int cur = ROOT;
	for (int i = 0; i < s.size(); i++)
	{
		if (nxt[cur][cToi(s[i])] == -1)
			nxt[cur][cToi(s[i])] = unUsed++;

		cur = nxt[cur][cToi(s[i])]; // 다음 넘버링부터 시작해야하므로 이렇게 한다.
	}

	chk[cur] = true;
}

bool find(string s)
{
	int cur = ROOT;
	for (int i = 0; i < s.size(); i++)
	{
		if (nxt[cur][cToi(s[i])] == -1) return false; // 해당 넘버가 없다는 소리

		cur = nxt[cur][cToi(s[i])]; // 다음 넘버링부터 시작해야하므로 이렇게 한다.
	}

	// 접두사를 찾는 것이므로 따로 마지막 visit을 검사할 필요가 없다.
	return true;
}

int n, m, result;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 전부 -1로 채워주기
	for (int i = 0; i < maxSize; i++)
	{
		for (int j = 0; j < alphaSize; j++)
		{
			nxt[i][j] = -1;
		}
	}

	cin >> n >> m;
	cin.ignore();

	for (int k = 0; k < n; k++)
	{
		string s;
		getline(cin, s);

		insert(s);
	}

	for (int z = 0; z < m; z++)
	{
		string s;
		getline(cin, s);

		bool canFind = find(s);
		if (canFind == true) result++;
	}

	cout << result;
	return 0;
}