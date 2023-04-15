#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> st;
	int count;
	
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		int tmp;
		cin >> tmp;

		if (tmp == 0)
		{
			st.pop();
		}
		else 
		{
			st.push(tmp);
		}
	}

	int sum = 0;

	while (st.size() != 0)
	{
		sum += st.top();
		st.pop();
	}

	cout << sum;

	return 0;
}