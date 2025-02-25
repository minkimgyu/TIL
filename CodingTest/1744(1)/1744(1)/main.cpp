#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> belowArr;
vector<int> upperArr;

bool upperCompare(int a, int b)
{
	return a > b;
}

bool belowCompare(int a, int b)
{
	return a < b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;

		if (item <= 0)
		{
			belowArr.push_back(item);
		}
		else
		{
			upperArr.push_back(item);
		}
	}

	sort(upperArr.begin(), upperArr.end(), upperCompare);
	sort(belowArr.begin(), belowArr.end(), belowCompare);

	// 0���� ū ���� ũ�Ⱑ ū ������ �����ϰ� �����ش�.
	// 0�̳� 0 ���� ���� ���� ũ�Ⱑ ���� ������ �����ϰ� �����ش�.
	int upperArrSize = upperArr.size();
	for (int i = 0; i < upperArrSize; i += 2)
	{
		if (i + 1 >= upperArrSize)
		{
			sum += upperArr[i];
		}
		else
		{
			// 1, 2 --> 1 + 2�� �� ŭ
			// 1, 1 --> 1 + 1�� �� ŭ
			if (upperArr[i] == 1 || upperArr[i + 1] == 1)
			{
				sum += upperArr[i] + upperArr[i + 1];
				continue;
			}

			sum += upperArr[i] * upperArr[i + 1];
		}
	}

	int belowArrSize = belowArr.size();
	for (int i = 0; i < belowArrSize; i += 2)
	{
		if (i + 1 >= belowArrSize)
		{
			sum += belowArr[i];
		}
		else
		{
			if (belowArr[i] < 0 && belowArr[i + 1] == 0) // 0�� �����ִٸ� ���� �����ִ� ���� �� ŭ
			{
				sum += belowArr[i] * belowArr[i + 1]; // 0���� ������ش�.
				continue;
			}

			// 0, 0�� ���� ���ϴ� ���ϴ� �Ȱ��� ������ �׳� �������ش�.
			sum += belowArr[i] * belowArr[i + 1];
		}
	}

	cout << sum;

	return 0;
}