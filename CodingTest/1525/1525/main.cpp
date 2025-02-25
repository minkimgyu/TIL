#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;

map<string, bool> visit;

const int lineSize = 9;
string arr;

// 엣지 케이스
// 1 2 3
// 4 5 6
// 7 8 0
// 으로 값이 주어진 경우 바로 0을 리턴해야한다.
// visit 배열에 true를 대입하기 때문에 아래 코드로는 바로 답이 입력으로 주어지면 찾을 수 없다.

// vector<vector<int>>는 메모리 초과가 난다 --> int 배열이나 string으로 바꿔보자
// int 배열은 안 됨
// 각 인덱스 별 offset을 만들어보자
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
	visit[arr] = true; // 방문 체크

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

				string newArr = front; // 새로 하나 만들어주기

				// 이후 swap 해주기
				newArr[offset[j]] = item;
				newArr[i] = nearItem;

				if (visit[newArr] == true) continue; // 이미 방문했다면 continue 시켜주기

				if (newArr == correctAnswer)
				{
					cout << loopCount + 1;
					return 0;
				}

				// 아니면 q에 넣어주기
				q.push({ newArr, loopCount + 1 });
				visit[newArr] = true;
			}
		}
	}

	cout << -1;
	return 0;
}