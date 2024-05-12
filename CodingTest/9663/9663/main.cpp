#include <iostream>
#include <vector>
using namespace std;

const int maxSize = 15;
bool map[maxSize];

bool checkLeftCross[maxSize * 2]{ false };
bool checkRightCross[maxSize * 2]{ false };


// y 값이 같으면 안 됨
// x 값이 같으면 안 됨
// 기울기 값이 같으면 안 됨

void recur(int n, int y, int* cnt, int loop)
{
	if (y >= n) return; // y 값이 범위를 벗어난 경우
	loop++;

	// x 검사
	for (int i = 0; i < n; i++)
	{
		/*if (i == 0 && y == 2 && map[1] == true && map[3] == true) 
		{
			int tmp = 123;
		}*/

		if (map[i] == true) continue;

		int leftCross = i - y + n;
		int rightCross = i + y;

		if (checkLeftCross[leftCross] == true || checkRightCross[rightCross] == true) continue;

		bool alreadyMapping = false;
		if (map[i] == true) alreadyMapping = true;
		else map[i] = true;
		
		bool alreadyCheckLeftCross = false;
		if (checkLeftCross[leftCross] == true) alreadyCheckLeftCross = true;
		else checkLeftCross[leftCross] = true;

		bool alreadyCheckRightCross = false;
		if (checkRightCross[rightCross] == true) alreadyCheckRightCross = true;
		else checkRightCross[rightCross] = true;

		if (loop == n) *cnt += 1;
		recur(n, y + 1, cnt, loop);

		if(alreadyMapping == false) map[i] = false;
		if (alreadyCheckLeftCross == false) checkLeftCross[leftCross] = false;
		if (alreadyCheckRightCross == false) checkRightCross[rightCross] = false;
	}

	loop--;
}

int main()
{
	int n;
	cin >> n;

	int cnt = 0;
	recur(n, 0, &cnt, 0);

	cout << cnt;
}