#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int n;
string pattern;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin.ignore();

	getline(cin, pattern);

	istringstream ss(pattern);
	string part;
	vector<string> parts;

	while (getline(ss, part, '*'))
	{
		parts.push_back(part);
	}

	for (int i = 0; i < n; i++)
	{
		string input;
		getline(cin, input);

		if (input.size() < parts[0].size() + parts[1].size())
		{
			cout << "NE";
			if (i != n - 1) cout << '\n';
			continue;
		}

		int inputSize = input.size();
		int part1Size = parts[1].size();

		int checkFront = input.find(parts[0]);
		int checkEnd = input.find(parts[1], inputSize - part1Size);

		if (checkFront == 0 && checkEnd == inputSize - part1Size)
		{
			cout << "DA";
		}
		else
		{
			cout << "NE";
		}

		if(i != n - 1) cout << '\n';
	}

	return 0;
}