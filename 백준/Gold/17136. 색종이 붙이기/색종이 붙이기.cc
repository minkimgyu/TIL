#include <iostream>
using namespace std;

const int maxSize = 10;
int arr[maxSize][maxSize];

int imgArr[5] = { 5, 5, 5, 5, 5 };

pair<int, int> offsets[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int result = 100 + 5;
int inputSize = 0;

bool canClear = false;

bool inRange(pair<int, int> point)
{
	if (point.first < 0 || point.second < 0 || point.first >= maxSize || point.second >= maxSize) return false;
	return true;
}

bool canFillRange(pair<int, int> point, int size)
{
	if (imgArr[size] <= 0) return false; // 해당 사이즈 색종이 개수가 0인 경우

	for (int i = point.first; i <= point.first + size; i++)
	{
		for (int j = point.second; j <= point.second + size; j++)
		{
			if (inRange({i, j}) == false || arr[i][j] != 1) return false; // 범위를 넘치면 붙일 수 없음, 0이면 붙일 수 없음, 이미 붙어진 경우 붙일 수 없음
		}
	}

	return true;
}

void fillRange(pair<int, int> point, int size)
{
	for (int i = point.first; i <= point.first + size; i++)
	{
		for (int j = point.second; j <= point.second + size; j++)
		{
			arr[i][j] = 3; // 해당 크기의 색종이로 붙여줌
		}
	}

	imgArr[size] -= 1;
}

void clearRange(pair<int, int> point, int size)
{
	for (int i = point.first; i <= point.first + size; i++)
	{
		for (int j = point.second; j <= point.second + size; j++)
		{
			arr[i][j] = 1; // 다시 돌려줌
		}
	}

	imgArr[size] += 1;
}

void dfs(int fillCount)
{
	//if (canClear == true) return; // 큰 거부터 채워서 모두 다 채우면 가장 먼저 채워지는게 가장 작은 수로 채우는거

	if (fillCount >= inputSize) // 빈 공간을 모두 색종이로 채운 경우
	{
		int totalUsage = 0;
		for (int i = 0; i < 5; i++)
		{
			totalUsage += 5 - imgArr[i]; // 사용한 만큼 더하기
		}

		result = min(result, totalUsage);
		return;
	}
	
	for (int r = 0; r < maxSize; r++)
	{
		for (int c = 0; c < maxSize; c++)
		{
			if (arr[r][c] == 1)
			{
				for (int i = 0; i < 5; i++)
				{
					pair<int, int> pos = { r, c };

					// 붙어있지 않은 경우 새로 붙어야함
					if (canFillRange(pos, i) == false) continue;

					fillRange(pos, i);
					dfs(fillCount + ((i + 1) * (i + 1)));
					//if (canClear == true) return;
					clearRange(pos, i);
				}

				return;
			}
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < maxSize; i++)
	{
		for (int j = 0; j < maxSize; j++)
		{
			int nowFill;
			cin >> nowFill;
			arr[i][j] = nowFill;

			if (nowFill == 1) inputSize++;
		}
	}

	if (inputSize == 0) cout << 0;
	else
	{
		dfs(0);
		if (result == 105) cout << -1;
		else cout << result;
	}
	
	return 0;
}