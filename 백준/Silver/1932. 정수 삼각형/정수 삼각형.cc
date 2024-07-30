#include <iostream>
#include <vector>
using namespace std;

int dp[200000];
int arr[200000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			int index = count + j;
			int tmp;
			cin >> tmp;

			dp[index] = tmp;
			arr[index] = tmp; // 원본 값
		}
		count += i + 1; // 라인에 있는 숫자 개수만큼 더해줌
	}


	int max = -1;

	count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			int index = count + j;

			int leftChild = dp[index + i + 1];
			int rightChild = dp[index + i + 2];

			// 여기서는 원본 arr 값을 사용해서 읽어와야 한다.
			int afterLeftChild = arr[index + i + 1] + dp[index];
			int afterRightChild = arr[index + i + 2] + dp[index];

			if (afterLeftChild > leftChild) dp[index + i + 1] = afterLeftChild;
			if (afterRightChild > rightChild) dp[index + i + 2] = afterRightChild;

			if (dp[index + i + 1] > max) max = dp[index + i + 1];
			if (dp[index + i + 2] > max) max = dp[index + i + 2];
		}
		count += i + 1; // 라인에 있는 숫자 개수만큼 더해줌
	}

	cout << max;

	return 0;
}