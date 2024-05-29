#include <iostream>
#include <string>
using namespace std;

string s[101];
int cnt;

int main()
{
	string str;

	for (int i = 0; !cin.eof(); i++)
	{
		getline(cin, str);
		cout << str << '\n';
	}
    return 0;
}