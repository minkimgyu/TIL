#include <iostream>
#include <string>
using namespace std;

int main()
{
	string line;
	getline(cin, line);

	cout << ":fan::fan::fan:" << '\n';
	cout << ":fan::" << line << "::fan:" << '\n';
	cout << ":fan::fan::fan:";

	return 0;
}