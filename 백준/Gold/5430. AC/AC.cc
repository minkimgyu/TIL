#include <iostream>
#include <deque>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	cin.ignore();

	for (int i = 0; i < t; i++)
	{
		string line;
		getline(cin, line);

		int num;
		cin >> num;
		cin.ignore();

		string arrLine;
		getline(cin, arrLine);

		int dCount = 0;
		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] == 'D') dCount++;
		}

		if (dCount > num)
		{
			cout << "error";
			if (i != t - 1) cout << '\n';
			continue;
		}

		deque<int> dQ;
		bool isFrontSide = true;

		string newArrLine;
		for (int j = 0; j < arrLine.size(); j++)
		{
			if (j == 0 || j == arrLine.size() - 1) continue;
			newArrLine.push_back(arrLine[j]);
		}

		stringstream ss(newArrLine);
		char delimiter = ',';
		string token;

		while (getline(ss, token, delimiter))
		{
			dQ.push_back(stoi(token));
		}

		for (int j = 0; j < line.size(); j++)
		{
			if (line[j] == 'R')
			{
				isFrontSide = !isFrontSide;
			}
			else if (line[j] == 'D')
			{
				if (isFrontSide == true)
				{
					dQ.pop_front();
				}
				else
				{
					dQ.pop_back();
				}
			}
		}

		string output;
		output.push_back('[');

		while (dQ.empty() == false)
		{
			if (isFrontSide == true)
			{
				string itos = to_string(dQ.front());
				for (int k = 0; k < itos.size(); k++)
				{
					output.push_back(itos[k]);
				}
				
				dQ.pop_front();
			}
			else
			{
				string itos = to_string(dQ.back());
				for (int k = 0; k < itos.size(); k++)
				{
					output.push_back(itos[k]);
				}
				dQ.pop_back();
			}

			if(dQ.empty() == false) output.push_back(',');
		}

		output.push_back(']');
		cout << output;
		if (i != t - 1) cout << '\n';
	}

	return 0;
}