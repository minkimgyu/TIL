#include <iostream>
#include <string>
using namespace std;

// - �ڿ� ������ ��� ���ڴ� ���ִ� �ɷ� �����ϰ� �����ϸ� ����.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int firstItem = 0;
	int secondItem = 0;

	bool changeState = false;

	const int size = 51;
	char arr[size];

	cin.getline(arr, size);

	char integer[3];
	int integerIndex = 0;

	int index = 0;

	bool stateChange = false;

	int firstSum = 0;
	int secondSum = 0;
	while (1)
	{
		if (arr[index] == '+' || arr[index] == '-' || arr[index] == '\0')
		{
			integer[integerIndex] = '\0';

			if (stateChange == false) firstSum += atoi(integer);
			else secondSum += atoi(integer);

			integerIndex = 0;

			if (arr[index] == '-') stateChange = true;
			else if (arr[index] == '\0') break;
		}
		else
		{
			if ((integerIndex == 0 && arr[index] == '0') == false)
			{
				integer[integerIndex] = arr[index];
				integerIndex++;
			}
		}

		index++;
	}

	cout << firstSum - secondSum;

	return 0;
}