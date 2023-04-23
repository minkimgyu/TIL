#include <iostream>
#include <string>
using namespace std;

int main()
{
	string st;

	getline(cin, st);

	int cnt = 0;
	for (int i = 0; i < st.size(); i++)
	{
		if (i == 0 || i == st.size() - 1) continue;

		if (st[i] == ' ') cnt++;
	}

	if (st == " ") cout << cnt; // 공백 1개만 있을 경우도 생각해주기
	else cout << cnt + 1;
	
	return 0;
}