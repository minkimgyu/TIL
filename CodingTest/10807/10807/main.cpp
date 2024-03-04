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

	int* arr = new int[cnt]; // 동적할당 하는 방식
	for (int i = 0; i < cnt; i++)
	{
		int input;
		cin >> input; // 이런 방식으로 여러 개를 받을 수 있다.
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