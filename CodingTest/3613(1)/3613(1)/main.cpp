#include <iostream>
#include <string>
using namespace std;

// 맨 앞 _
// 맨 뒤 _
// _ 대문자 혼합
// _ 바로 뒤에 대문자 존재
// 대문자 한 글자 --> 소문자 한 글자는 괜찮음

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;
	getline(cin, input);

	//  맨 앞 _, 맨 뒤 _, 대문자 한 글자
	if (input[0] == '_' || input[input.size() - 1] == '_' || (65 <= input[0] && input[0] <= 90)) 
	{
		cout << "Error!";
		return 0;
	}

	bool isCType = input.find('_') != string::npos;

	if (isCType)
	{
		for (int i = 0; i < input.size(); i++)
		{
			if (65 <= input[i] && input[i] <= 90) // _, 대문자 혼합
			{
				cout << "Error!";
				return 0;
			}
		}

		int index = 0;
		while (index < input.size() && input.find('_') != string::npos)
		{
			// _ 바로 뒤에 대문자 존재

			index = input.find('_', index);
			char backAlpha = input[index + 1];

			if (backAlpha == '_')
			{
				cout << "Error!";
				return 0;
			}

			if (65 <= backAlpha && backAlpha <= 90)
			{
				cout << "Error!";
				return 0;
			}

			char changeAlpha = input[index + 1] - (97 - 65);
			input.erase(index, 2);

			string insertAlpha;
			insertAlpha.push_back(changeAlpha);
			input.insert(index, insertAlpha);

			index += 1;
		}
	}
	else
	{
		for (int i = 0; i < input.size(); i++)
		{
			if (65 <= input[i] && input[i] <= 90)
			{
				char alpha = input[i];
				input.erase(i, 1);

				string insertString;
				insertString.push_back(alpha + (97 - 65));

				input.insert(i, "_");
				input.insert(i + 1, insertString);
			}
		}
	}

	cout << input;

	return 0;
}