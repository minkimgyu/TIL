#include <iostream>
using namespace std;

int n, r, c;

int visitCount;


// (0, 0) (0, 1), (0, 2), (0, 3)
// (1, 0) (1, 1), (1, 2), (1, 3)
// (2, 0) (2, 1), (2, 2), (2, 3)
// (3, 0) (3, 1), (3, 2), (3, 3)

// �ð� �ʰ� �Ф�
// ���� Ž������ ���ð� �簢���� 4���� ���� ��ġ�� ���� �� ��и��� ������ �����鼭 ����غ�����

void dfs(pair<int, int> leftTop, pair<int, int> rightBottom, int size, int multi)
{
	visitCount += size * size * multi;
	// �� ĭ���� ������ ���
	if (leftTop.first == rightBottom.first && leftTop.second == rightBottom.second)
	{
		if (leftTop.first == r && leftTop.second == c)
		{
			cout << visitCount; // �湮 ī��Ʈ�� 0������ ������
		}
		return;
	}

	int newSize = size / 2;
	int rowMid = (leftTop.first + rightBottom.first) / 2;
	int columnMid = (leftTop.second + rightBottom.second) / 2;

	if (leftTop.first <= r && r <= rowMid && leftTop.second <= c && c <= columnMid)
	{
		dfs({ leftTop.first, leftTop.second }, { rowMid, columnMid }, newSize, 0); // 1��и�
	}

	if (leftTop.first <= r && r <= rowMid && columnMid + 1 <= c && c <= rightBottom.second)
	{
		dfs({ leftTop.first, columnMid + 1 }, { rowMid, rightBottom.second }, newSize, 1); // 2��и� --> 1��и��� ��ȸ��ŭ �����ش�.
	}

	if (rowMid + 1 <= r && r <= rightBottom.first && leftTop.second <= c && c <= columnMid)
	{
		dfs({ rowMid + 1, leftTop.second }, { rightBottom.first,  columnMid }, newSize, 2); // 3��и� --> 1, 2��и��� ��ȸ��ŭ �����ش�.
	}

	if (rowMid + 1 <= r && r <= rightBottom.first && columnMid + 1 <= c && c <= rightBottom.second)
	{
		dfs({ rowMid + 1, columnMid + 1 }, { rightBottom.first, rightBottom.second }, newSize, 3); // 4��и� --> 1, 2, 3��и��� ��ȸ��ŭ �����ش�.
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> r >> c;

	long long int size = 1;
	for (int i = 0; i < n; i++)
	{
		size *= 2;
	}

	dfs({ 0, 0 }, { size - 1, size - 1 }, size, 0);

	return 0;
}