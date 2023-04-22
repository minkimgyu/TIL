#include <iostream>
#include <string>
using namespace std;

int main()
{
	int count;
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		int multiply;
		string st;
		cin >> multiply >> st;

		int size = st.size();
		string newSt;

		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < multiply; k++)
			{
				newSt += st[j];
			}
		}

		cout << newSt << '\n';
	}

	return 0;
}