#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
using namespace std;

void Check(list<int>* li, string st);
vector<string> split(string str, char Delimiter);

int main()
{
	int count;
	cin >> count;
	cin.ignore();

	list<int> li;
	string st;

	for (int i = 0; i < count; i++)
	{
		getline(cin, st);
		Check(&li, st);
	}

	return 0;
}

void Check(list<int>* li, string st)
{
	if (st.find("push_front") != string::npos)
	{
		vector<string> tmp = split(st, ' ');
		li->emplace_front(stoi(tmp[1]));
	}
	else if(st.find("push_back") != string::npos)
	{
		vector<string> tmp = split(st, ' ');
		li->emplace_back(stoi(tmp[1]));
	}
	else if (st.find("pop_front") != string::npos)
	{
		if (li->empty() == true)
		{
			cout << -1 << '\n';
			return;
		}

		int tmp = li->front();
		li->pop_front();
		cout << tmp << '\n';
	}
	else if (st.find("pop_back") != string::npos)
	{
		if (li->empty() == true)
		{
			cout << -1 << '\n';
			return;
		}

		int tmp = li->back();
		li->pop_back();
		cout << tmp << '\n';
	}
	else if (st.find("size") != string::npos)
	{
		cout << li->size() << '\n';
	}
	else if (st.find("empty") != string::npos)
	{
		cout << li->empty() << '\n';
	}
	else if (st.find("front") != string::npos)
	{
		if (li->empty() == true)
		{
			cout << -1 << '\n';
			return;
		}

		cout << li->front() << '\n';
	}
	else if (st.find("back") != string::npos)
	{
		if (li->empty() == true)
		{
			cout << -1 << '\n';
			return;
		}

		cout << li->back() << '\n';
	}
}

vector<string> split(string str, char Delimiter) {
	istringstream iss(str);             // istringstream�� str�� ��´�.
	string buffer;                      // �����ڸ� �������� ����� ���ڿ��� ������� ����

	vector<string> result;

	// istringstream�� istream�� ��ӹ����Ƿ� getline�� ����� �� �ִ�.
	while (getline(iss, buffer, Delimiter)) {
		result.push_back(buffer);               // ����� ���ڿ��� vector�� ����
	}

	return result;
}