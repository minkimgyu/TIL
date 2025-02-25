#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	string s, findStr;
	getline(cin, s);
	getline(cin, findStr);

	int pos = 0;
	int result = 0;
	while (pos < s.size())
	{
		int nxt = s.find(findStr, pos);

		if (nxt == string::npos)
		{
			pos = s.size();
		}
		else
		{
			pos = nxt + findStr.size();
			result++;
		}
	}

	cout << result;
	return 0;
}