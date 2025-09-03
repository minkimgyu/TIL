#include <iostream>
#include <string>
#include <deque>
using namespace std;

const int gearSize = 4;
const int gearPickCount = 8;

deque<int> gears[gearSize + 1];

int GetLeftGearItem(int idx)
{
	return gears[idx][6];
}

int GetRightGearItem(int idx)
{
	return gears[idx][2];
}

int GetTopGearItem(int idx)
{
	return gears[idx][0];
}

// dir이 1인 경우는 시계 방향이고, -1인 경우는 반시계 방향
void RotationGear(int idx, int dir)
{
	if (dir == 1)
	{
		int back = gears[idx].back();
		gears[idx].pop_back();
		gears[idx].push_front(back);
	}
	else
	{
		int front = gears[idx].front();
		gears[idx].pop_front();
		gears[idx].push_back(front);
	}
}

void dfs(int idx, int dir, int beforeValue = -1, int beforeIdx = -1)
{
	if (idx == 0 || idx == 5) return; // 끝인 경우 return 0 ~ 3

	bool isMove = false;

	int originLeft = GetLeftGearItem(idx);
	int originRight = GetRightGearItem(idx);

	if (beforeIdx == -1) // 이전 기어 움직임이 없다면 그냥 움직임
	{
		RotationGear(idx, dir);
		isMove = true;
	}
	else
	{
		if (beforeIdx > idx) // 왼쪽의 경우
		{
			int right = GetRightGearItem(idx);
			int left = beforeValue;
			if (right != left) // 극이 다른 경우
			{
				// 회전
				RotationGear(idx, dir);
				isMove = true;
			}
		}
		else // 오른쪽의 경우
		{
			int left = GetLeftGearItem(idx);
			int right = beforeValue;

			if (left != right) // 극이 다른 경우
			{
				// 회전
				RotationGear(idx, dir);
				isMove = true;
			}
		}
	}

	if (isMove == true) // 본인이 움직였다면
	{
		// 이전 움직임이 없다면 둘 다 움직이기
		if (beforeIdx == -1)
		{
			dfs(idx - 1, -dir, originLeft, idx);
			dfs(idx + 1, -dir, originRight, idx);
		}
		else // 이전 움직임이 있다면 한쪽만 움직이기
		{
			if (beforeIdx > idx) // 왼쪽의 경우
			{
				dfs(idx - 1,-dir, originLeft, idx);
			}
			else // 오른쪽의 경우
			{
				dfs(idx + 1, -dir, originRight, idx);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= gearSize; i++)
	{
		string s;
		cin >> s;

		for (int k = 0; k < s.size(); k++)
		{
			gears[i].push_back(s[k] - '0');
		}
	}

	int k;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int idx, rotationDirection;
		cin >> idx >> rotationDirection;

		dfs(idx, rotationDirection);
	}

	int result = GetTopGearItem(1) * 1 + GetTopGearItem(2) * 2 + GetTopGearItem(3) * 4 + GetTopGearItem(4) * 8;
	cout << result;

	return 0;
}