#include <iostream>
#include <string>
using namespace std;

string input;
bool switchArr[100];

void dfs(int start, int end, string part)
{
	if (start > end) return;

	char startAlpha = part[start];
	char minIndex = start;

	for (int i = start; i <= end; i++)
	{
		if (startAlpha > part[i])
		{
			startAlpha = part[i];
			minIndex = i;
		}
	}

	switchArr[minIndex] = true;

	int inputSize = input.size();
	for (int i = 0; i < inputSize; i++)
	{
		if (switchArr[i] == true)
		{
			cout << input[i];
		}
	}

	cout << '\n';

	// ���������� ���� ���� ���Ҹ� �̰�
	// �������� �� ���ڴ� �� ���� �ڿ� �ִ� ���ڷ� �ؾ���

	// ���� ���� ���Һ��� �̱� ������ �׷� ����

	dfs(minIndex + 1, end, part); // --> �׷��� �ں��� ��͸� �����ش�.
	dfs(start, minIndex - 1, part);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getline(cin, input);
	dfs(0, input.size() - 1, input);
	return 0;
}