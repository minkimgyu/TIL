#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	cin.ignore();

	int result = 0;

	for (int j = 0; j < n; j++)
	{
		string line;
		getline(cin, line);

		stack<char> stack;
		for (int i = 0; i < line.size(); i++)
		{
			char item = line[i];

			if (stack.empty() == true)
			{
				stack.push(item);
			}
			else
			{
				char top = stack.top();

				if (item == top)
				{
					stack.pop();
				}
				else
				{
					stack.push(item);
				}
			}
		}

		if (stack.empty() == true) result++;
	}

	cout << result;
	return 0;
}