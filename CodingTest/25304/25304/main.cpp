#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int sum, buyCount = 0;
	cin >> sum;
	cin >> buyCount;

	int totalItemPrice = 0;
	for (int i = 0; i < buyCount; i++)
	{
		int price, counOfItem;
		cin >> price >> counOfItem;

		totalItemPrice += price * counOfItem;
	}

	if (totalItemPrice == sum) cout << "Yes";
	else cout << "No";

	return 0;
}