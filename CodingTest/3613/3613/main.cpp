#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string input;
	getline(cin, input);

	// ����ٷ� �����ϰ� �����ų� �� �� ���ڰ� �빮���� ���
	if (input[0] == '_' || input[input.size() - 1] == '_' || (65 <= input[0] && input[0] <= 90))
	{
		cout << "Error!";
		return 0;
	}

	bool isCStyle = input.find('_') != string::npos;
	if (isCStyle)
	{
		for (int i = 0; i < input.size(); i++)
		{
			char item = input[i];
			if (item >= 65 && item <= 90)
			{
				cout << "Error!"; // C++ ��Ÿ���ε� �빮�ڰ� ���� ���
				return 0;
			}

			if (item == '_')
			{
				if (65 <= input[i + 1] && input[i + 1] <= 90)
				{
					cout << "Error!"; // _ ������ �ٷ� �빮�ڰ� ���� ���
					return 0;
				}

				if (input[i + 1] == '_')
				{
					cout << "Error!"; // ����ٰ� 2�� ���ӵ� ���
					return 0;
				}

				int offset = 97 - 65;
				char nextAlpha = input[i + 1];
				nextAlpha = nextAlpha - offset;

				string nextItem;
				nextItem.push_back(nextAlpha);

				input.erase(i, 2);
				input.insert(i, nextItem);
			}
		}
	}
	else
	{
		int index = 0;

		for (int i = 0; i < input.size(); i++)
		{
			char item = input[i];
			if (65 <= item && item <= 90)
			{
				int offset = 97 - 65;
				item += offset;

				input[i] = item;
				input.insert(i, "_");
			}
		}
	}

	cout << input;

	return 0;
}