#include <map>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

#include <sstream>
using namespace std;

int main()
{
	istringstream s1("akwhdkuagh_wdkuhawkud_awukhdkuawhdu_awdkuaukwdh");

	string tmp;
	while (getline(s1, tmp, '_'))
	{
		cout << tmp << '\n';
	}

	return 0;
}