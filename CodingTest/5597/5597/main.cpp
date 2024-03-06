#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int main()
{
	/*ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/

	const int n = 30;
	bool arr[n];
	for (int i = 0; i < n; i++) arr[i] = false;

	for (int i = 0; i < 28; i++)
	{
		int index;
		scanf("%d", &index);

		arr[index - 1] = true;
	}

	for (int i = 0; i < n; i++) if (arr[i] == false) cout << i + 1 << '\n';

	return 0;
}