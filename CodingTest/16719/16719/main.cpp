#include <iostream>
#include <string>
using namespace std;

string input;
bool switchArr[100];

void dfs(int start, int end, string part)
{
	if (start > end) return;

	char startAlpha = part[start];
	char minIndex = start;

	for (int i = start; i <= end; i++)
	{
		if (startAlpha > part[i])
		{
			startAlpha = part[i];
			minIndex = i;
		}
	}

	switchArr[minIndex] = true;

	int inputSize = input.size();
	for (int i = 0; i < inputSize; i++)
	{
		if (switchArr[i] == true)
		{
			cout << input[i];
		}
	}

	cout << '\n';

	// 사전순으로 가장 빠른 원소를 뽑고
	// 다음으로 올 문자는 위 문자 뒤에 있는 문자로 해야함

	// 가장 빠른 원소부터 뽑기 때문에 그런 것임

	dfs(minIndex + 1, end, part); // --> 그래서 뒤부터 재귀를 돌려준다.
	dfs(start, minIndex - 1, part);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getline(cin, input);
	dfs(0, input.size() - 1, input);
	return 0;
}