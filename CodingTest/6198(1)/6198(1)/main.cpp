#include <iostream>
#include <stack>
using namespace std;

const int maxSize = 80000;
int arr[maxSize];

// �������� �ݷ�
// 
// n�� 1�� ���
// 
// n�� 80,000�� ��� - result�� ������ ���� ���
// 
// 
// 1, 2, 3, 4, 5, 6, 7, 8, 9 ... 80,000���� �� ���ϰ� �ȴ�.
// �̷ν� int ���� �ʰ� ������ �߻���
//
//


int main()
{
	int n;
	cin >> n;

	long long int result = 0;

	stack<pair<int, long long int>> s;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = n - 1; i > -1; i--)
	{
		int item = arr[i];

		if (s.empty() == true)
		{
			s.push({ item , 0 });
		}
		else
		{
			long long int roofCount = 0;
			while (s.empty() == false && s.top().first < item)
			{
				roofCount += s.top().second + 1;
				s.pop();
			}

			s.push({ item, roofCount });
			result += roofCount;
		}
	}

	cout << result;
	return 0;
}