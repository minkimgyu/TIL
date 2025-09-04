#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 
// a b c d e f g h i j k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
// 
// 0, 13, 19, 8, 2 제외하기
// a n t i c + r, -> 기본 5글자 + 조합 뽑기
const int maxSize = 50 + 5;
vector<string> lines;

int n, k;

int makableAlphaCount = 0;
const int maxCharCount = 5;
const int maxAlphaCount = 26;

int pickArr[maxAlphaCount];
int result = 0;

void Pick(int idx, int count)
{
	if (count == k - 5)
	{
		int currentPickResult = 0;
		for (auto line : lines)
		{
			bool flag = true;
			for (auto item : line)
			{
				if (!pickArr[item - 'a'])
				{
					flag = false;
					break;
				}
			}

			if (flag == true)
			{
				currentPickResult++;
			}
		}

		result = max(result, currentPickResult);
	}
	else
	{
		for (int i = idx; i < maxAlphaCount; i++)
		{
			if (pickArr[i] != 0) continue; // 존재 한다면 진행하지 않음

			pickArr[i]++;
			Pick(i + 1, count + 1);
			pickArr[i]--;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		lines.push_back(s);
	}

	if (k < maxCharCount)
	{
		cout << 0;
		return 0;
	}

	makableAlphaCount = k - maxCharCount;

	pickArr[0] = 1;
	pickArr[13] = 1;
	pickArr[19] = 1;
	pickArr[8] = 1;
	pickArr[2] = 1;

	Pick(0, 0);

	cout << result;
}