#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt, num, countOfPickedNumber = 0;
	cin >> cnt;

	/*int arr[100];

	for (int i = 0; i < cnt; i++)
	{
		int input;
		cin >> input;
		arr[i] = input;
	}

	cin >> num;

	for (int i = 0; i < cnt; i++)
	{
		if (arr[i] == num) countOfPickedNumber++;
	}*/

	int* arr = new int[cnt]; // �����Ҵ� �ϴ� ���
	for (int i = 0; i < cnt; i++)
	{
		int input;
		cin >> input; // �̷� ������� ���� ���� ���� �� �ִ�.
		*(arr + i) = input;
	}

	cin >> num;

	for (int i = 0; i < cnt; i++)
	{
		if (arr[i] == num) countOfPickedNumber++;
	}

	cout << countOfPickedNumber;
	delete []arr;

	return 0;
}