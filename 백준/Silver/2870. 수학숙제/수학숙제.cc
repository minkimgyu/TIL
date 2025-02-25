#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> results;

	int n;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		string input;
		getline(cin, input);

		int start = -1;
		int end = -1;

		int inputSize = input.size();
		for (int j = 0; j < inputSize; j++)
		{
			if (inputSize == 1)
			{
				results.push_back(input);
			}
			else
			{
				if (48 <= input[j] && input[j] <= 57)
				{
					if (start == -1)
					{
						start = j; // 시작하는 인덱스를 넣어주기
					}
				}
				else
				{
					if (start != -1) // 시작하는 인덱스가 들어있고 숫자가 아닌 문자가 들어온 경우
					{
						string item = input.substr(start, j - start);
						results.push_back(item);

						start = -1;
						end = -1;
					}
				}
			}
		}

		if (start != -1)
		{
			string item = input.substr(start, inputSize - start);
			results.push_back(item);
		}
	}

	int resultSize = results.size();

	for (int i = 0; i < resultSize; i++)
	{
		while (results[i].size() > 1 && results[i][0] == '0')
		{
			results[i].erase(0, 1);
		}
	}

	for (int i = 0; i < resultSize - 1; i++)
	{
		for (int j = 0; j < resultSize - 1 - i; j++)
		{
			int output = results[j].compare(results[j + 1]);


			if ((output > 0 && results[j].size() == results[j + 1].size()) || results[j].size() > results[j + 1].size()) // swap
			{
				string tmp = results[j];
				results[j] = results[j + 1];
				results[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < resultSize; i++)
	{
		cout << results[i];
		if (i != resultSize - 1)
		{
			cout << '\n';
		}
	}

	return 0;
}