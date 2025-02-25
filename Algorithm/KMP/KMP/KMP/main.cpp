#include <iostream>
#include <string>
using namespace std;

// a가 더 길다는 가정
bool find(string a, string b)
{
	int aSize = a.size();
	int bSize = b.size();

	for (int i = 0; i < aSize - bSize; i++)
	{
		bool isCorrect = true;

		for (int j = 0; j < bSize; j++)
		{
			if (a[i + j] != b[j])
			{
				isCorrect = false;
				break;
			}
		}

		if (isCorrect == true) return true;
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cout << find("abcdefg", "abd");

	return 0;
}