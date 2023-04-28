#include <iostream>
#include <string>
using namespace std;

int main()
{
	int count;
	cin >> count;

	string st;

	for (int i = 0; i < count; i++)
	{
		cin >> st;

		int sum = 0;
		int addCount = 0;
		int size = st.size();

		char beforeCha;
		for (int i = 0; i < size; i++)
		{
			if (i == 0) 
			{
				beforeCha = st[i];

				if (st[i] == 'O')
				{
					addCount++;
					sum += addCount;
				}

				continue;
			}

			if (st[i] == 'O')
			{
				if (st[i] != beforeCha)
				{
					addCount = 0;
				}

				addCount++;
				sum += addCount;
			}

			beforeCha = st[i];
		}

		cout << sum << '\n';
	}

	return 0;
}