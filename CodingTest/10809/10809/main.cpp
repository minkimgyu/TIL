#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 이거는 개행 문자가 필요없음 --> 있으면 1개 더 검사해서 틀림
	const int alphaSize = 26;
	char alpha[alphaSize] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

	const int size = 101; 
	// 근데 여기는 개행문자가 필요함 --> 왜냐하면 if (s[j + 1] == '\0') break; 
	// 이런 식으로 비교하는 코드가 존재하는데 만약 문자 수가 100개면 넘쳐서 마지막 개행문자가 들어오지 못 함

	char s[size];
	cin >> s;

	for (int i = 0; i < alphaSize; i++)
	{
		int tmp = -1;
		for (int j = 0; j < size; j++)
		{
			if (alpha[i] == s[j])
			{
				tmp = j;
				break;
			}

			if (s[j + 1] == '\0') break;
		}

		if (i == alphaSize - 1) cout << tmp; // 마지막 단어인 경우
		else cout << tmp << " ";
	}

	return 0;
}