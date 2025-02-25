#include <iostream>
#include <string>
#include <stack>
using namespace std;

int n;

int main()
{
	cin >> n;
	cin.ignore();

	int result = 0;

	for (int i = 0; i < n; i++)
	{
		stack<char> st;

		string line;
		getline(cin, line);

		for (int j = 0; j < line.size(); j++)
		{
			if (st.empty() == true)
			{
				st.push(line[j]);
			}
			else
			{
				if (st.top() == line[j])
				{
					st.pop();
				}
				else
				{
					st.push(line[j]);
				}
			}
		}

		if (st.empty() == true) result += 1;
	}

	cout << result;

	return 0;
}