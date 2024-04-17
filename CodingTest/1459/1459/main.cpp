#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int x, y, w, s;
	long long int time = 0;

	cin >> x >> y >> w >> s;

	if (2 * w <= s) // 가로 세로 가는 경우가 더 짧은 경우
	{
		if (x > y)
		{
			time += y * w * 2; // 가로지르는 것 없이 가로 세로 기반으로 이동한다.
			time += (x - y) * w;
		}
		else
		{
			time += x * w * 2;
			time += (y - x) * w;
		}
	}
	else if (2 * w > s) // 대각선으로 가는 경우가 더 짧은 경우
	{
		if (x > y)
		{
			time += y * s;

			int leftDistance = x - y;
			if (w > s)
			{
				int crossCnt = leftDistance / 2;
				int leftMove = leftDistance % 2;

				time += crossCnt * 2 * s; // 2번 가로지르기 때문에 이렇게 해야함
				time += leftMove * w;
			}
			else
			{
				time += leftDistance * w; // 그냥 올라감
			}
		}
		else
		{
			time += x * s;

			int leftDistance = y - x;

			if (w > s)
			{
				int crossCnt = leftDistance / 2;
				int leftMove = leftDistance % 2;

				time += crossCnt * 2 * s; // 2번 가로지르기 때문에 이렇게 해야함
				time += leftMove * w;
			}
			else
			{
				time += leftDistance * w; // 그냥 올라감
			}
		}
	}
	else if (2 * w == s) // 가로 세로 가는 길이랑 가로지르는 길이가 같은 경우
	{
		if (x > y)
		{
			time += y * s; // 작은 값의 길이만큼 가로질러준다.
			time += (x - y) * w;
		}
		else
		{
			time += x * s;
			time += (y - x) * w;
		}
	}


	cout << time;

	return 0;
}