#include <iostream>
#include <vector>
using namespace std;

const int n = 6;
int arr[n] = { 100, 150, 126, 1, 5, 3 };
int d = 3;
int p10[3];

int digitNum(int x, int a)
{
	return (x / p10[a]) % 10;
}

vector<int> l[10];

int main()
{
	p10[0] = 1;

	// 정수의 거듭제곱 계산
	for (int i = 1; i < d; i++) p10[i] = p10[i - 1] * 10; // 10 100 1000 채우기

	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < 10; j++) l[j].clear();
		for (int j = 0; j < n; j++)
		{
			l[digitNum(arr[j], i)].push_back(arr[j]);
		}
		int aidx = 0;
		for (int j = 0; j < 10; j++)
		{
			for (auto x : l[j])
			{
				arr[aidx++] = x;
			}
		}
	}

	for (int i = 0; i < n; i++) cout << arr[i] << " ";
	return 0;
}