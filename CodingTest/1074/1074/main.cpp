#include <iostream>
using namespace std;

int n, r, c;

int visitCount;


// (0, 0) (0, 1), (0, 2), (0, 3)
// (1, 0) (1, 1), (1, 2), (1, 3)
// (2, 0) (2, 1), (2, 2), (2, 3)
// (3, 0) (3, 1), (3, 2), (3, 3)

// 시간 초과 ㅠㅠ
// 전부 탐색하지 마시고 사각형을 4개로 나눠 위치에 따라서 한 사분면을 선택해 나가면서 재귀해보세요

void dfs(pair<int, int> leftTop, pair<int, int> rightBottom, int size, int multi)
{
	visitCount += size * size * multi;
	// 한 칸으로 떨어질 경우
	if (leftTop.first == rightBottom.first && leftTop.second == rightBottom.second)
	{
		if (leftTop.first == r && leftTop.second == c)
		{
			cout << visitCount; // 방문 카운트가 0번부터 시작함
		}
		return;
	}

	int newSize = size / 2;
	int rowMid = (leftTop.first + rightBottom.first) / 2;
	int columnMid = (leftTop.second + rightBottom.second) / 2;

	if (leftTop.first <= r && r <= rowMid && leftTop.second <= c && c <= columnMid)
	{
		dfs({ leftTop.first, leftTop.second }, { rowMid, columnMid }, newSize, 0); // 1사분면
	}

	if (leftTop.first <= r && r <= rowMid && columnMid + 1 <= c && c <= rightBottom.second)
	{
		dfs({ leftTop.first, columnMid + 1 }, { rowMid, rightBottom.second }, newSize, 1); // 2사분면 --> 1사분면의 순회만큼 더해준다.
	}

	if (rowMid + 1 <= r && r <= rightBottom.first && leftTop.second <= c && c <= columnMid)
	{
		dfs({ rowMid + 1, leftTop.second }, { rightBottom.first,  columnMid }, newSize, 2); // 3사분면 --> 1, 2사분면의 순회만큼 더해준다.
	}

	if (rowMid + 1 <= r && r <= rightBottom.first && columnMid + 1 <= c && c <= rightBottom.second)
	{
		dfs({ rowMid + 1, columnMid + 1 }, { rightBottom.first, rightBottom.second }, newSize, 3); // 4사분면 --> 1, 2, 3사분면의 순회만큼 더해준다.
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