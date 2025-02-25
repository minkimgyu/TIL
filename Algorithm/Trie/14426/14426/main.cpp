#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int ROOT = 1;
int unUsed = 2; // ������ ���� �ѹ���
const int maxSize = 500 * 10000 + 5;

const int alphaSize = 26;

// �θ� ��Ʈ �ѹ�, ���ĺ� �ε��� = ���� ��Ʈ �ѹ�
int nxt[maxSize][alphaSize]; // Ʈ��
bool chk[maxSize]; // �湮 Ƚ��

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

		cur = nxt[cur][cToi(s[i])]; // ���� �ѹ������� �����ؾ��ϹǷ� �̷��� �Ѵ�.
	}

	chk[cur] = true;
}

bool find(string s)
{
	int cur = ROOT;
	for (int i = 0; i < s.size(); i++)
	{
		if (nxt[cur][cToi(s[i])] == -1) return false; // �ش� �ѹ��� ���ٴ� �Ҹ�

		cur = nxt[cur][cToi(s[i])]; // ���� �ѹ������� �����ؾ��ϹǷ� �̷��� �Ѵ�.
	}

	// ���λ縦 ã�� ���̹Ƿ� ���� ������ visit�� �˻��� �ʿ䰡 ����.
	return true;
}

int n, m, result;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// ���� -1�� ä���ֱ�
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