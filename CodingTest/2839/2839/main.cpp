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

	// i�� bigPocket, j�� smallPocket�� ������ ���
	// 
	// kg % bigPocket == 0�� ��� : i�� + 0��
	// kg % bigPocket == 1�� ��� : (i - 1)�� + 2��
	// kg % bigPocket == 2�� ��� : (i - 2)�� + 4��
	// kg % bigPocket == 3�� ��� : i�� + 1��
	// kg % bigPocket == 4�� ��� : (i - 1)�� + 3��

	int bigPocketArr[5] = { 0, 1, 2, 0, 1 };
	int smallPocketArr[5] = { 0, 2, 4, 1, 3 };

	int index = kg % bigPocketSize;

	int j = smallPocketArr[index];
	int i = (int)(kg / bigPocketSize) - bigPocketArr[index];

	// ���� i ���� 0���� �۴ٸ� -->  3�� 5�� �������� kg�� ������ ���� �Ұ�����
	if(i < 0) cout << -1;
	else cout << i + j;
	

	return 0;
}