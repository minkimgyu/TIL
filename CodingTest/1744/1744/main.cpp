#include <iostream>
#include <algorithm>
using namespace std;

bool positiveCompare(int a, int b)
{
	return a > b;
}

bool negativeCompare(int a, int b)
{
	return a < b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int positiveArr[50]{ 0 };
	int negativeArr[50]{ 0 };

	int positiveCnt = 0;
	int negativeCnt = 0;

	int n;
	cin >> n;

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

	sort(positiveArr, positiveArr + positiveCnt, positiveCompare);
	sort(negativeArr, negativeArr + negativeCnt, negativeCompare);

	int sum = 0;

	for (int i = 0; i < positiveCnt; i += 2)
	{
		if (i + 1 > positiveCnt - 1)
		{
			// i가 마지막 인덱스임
			sum += positiveArr[i];
			break;
		}

		int tmp;

		if (positiveArr[i] == 1 || positiveArr[i + 1] == 1)
		{
			tmp = positiveArr[i] + positiveArr[i + 1];
		}
		else
		{
			tmp = positiveArr[i] * positiveArr[i + 1];
		}

		sum += tmp;
	}

	for (int i = 0; i < negativeCnt; i += 2)
	{
		if (i + 1 > negativeCnt - 1)
		{
			// i가 마지막 인덱스임
			sum += negativeArr[i];
			break;
		}

		sum += negativeArr[i] * negativeArr[i + 1];
	}

	cout << sum;

	return 0;
}