#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int kg;
	int smallPocketSize = 3;
	int bigPocketSize = 5;

	int smallPocketCount = 0;
	int bigPocketCount = 0;

	cin >> kg;

	// i가 bigPocket, j가 smallPocket의 개수인 경우
	// 
	// kg % bigPocket == 0인 경우 : i개 + 0개
	// kg % bigPocket == 1인 경우 : (i - 1)개 + 2개
	// kg % bigPocket == 2인 경우 : (i - 2)개 + 4개
	// kg % bigPocket == 3인 경우 : i개 + 1개
	// kg % bigPocket == 4인 경우 : (i - 1)개 + 3개

	int bigPocketArr[5] = { 0, 1, 2, 0, 1 };
	int smallPocketArr[5] = { 0, 2, 4, 1, 3 };

	int index = kg % bigPocketSize;

	int j = smallPocketArr[kg % bigPocketSize];
	int i = (int)(kg / bigPocketSize) - bigPocketArr[index];

	if(i < 0) cout << -1;
	else cout << i + j;
	

	return 0;
}