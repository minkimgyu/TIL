#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<stack<string>> vec;
	int count;
	cin >> count;
	cin.ignore();

	for (int i = 0; i < count; i++)
	{
		string st;
		getline(cin, st);

		string tmp;
		stack<string> tmpSt;

		for (int j = 0; j < st.size(); j++)
		{
			if (st[j] == ' ')
			{
				tmpSt.push(tmp);
				tmp = "";
			}
			else 
			{
				tmp += st[j];
			}

			if (j == st.size() - 1)
			{
				tmpSt.push(tmp);
				tmp = "";
			}
		}

		vec.emplace_back(tmpSt);
	}

	for (int i = 0; i < vec.size(); i++)
	{
		stack<string> tmp = vec[i];
		cout << "Case #" << i + 1 << ": ";
		int tmpCount = tmp.size();

		for (int j = 0; j < tmpCount; j++)
		{
			if (j != tmpCount - 1) cout << tmp.top() << " ";
			else cout << tmp.top();
			
			tmp.pop();
		}

		cout << '\n';
	}

	return 0;
}