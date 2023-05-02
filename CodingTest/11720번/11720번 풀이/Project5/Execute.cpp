#include <iostream>
#include <string>
using namespace std;

int main() 
{
	int count = 0;
	cin >> count;

	string st;
	cin >> st;
	
	int returnValue = 0;

	for (int i = 0; i < count; i++)
	{
		int tmp = (int)st[i] - '0';
		returnValue += tmp;
	}

	cout << returnValue;

	return 0;
}