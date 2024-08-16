#include <iostream>
#include <string>
using namespace std;

string input;
bool check[100];

void dfs(int start, int end)
{
	if (start > end) return;

	char min = input[start];
	int minIndex = start;

	for (int i = start; i <= end; i++)
	{
		if (input[i] < min)
		{
			min = input[i];
			minIndex = i;
		}
	}

	check[minIndex] = true;
	for (int i = 0; i < input.size(); i++)
	{
		if (check[i] == false) continue;
		cout << input[i];
	}
	cout << '\n';

	dfs(minIndex + 1, end);
	dfs(start, minIndex - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getline(cin, input);

	dfs(0, input.size() - 1);
	return 0;
}