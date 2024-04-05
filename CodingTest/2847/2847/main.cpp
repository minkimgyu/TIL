#include <iostream>
using namespace std;

// 뒤에서부터 확인하는 방법으로 진행
// 답이 없는 경우는 존재하지 않기 때문에 이 방식으로 작업해도 괜찮다.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int totalCnt = 0;

	for (int i = n - 1; i > 0; i--)
	{
		while (arr[i] <= arr[i - 1])
		{
			arr[i - 1] -= 1;
			totalCnt += 1;
		}
	}

	cout << totalCnt;

	return 0;
}