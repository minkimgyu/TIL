#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	const int size = 6;
	int arr[6];

	int storedChess[6] = { 1, 1, 2, 2, 2, 8 };

	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < size; i++)
	{
		if (i == size - 1) cout << storedChess[i] - arr[i] << " ";
		else cout << storedChess[i] - arr[i] << " ";
	}

	return 0;
}