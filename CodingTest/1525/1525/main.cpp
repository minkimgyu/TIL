#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;

map<string, bool> visit;

const int lineSize = 9;
string arr;

// ���� ���̽�
// 1 2 3
// 4 5 6
// 7 8 0
// ���� ���� �־��� ��� �ٷ� 0�� �����ؾ��Ѵ�.
// visit �迭�� true�� �����ϱ� ������ �Ʒ� �ڵ�δ� �ٷ� ���� �Է����� �־����� ã�� �� ����.

// vector<vector<int>>�� �޸� �ʰ��� ���� --> int �迭�̳� string���� �ٲ㺸��
// int �迭�� �� ��
// �� �ε��� �� offset�� ������
const int offsetSize = 9;
vector<int> offsets[offsetSize] =
{
	{1, 3},
	{0, 2, 4},
	{1, 5},
	{0, 4, 6},
	{1, 3, 5, 7},
	{2, 4, 8},
	{3, 7},
	{4, 6, 8},
	{5, 7}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int answerItem = 0;
	string correctAnswer = "123456780";

	for (int i = 0; i < lineSize; i++)
	{
		int item;
		cin >> item;
		arr.push_back(item + '0');
	}

	if (arr == correctAnswer)
	{
		cout << 0;
		return 0;
	}

	queue<pair<string, int>> q;
	q.push({ arr , 0 });
	visit[arr] = true; // �湮 üũ

	while (q.empty() == false)
	{
		string front = q.front().first;
		int loopCount = q.front().second;
		q.pop();

		for (int i = 0; i < lineSize; i++)
		{
			char item = front[i];
			vector<int> offset = offsets[i];
			for (int j = 0; j < offset.size(); j++)
			{
				char nearItem = front[offset[j]];
				if (nearItem != '0') continue;

				string newArr = front; // ���� �ϳ� ������ֱ�

				// ���� swap ���ֱ�
				newArr[offset[j]] = item;
				newArr[i] = nearItem;

				if (visit[newArr] == true) continue; // �̹� �湮�ߴٸ� continue �����ֱ�

				if (newArr == correctAnswer)
				{
					cout << loopCount + 1;
					return 0;
				}

				// �ƴϸ� q�� �־��ֱ�
				q.push({ newArr, loopCount + 1 });
				visit[newArr] = true;
			}
		}
	}

	cout << -1;
	return 0;
}