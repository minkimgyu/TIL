#include <iostream>
#include <algorithm>
using namespace std;

const int maxSize = 8 + 5;

// ������, ����
pair<int, int> egg[maxSize];

int result = 0;
int n;
int successCount = 0;

void dfs(int currentEggIndex)
{
	// ���� �ε����� ������ �ε����� �Ѵ´ٸ� return;
	// ���� �ε����� ����� �̹� �μ��� ���
	if (currentEggIndex == n) 
	{
		result = max(result, successCount); // ���������� ���� ������Ʈ �ʿ�
		return;
	}

	if (egg[currentEggIndex].first <= 0 || successCount == n - 1) // �տ� �� ����� �����ų� ������ ���� �ٸ� ����� ������ ġ�� �ʰ� �Ѿ��.
	{
		dfs(currentEggIndex + 1); // ���� ���� ����� �����ִ� ��� ���� ����� �����Ѵ�.
		return; // ���� �� �ʿ�
	}

	for (int i = 0; i < n; i++)
	{
		if (i == currentEggIndex || egg[i].first <= 0) continue; // ���� ����� ����, ���� ����� �μ����ٸ� continue;

		egg[i].first -= egg[currentEggIndex].second; // ��� �ִ� ����� ���Է� ������ ���ҽ�Ű��
		egg[currentEggIndex].first -= egg[i].second; // ���� ����� ���Է� ��� �ִ� ��� ������ ���ҽ�Ű��

		if (egg[currentEggIndex].first <= 0) successCount++;
		if (egg[i].first <= 0) successCount++;

		dfs(currentEggIndex + 1);

		if (egg[currentEggIndex].first <= 0) successCount--;
		if (egg[i].first <= 0) successCount--;

		egg[i].first += egg[currentEggIndex].second; // ��Ʈ��ŷ���� ������ �ٽ� ���� �ʿ�
		egg[currentEggIndex].first += egg[i].second;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int s, w;
		cin >> s >> w;

		egg[i].first = s;
		egg[i].second = w;
	}
	
	dfs(0);

	cout << result;
	return 0;
}