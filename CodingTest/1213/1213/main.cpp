#include <iostream>
#include <string>
using namespace std;

const int arrSize = 26;
int arr[arrSize]{ 0 };

// Ȧ���� ���ڸ� �ϳ� ���� �߰��� �ִ� ������ �߿���

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	const int size = 51;
	char str[size];
	cin.getline(str, size);

	int oddCnt = 0;

	int i = 0;
	while (1)
	{
		if (str[i] == '\0') break;

		int index = (int)str[i] - 65;
		arr[index] += 1;

		if (arr[index] % 2 != 0)
		{
			oddCnt++;
		}
		else
		{
			oddCnt--;
		}

		i++;
	}

	if (oddCnt > 1)
	{
		cout << "I'm Sorry Hansoo";
		return 0;
	}

	int currentOddIndex = -1;

	for (int f = 0; f < arrSize; f++)
	{
		if (arr[f] % 2 != 0)
		{
			currentOddIndex = f;
			break;
		}
	}

	char* result = new char[i];
	bool addFront = true;

	int frontIndex = 0;
	int backIndex = i - 1;

	// Ȧ���� �����ϴ� ��쿡�� ����
	if (currentOddIndex != -1)
	{
		result[i / 2] = (char)(currentOddIndex + 65);
		arr[currentOddIndex] -= 1;
	}

	for (int j = 0; j < arrSize; j++)
	{
		for (int k = 0; k < arr[j]; k++)
		{
			char alpha = (char)(j + 65);

			if (addFront == true)
			{
				result[frontIndex] = alpha;
				frontIndex++;
			}
			else
			{
				result[backIndex] = alpha;
				backIndex--;
			}

			addFront = !addFront;
		}
	}

	for (int l = 0; l < i; l++)
	{
		cout << result[l];
	}

	delete[] result;

	return 0;
}