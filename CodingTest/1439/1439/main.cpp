#include <iostream>
using namespace std;

void CountUp(char* arr, int index, int* zeroCount, int* oneCount)
{
	if (arr[index] == '0') *zeroCount += 1;
	else if (arr[index] == '1') *oneCount += 1;
}


// �׸��� �˰����� �� ��Ȳ���� ���� �̵��� �Ǵ� ��츦 ���� ��
// �� ���� ���� �پ��ִ� ���� �������� ���� �ȴ�.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int size = 1000001; // ���ڿ��̹Ƿ� ũ�⸦ +1 ����

	char* arr = new char[size];
	cin.getline(arr, size);

	int zeroCount = 0;
	int oneCount = 0;


	for (int i = 0; i < size; i++)
	{
		if (arr[i] == '\0') break;

		if (i == 0)
		{
			CountUp(arr, i, &zeroCount, &oneCount);
			continue;
		}


		if (arr[i - 1] != arr[i])
		{
			CountUp(arr, i, &zeroCount, &oneCount);
		}
	}

	if (zeroCount < oneCount) cout << zeroCount;
	else cout << oneCount;

	return 0;
}