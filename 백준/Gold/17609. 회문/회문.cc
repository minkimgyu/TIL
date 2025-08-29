#include <iostream>
#include <string>
using namespace std;

string s;

int isCorrect(int left, int right, int InCorrectCount)
{
	while (left < right) // 같은 경우는 볼 필요 없음
	{
		char leftItem = s[left];
		char rightItem = s[right];

		if (leftItem == rightItem)
		{
			left++;
			right--;
		}
		else
		{
			if (InCorrectCount == 0)
			{
				if (isCorrect(left + 1, right, 1) == 0 || isCorrect(left, right - 1, 1) == 0) return 1;
				return 2;
			}
			else
			{
				return 2;
			}
		}
	}

	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> s;

		int left = 0;
		int right = s.size() - 1;

		int missCount = isCorrect(0, right, 0);

		if (missCount == 2) cout << 2;
		else if (missCount == 1) cout << 1;
		else cout << 0;

		if(i != t - 1) cout << '\n';
	}

	return 0;
}