#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;

		multiset<int> multiSet;

		for (int j = 0; j < n; j++)
		{
			char key;
			int item;

			cin >> key >> item;

			if (key == 'I')
			{
				multiSet.insert(item);
			}
			else if (key == 'D')
			{
				if (multiSet.empty() == true) continue;

				if (item == 1)
				{
					multiSet.erase(--multiSet.end());
				}
				else if (item == -1)
				{
					multiSet.erase(multiSet.begin());
				}
			}
		}

		if (multiSet.empty() == true)
		{
			cout << "EMPTY";
		}
		else
		{
			cout << *--multiSet.end() << " " << *multiSet.begin();
		}

		if (i != t - 1) cout << '\n';
	}

	return 0;
}