#include <iostream>
#include <string>
using namespace std;

int result = 0;
string alpha[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getline(cin, s);

	for (int i = 0; i < 8; i++)
	{
		int start = 0;
		while (start < s.size() - 1 && s.find(alpha[i], start) != string::npos)
		{
			start = s.find(alpha[i], start);
			s.erase(start, alpha[i].size());
			s.insert(start, "A");
		}
	}

	cout << s.size();

	return 0;
}