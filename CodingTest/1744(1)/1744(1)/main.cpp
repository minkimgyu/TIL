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

	// 0보다 큰 것은 크기가 큰 순으로 정렬하고 곱해준다.
	// 0이나 0 보다 작은 경우는 크기가 작은 순으로 정렬하고 곱해준다.
	int upperArrSize = upperArr.size();
	for (int i = 0; i < upperArrSize; i += 2)
	{
		if (i + 1 >= upperArrSize)
		{
			sum += upperArr[i];
		}
		else
		{
			// 1, 2 --> 1 + 2가 더 큼
			// 1, 1 --> 1 + 1이 더 큼
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
			if (belowArr[i] < 0 && belowArr[i + 1] == 0) // 0이 끼어있다면 둘을 곱해주는 것이 더 큼
			{
				sum += belowArr[i] * belowArr[i + 1]; // 0으로 만들어준다.
				continue;
			}

			// 0, 0인 경우는 곱하던 더하던 똑같기 때문에 그냥 적용해준다.
			sum += belowArr[i] * belowArr[i + 1];
		}
	}

	cout << sum;

	return 0;
}