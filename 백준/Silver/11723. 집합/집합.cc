#include <iostream>
#include <string>
using namespace std;

int arr[20];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		if (s == "add")
		{
			int num;
			cin >> num;

			arr[num - 1] = 1;
		}
		else if (s == "remove")
		{
			int num;
			cin >> num;

			arr[num - 1] = 0;
		}
		else if (s == "check")
		{
			int num;
			cin >> num;

			cout << arr[num - 1];
			if (i != n - 1) cout << '\n';
		}
		else if (s == "toggle")
		{
			int num;
			cin >> num;

			arr[num - 1] = 1 ^ arr[num - 1];
		}
		else if (s == "all")
		{
			for (int i = 0; i < 20; i++)
			{
				arr[i] = 1;
			}
		}
		else if (s == "empty")
		{
			for (int i = 0; i < 20; i++)
			{
				arr[i] = 0;
			}
		}
	}

	return 0;
}