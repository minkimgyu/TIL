#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// �̰Ŵ� ���� ���ڰ� �ʿ���� --> ������ 1�� �� �˻��ؼ� Ʋ��
	const int alphaSize = 26;
	char alpha[alphaSize] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

	const int size = 101; 
	// �ٵ� ����� ���๮�ڰ� �ʿ��� --> �ֳ��ϸ� if (s[j + 1] == '\0') break; 
	// �̷� ������ ���ϴ� �ڵ尡 �����ϴµ� ���� ���� ���� 100���� ���ļ� ������ ���๮�ڰ� ������ �� ��

	char s[size];
	cin >> s;

	for (int i = 0; i < alphaSize; i++)
	{
		int tmp = -1;
		for (int j = 0; j < size; j++)
		{
			if (alpha[i] == s[j])
			{
				tmp = j;
				break;
			}

			if (s[j + 1] == '\0') break;
		}

		if (i == alphaSize - 1) cout << tmp; // ������ �ܾ��� ���
		else cout << tmp << " ";
	}

	return 0;
}