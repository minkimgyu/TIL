#include <iostream>
#include <vector>
using namespace std;

int arr[1024][1024];

int Loop(int XIndex, int YIndex, int size)
{
	if (size == 1) return arr[YIndex][XIndex];

	int half = size / 2;

	vector<int> vec;

	vec.push_back(Loop(XIndex, YIndex, half));
	vec.push_back(Loop(XIndex + half, YIndex, half));
	vec.push_back(Loop(XIndex, YIndex + half, half));
	vec.push_back(Loop(XIndex + half, YIndex + half, half));

	int biggest = -10000;
	int second = -10000;

	for (int i = 0; i < 4; i++)
	{
		if (vec[i] >= biggest)
		{
			second = biggest;
			biggest = vec[i];
		}
		else if (vec[i] > second)
		{
			second = vec[i];
		}
	}

	return second;
}

// ��͸� Ȱ���ϴ� ����
// size == 1�� ��, �ι�° ���� ã�� �κ��� �����ϰ� ����غ��°� �߿��� ��

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int size;
	cin >> size;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << Loop(0, 0, size);

	return 0;
}