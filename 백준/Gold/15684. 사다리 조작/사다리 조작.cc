#include <iostream>
using namespace std;

const int maxRowSize = 30 + 5;
const int maxColSize = 10 + 5;

int n, m, h;

int mapArr[maxRowSize][maxColSize];

// 중복 순열 뽑기 -> 양옆으로 같은 숫자만 안 나오면 됨
// 최대 300개 까지 채울 수 있음
// 해당 인덱스를 채우고 dfs 돌리기 -> 가능하다면
// i번쨰에서 출발해서 i번째로 도착하는 경우 찾아야함

int pickArr[maxRowSize * maxColSize];
pair<int, int> passArr[maxRowSize * maxColSize];


bool canPass(pair<int, int> pos, int startIndex)
{
	if (pos.first == h + 1)
	{
		if (pos.second == startIndex) return true; // 출발한 곳으로 돌아온 경우
		else return false; // 다른 곳에 도착한 경우
	}

	if (pos.second > 1 && mapArr[pos.first][pos.second - 1] == 1) // 왼쪽 이동
	{
		return canPass({ pos.first + 1, pos.second - 1 }, startIndex);
	}
	else if (pos.second < n && mapArr[pos.first][pos.second] == 1) // 오른쪽 이동
	{
		return canPass({ pos.first + 1, pos.second + 1 }, startIndex);
	}
	else
	{
		return canPass({ pos.first + 1, pos.second }, startIndex);
	}
}

int result = 5;

void pick(int maxCount, int count)
{
	if (maxCount == count)
	{
		/*for (int j = 0; j < maxCount; j++)
		{
			cout << passArr[pickArr[j]].first << " " << passArr[pickArr[j]].second << " ";
			cout << '\n';
		}
		cout << '\n';
		cout << '\n';*/

		// 여기에 다리 추가 코드 추가
		for (int i = 0; i < maxCount; i++)
		{
			mapArr[passArr[pickArr[i]].first][passArr[pickArr[i]].second] = 1;
		}

		bool canClear = true;
		for (int i = 1; i <= n; i++)
		{
			bool chkPass = canPass({ 1, i }, i);
			if (chkPass == false)
			{
				canClear = false;
				break;
			}
		}

		if (canClear == true)
		{
			result = min(result, maxCount); // 업데이트
			return;
		}

		// 여기에 다리 해제 코드 추가
		for (int i = 0; i < maxCount; i++)
		{
			mapArr[passArr[pickArr[i]].first][passArr[pickArr[i]].second] = 0;
		}
	}
	else
	{
		for (int i = 0; i < (n - 1) * h; i++)
		{
			if (count > 0 && pickArr[count - 1] >= i) continue; 
			if (mapArr[passArr[i].first][passArr[i].second] == 1) continue; // 해당 인덱스에 이미 다리가 있는 경우 확인

			pickArr[count] = i;
			pick(maxCount, count + 1);
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> h;

	// h가 row
	// n이 col

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		mapArr[a][b] = 1;
	}

	int pickIndex = 0;
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j < n; j++)
		{
			passArr[pickIndex] = { i, j };
			pickIndex++;
		}
	}

	bool canClear = true;
	for (int i = 1; i <= n; i++)
	{
		bool chkPass = canPass({ 1, i }, i);
		if (chkPass == false)
		{
			canClear = false;
			break;
		}
	}

	if (canClear == true)
	{
		cout << 0; // 아무것도 추가하지 않고 패스 가능함
		return 0;
	}


	pick(1, 0);
	pick(2, 0);
	pick(3, 0);

	if (result == 5) cout << -1;
	else cout << result;

	return 0;
}