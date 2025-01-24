#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	cin >> num;

	int i = 2;
	vector<int> list;

	while (i * i <= num)
	{
		if (num % i == 0)
		{
			num /= i;
			list.push_back(i);
			continue;
		}
		i += 1;
	}

	if (num != 1) list.push_back(num);

	int listSize = list.size();
	for (int i = 0; i < listSize; i++)
	{
		cout << list[i];
		if (i != listSize - 1) cout << '\n';
	}

	return 0;
}