#include <iostream>
#include <map>
#include <vector>
using namespace std;

// map�� ��� key�� ���� ������
struct compare {
	bool operator() (string a, string b) const {
		// ������ �ϳ� ���� �߻� ����. �ڼ��� ������ �ؿ� �����
		return a.compare(b) > 0;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> names;
	map<string, bool, compare> checkEnter;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string name, isEnter;
		cin >> name >> isEnter;

		if (isEnter == "enter")
		{
			checkEnter[name] = true;
		}
		else if (isEnter == "leave")
		{
			checkEnter[name] = false;
		}
	}

	for (auto it = checkEnter.begin(); it != checkEnter.end(); it++)
	{
		if (it->second == true)
		{
			cout << it->first;
			if (it != --checkEnter.end()) cout << '\n';
		}
	}

	return 0;
}