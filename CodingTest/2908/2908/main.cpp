#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	const int size = 4;

	char a[size]; // 마지막 '\0' 받아야해서 4로 지정
	char b[size];

	cin >> a;
	cin >> b;

	char tmp = a[0];
	a[0] = a[2];
	a[2] = tmp;

	char tmp1 = b[0];
	b[0] = b[2];
	b[2] = tmp1;

	int aToInt = atoi(a); // 문자열을 정수로 변환해준다.
	int bToInt = atoi(b);

	if (aToInt > bToInt) cout << aToInt;
	else cout << bToInt;

	return 0;
}