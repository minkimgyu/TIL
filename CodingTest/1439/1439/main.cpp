#include <iostream>
using namespace std;

void CountUp(char* arr, int index, int* zeroCount, int* oneCount)
{
	if (arr[index] == '0') *zeroCount += 1;
	else if (arr[index] == '1') *oneCount += 1;
}


// 그리디 알고리즘은 현 상황에서 가장 이득이 되는 경우를 고르면 됨
// 즉 가장 적게 붙어있는 값을 뒤집으면 답이 된다.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int size = 1000001; // 문자열이므로 크기를 +1 해줌

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