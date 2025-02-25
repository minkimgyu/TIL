#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int maxSize = 50 + 5;
long long int states[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string s, yAndN;
		cin >> s >> yAndN;

		//long long int item = 0;
		//long long int multi = 1;

		//for (int j = m - 1; j > -1; j--)
		//{
		//	if (yAndN[j] == 'Y') item += multi;
		//	multi *= 2;
		//}

		//states[i] = item;

		for (int j = m - 1; j > -1; j--)
		{
			states[i] = (states[i] << 1) | (yAndN[j] == 'Y'); // 한 칸 밀어주고 (yAndN[j] == 'Y')가 참이라면 맨 끝에 1 추가
		}
	}

	int result = -1; // 최대 10개까지 선택 가능
	long long int storedState = 0;

	for (int i = 0; i < (1 << n); i++) // 2^n만큼 시행 반복 ex) m이 5라면 00000, 00001, 00011... 이런식으로 진행됨
	{
		int pickCount = 0;
		long long int state = 0;

		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				state |= states[j];
				pickCount++;
			}
		}

		if (storedState < state) // 더 많이 연주할 수 있는 경우
		{
			storedState = state;
			result = pickCount;
		}
		else if (storedState == state && result > pickCount) // 연주할 수 있는 노래 개수는 같지만 선택한 기타 개수가 적은 경우
		{
			result = pickCount;
		}
	}

	cout << result;
	return 0;
}