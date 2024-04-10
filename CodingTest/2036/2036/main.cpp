#include <iostream>
#include <algorithm>
using namespace std;

bool PositiveCompare(int a, int b)
{
	return a > b;
}

bool NegativeCompare(int a, int b)
{
	return a < b;
}

long long int positiveArr[100000];
long long int negativeArr[100000];

// 다 해놓고 1일 때 분기 처리를 안 했다...
// 양수, 0 + 음수로 범위를 나누고
// 정렬 후 따로 연산한다.
// 0 + 음수 보다 0 * 음수가 이득이므로 음수쪽에 0을 넣어서 연산한다.
// 
// 정답률에 비해서 생각보다 쉬웠던 문제

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int positiveCnt = 0;
	int negativeCnt = 0;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		if (tmp > 0)
		{
			positiveArr[positiveCnt] = tmp;
			positiveCnt++;
		}
		else
		{
			negativeArr[negativeCnt] = tmp;
			negativeCnt++;
		}
	}

	sort(positiveArr, positiveArr + positiveCnt, PositiveCompare);
	sort(negativeArr, negativeArr + negativeCnt, NegativeCompare);

	long long int sum = 0;

	for (int i = 0; i < positiveCnt; i += 2)
	{
		if (i + 1 > positiveCnt - 1) break;

		if (positiveArr[i] == 1 || positiveArr[i + 1] == 1)
		{
			sum += positiveArr[i] + positiveArr[i + 1];
		}
		else
		{
			sum += positiveArr[i] * positiveArr[i + 1];
		}
	}

	bool isOdd = positiveCnt % 2 != 0;
	if (isOdd) sum += positiveArr[positiveCnt - 1];



	for (int i = 0; i < negativeCnt; i += 2)
	{
		if (i + 1 > negativeCnt - 1) break;
		sum += negativeArr[i] * negativeArr[i + 1];
	}

	isOdd = negativeCnt % 2 != 0;
	if (isOdd) sum += negativeArr[negativeCnt - 1];
	

	cout << sum;

	return 0;
}