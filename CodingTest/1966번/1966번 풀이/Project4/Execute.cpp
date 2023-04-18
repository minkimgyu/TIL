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
					break; // 루프 끝내고 출력
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
	istringstream iss(str);             // istringstream에 str을 담는다.
	string buffer;                      // 구분자를 기준으로 절삭된 문자열이 담겨지는 버퍼

	list<int> result;

	// istringstream은 istream을 상속받으므로 getline을 사용할 수 있다.
	while (getline(iss, buffer, Delimiter)) {
		result.emplace_back(stoi(buffer));               // 절삭된 문자열을 vector에 저장
	}

	return result;
}