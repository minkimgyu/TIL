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

	if (st == " ") cout << cnt; // ���� 1���� ���� ��쵵 �������ֱ�
	else cout << cnt + 1;
	
	return 0;
}