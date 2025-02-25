#include <iostream>
#include <stack>
#include <string>
using namespace std;

int result = 0;
int before = 0;

string line;
stack<pair<int, int>> partStack;

void dfs(int index)
{
	if (index > line.size() - 1) return;

	if (line[index] == '(')
	{
		partStack.push({ result, before });
		result = 0;
	}
	else if (line[index] == ')')
	{
		pair<int, int> top = partStack.top();
		partStack.pop();
		result = top.first - 1 + (top.second * result);
	}
	else
	{
		result++;
		before = line[index] - '0';
	}

	dfs(index + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getline(cin, line);
	dfs(0);

	cout << result;
	return 0;
}