#include <iostream>
#include <string>
using namespace std;

const int alphaCount = 8;
string alpha[alphaCount] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;
	getline(cin, input);

	int result = input.size();

	for (int i = 0; i < alphaCount; i++)
	{
		int alphaSize = alpha[i].size();
		int index = 0;

		while (index < input.size() && input.find(alpha[i]) != string::npos)
		{
			index = input.find(alpha[i], index);
			input.erase(index, alphaSize); // erase --> index, count (지워지고 총 개수도 바뀜)
			input.insert(index, "A"); // index에 문자 삽입

			result -= alphaSize;
			result += 1;
			index += 1;
		}
	}

	cout << result;

	return 0;
}