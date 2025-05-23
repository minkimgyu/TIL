#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s1, s2;
	cin >> s1 >> s2;

	int s2Size = s2.size();
	int s2Index = 0;
	int s2Count = 0;

	int result = 0;

	while (s2Index < s2Size)
	{
		string newS2 = s2.substr(s2Index, s2Count + 1);
		if (s1.find(newS2) == string::npos) // 못 찾은 경우
		{
			// s1Count 값을 기준으로 s2Count 올려주기
			s2Index += s2Count;
			result++;
			s2Count = 0;
		}
		else
		{
			s2Count++;
			if (s2Index + s2Count == s2Size) // 끝에 도달한 경우
			{
				result++;
				break;
			}
		}
	}

	cout << result;
	return 0;
}