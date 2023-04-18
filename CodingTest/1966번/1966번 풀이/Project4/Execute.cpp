#include <iostream>
#include <list>
#include <string>
#include <sstream>
using namespace std;

list<int> split(string str, char Delimiter);

int main()
{
	list<int> priority;

	int count;
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		int cnt;
		int index;

		cin >> cnt >> index;
		cin.ignore();

		string st;
		getline(cin, st);

		priority = split(st, ' ');

		int backCount = 0;

		while (true)
		{
			bool nowHavePriority = false;
			int front = priority.front();

			for (std::list<int>::iterator itr = priority.begin(); itr != priority.end(); itr++) {

				if (*itr > front)
				{
					nowHavePriority = true;
					break;
				}

			}

			if (nowHavePriority == true)
			{
				priority.pop_front();
				priority.emplace_back(front);

				if (index == 0)
				{
					index = priority.size() - 1;
				}
				else
				{
					index--;
				}
			}
			else
			{
				priority.pop_front();
				backCount++;
				if (index == 0)
				{
					cout << backCount << '\n';
					break; // ���� ������ ���
				}
				else
				{
					index--;
				}
			}
		}
	}

	return 0;
}

list<int> split(string str, char Delimiter) {
	istringstream iss(str);             // istringstream�� str�� ��´�.
	string buffer;                      // �����ڸ� �������� ����� ���ڿ��� ������� ����

	list<int> result;

	// istringstream�� istream�� ��ӹ����Ƿ� getline�� ����� �� �ִ�.
	while (getline(iss, buffer, Delimiter)) {
		result.emplace_back(stoi(buffer));               // ����� ���ڿ��� vector�� ����
	}

	return result;
}