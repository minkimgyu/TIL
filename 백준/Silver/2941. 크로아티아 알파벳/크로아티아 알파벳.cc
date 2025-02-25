#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	getline(cin, s);
	int result = 0;

	string rep[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

	for (int i = 0; i < 8; i++)
	{
		while (s.find(rep[i]) != string::npos)
		{
			int index = s.find(rep[i]);
			s.replace(index, rep[i].size(), "R");
		}
	}

	cout << s.size();
	return 0;
}