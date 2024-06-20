#include <iostream>
using namespace std;

const int arrSize = 101;
char arr[arrSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin.getline(arr, arrSize);

	int cnt = 0;
	int index = 0;
	while (1)
	{
		if (arr[index] == '\0') break;


		cnt++;
	}

	return 0;
}