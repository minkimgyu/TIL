#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long double x, y;
	cin >> x >> y;

	int originalWinRatio = y * 100 / x;

	// 이미 승률이 100%인 경우 또는 99%인 경우
	if (originalWinRatio >= 99)
	{
		cout << -1;
		return 0;
	}

	int left = 1;
	int right = 1000000000;

	// 최대 1,000,000,000판 999,999,999승
	//  2,000,000,000판 1,999,999,999

	while (left <= right)
	{
		int mid = (left + right) / 2;

		long double  winGameCount = mid + y; // 앞으로 이길 게임 수 + 이미 이긴 게임 수
		long double  totalGameCount = mid + x;

		int winRatio = winGameCount * 100 / totalGameCount;

		// 만약 승률이 같다면 왼쪽 선택해줘야함 ->
		if (originalWinRatio >= winRatio) left = mid + 1;
		else right = mid - 1;
	}

	cout << left;
	return 0;
}