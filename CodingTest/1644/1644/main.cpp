#include <iostream>
#include <vector>
using namespace std;

// �����佺�׳׽��� ü�� ����ؼ� �Ҽ��� ������
// 2 ~ 4000000
// 2���� �ڱ� �ڽ��� ������ ������� �������ش�.


const int maxSize = 4000000;
pair<int, int> arr[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	// �Ҽ� ���ϱ�
	for (int i = 0; i <= n; i++)
	{
		arr[i] = { i, true };
	}

	for (int i = 2; i <= n; i++)
	{
		int multi = 2; // �ڱ� �ڽ� ����
		while (arr[i].first * multi <= n)
		{
			int multiNumIndex = arr[i].first * multi;
			arr[multiNumIndex].second = false;

			multi++;
		}
	}

	vector<int> primeNums;
	for (int i = 2; i <= n; i++)
	{
		if (arr[i].second == false) continue;
		primeNums.push_back(arr[i].first);
	}

	int start = -1;
	int end = -1;

	int sum = 0;
	int result = 0;

	int primeNumLastIndex = primeNums.size() - 1;
	while (start < primeNumLastIndex)
	{
		if (sum < n && end < primeNumLastIndex) // end�� primeNumIndexSize���� �۾ƾ���
		{
			end++;
			sum += primeNums[end];
		}
		else
		{
			start++;
			sum -= primeNums[start];
		}

		if (sum == n)
		{
			result++;
		}
	}

	cout << result;
	return 0;
}