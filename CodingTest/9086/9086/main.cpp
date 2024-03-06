#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count = 1000;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char* arr = new char[count]; // 동적 할당 후 해제하는 방식으로 진행
		cin >> arr;

		int start = 0;
		int end = 0;

		for (int i = 0; i < count; i++)
		{
			if (arr[i] == '\0')
			{
				end = i - 1; // 마지막 문자일 경우, 이 앞까지 확인하기
				break;
			}
		}

		cout << arr[start] << arr[end] << '\n';
		delete[] arr;
	}

	return 0;
}