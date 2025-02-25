#include <iostream>
using namespace std;

int n;

const int maxSize = 100000;
int arr[maxSize];

bool visit[maxSize + 1]; // 1���� 100,000����


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int start = 0;
	int end = 0;

	long long int result = 0; // �ִ� ����� ���� 1���� 100,000���� ���� ������ ���� 5,000,050,000�̴�.

	visit[arr[end]] = true;

	while (start < n)
	{
		if (end < n - 1 && visit[arr[end + 1]] == false) // ���� end�� false�� ��츦 ����
		{
			end++;
			visit[arr[end]] = true;
		}
		else
		{
			result += end - start + 1;
			visit[arr[start]] = false;
			start++;
		}
	}

	cout << result;

	return 0;
}