#include <iostream>
#include <string>
using namespace std;

const int maxSize = 1000000 + 5;
int arr[maxSize];

int acgt[4];

int correctArr[4];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);

	int s, p;
	cin >> s >> p;

	string st;
	cin >> st;

	for (int i = 0; i < 4; i++) cin >> acgt[i];

	int result = 0;

	int right = 0;
	for (int left = 0; left < s; left++)
	{
		while (right < s && right - left < p)
		{
			switch (st[right])
			{
				case 'A':
					correctArr[0] += 1;
					break;

				case 'C':
					correctArr[1] += 1;
					break;

				case 'G':
					correctArr[2] += 1;
					break;

				case 'T':
					correctArr[3] += 1;
					break;
			}
			right++;
		}

		if ((right - 1) - left + 1 == p) // 길이가 P인 경우만
		{
			bool isCorrect = true;
			for (int i = 0; i < 4; i++)
			{
				if (correctArr[i] < acgt[i])
				{
					isCorrect = false;
					break;
				}
			}

			if (isCorrect == true) result += 1;
		}

		switch (st[left])
		{
			case 'A':
				correctArr[0] -= 1;
				break;

			case 'C':
				correctArr[1] -= 1;
				break;

			case 'G':
				correctArr[2] -= 1;
				break;

			case 'T':
				correctArr[3] -= 1;
				break;
		}
	}
	
	cout << result;

	return 0;
}