#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int ROOT = 1; // 루트 번호
int unUsed = 2; // 사용되지 않은 가장 앞선 루트 번호
const int MX = 10000 * 500 + 5; // 최대 등장 가능한 글자의 수 --> 최대 500인 문자열이 10000개 들어오는 경우
bool chk[MX]; // 해당 정점이 문자열의 끝인지 저장하는 배열
int nxt[MX][26];
// 각 정점에서 자식 정점의 번호 --> 알파뱃 기준 26자로 정함
// 이를 통해 이동해야 하는 자식 정점을 O(1)에 알 수 있지만 단점으로는 각 정점마다 26칸을 할당해야 하므로
// (int형 메모리) * (문자 개수) 만큼의 공간이 필요하므로 4 * 26 바이트가 필요하다

// 따라서 메모리 공간에 있어서 비효율적이다.

// char 형을 index로 바꿔준다.
int cToI(char c)
{
	return c - 'a';
}

void insert(string s)
{
	int cur = ROOT; // 현재 보고 있는 정점
	for (int index = 0; index < s.size(); index++)
	{
		if (nxt[cur][cToI(s[index])] == -1)
			nxt[cur][cToI(s[index])] = unUsed++;

		cur = nxt[cur][cToI(s[index])];
	}

	chk[cur] = true;
}

bool find(string s)
{
	int cur = ROOT; // 현재 보고 있는 정점
	for (int index = 0; index < s.size(); index++)
	{
		if (nxt[cur][cToI(s[index])] == -1)
			return false;

		cur = nxt[cur][cToI(s[index])];
	}

	return chk[cur];
}

void erase(string s)
{
	int cur = ROOT; // 현재 보고 있는 정점
	for (int index = 0; index < s.size(); index++)
	{
		if (nxt[cur][cToI(s[index])] == -1)
			return; // 정점을 찾지 못한 경우 --> 만약 반드시 존재한다면 사실 필요없음

		cur = nxt[cur][cToI(s[index])];
	}

	chk[cur] = false; // 마지막 정점에 false를 넣어서 해당 글자를 제거해준다.
}

int n, m, result;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// nxt는 -1로 초기화시켜서 자식 정점이 없다는 것을 알려준다.
	for (int i = 0; i < MX; i++)
		fill(nxt[i], nxt[i] + 26, -1);

	cin >> n >> m;
	cin.ignore();

	vector<string> strs;

	for (int i = 0; i < n; i++)
	{
		string s;
		getline(cin, s);

		insert(s);
	}

	for (int j = 0; j < m; j++)
	{
		string s;
		getline(cin, s);

		bool canFind = find(s);
		if (canFind == true)
		{
			result++;
		}
	}

	cout << result;
	return 0;
}