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
		st.push(tmp);
	}
	
	int right = st.top();
	int biggerThen = 1; // 맨 오른쪽은 기본적으로 보임

	while (st.size() != 0)
	{
		int tmp = st.top();
		if (right < tmp)
		{
			right = tmp;
			biggerThen++;
		}

		st.pop();
	}

	cout << biggerThen;

	return 0;
}