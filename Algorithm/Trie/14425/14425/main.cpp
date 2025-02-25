#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int ROOT = 1; // ��Ʈ ��ȣ
int unUsed = 2; // ������ ���� ���� �ռ� ��Ʈ ��ȣ
const int MX = 10000 * 500 + 5; // �ִ� ���� ������ ������ �� --> �ִ� 500�� ���ڿ��� 10000�� ������ ���
bool chk[MX]; // �ش� ������ ���ڿ��� ������ �����ϴ� �迭
int nxt[MX][26];
// �� �������� �ڽ� ������ ��ȣ --> ���Ĺ� ���� 26�ڷ� ����
// �̸� ���� �̵��ؾ� �ϴ� �ڽ� ������ O(1)�� �� �� ������ �������δ� �� �������� 26ĭ�� �Ҵ��ؾ� �ϹǷ�
// (int�� �޸�) * (���� ����) ��ŭ�� ������ �ʿ��ϹǷ� 4 * 26 ����Ʈ�� �ʿ��ϴ�

// ���� �޸� ������ �־ ��ȿ�����̴�.

// char ���� index�� �ٲ��ش�.
int cToI(char c)
{
	return c - 'a';
}

void insert(string s)
{
	int cur = ROOT; // ���� ���� �ִ� ����
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
	int cur = ROOT; // ���� ���� �ִ� ����
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
	int cur = ROOT; // ���� ���� �ִ� ����
	for (int index = 0; index < s.size(); index++)
	{
		if (nxt[cur][cToI(s[index])] == -1)
			return; // ������ ã�� ���� ��� --> ���� �ݵ�� �����Ѵٸ� ��� �ʿ����

		cur = nxt[cur][cToI(s[index])];
	}

	chk[cur] = false; // ������ ������ false�� �־ �ش� ���ڸ� �������ش�.
}

int n, m, result;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// nxt�� -1�� �ʱ�ȭ���Ѽ� �ڽ� ������ ���ٴ� ���� �˷��ش�.
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