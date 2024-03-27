#include <iostream>
#include <vector>
using namespace std;

void PrintLine(vector<const char*>arrs, int index, int count)
{
	count--;
	for (int i = 0; i < count * 4; i++) cout << "_";
	cout << arrs[index];
}

void Print(vector<const char*>arrs, int count, int maxCount)
{
	if (maxCount < count) return;

	int size = arrs.size();

	if (maxCount == count)
	{
		PrintLine(arrs, 0, count);
		cout << '\n';
		PrintLine(arrs, 4, count);
		cout << '\n';
	}
	else
	{
		for (int i = 0; i < size - 2; i++)
		{
			PrintLine(arrs, i, count);
			cout << '\n';
		}

		Print(arrs, count + 1, maxCount);
	}

	PrintLine(arrs, size - 1, count);

	if (count == 1) return;
	cout << '\n';
}

// 기본적인 재귀를 활용하는 문제
// 간단함

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << '\n';

	vector<const char*> arrs;

	arrs.push_back("\"재귀함수가 뭔가요?\"");
	arrs.push_back("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.");
	arrs.push_back("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.");
	arrs.push_back("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"");
	arrs.push_back("\"재귀함수는 자기 자신을 호출하는 함수라네\"");
	arrs.push_back("라고 답변하였지.");

	Print(arrs, 1, n + 1);

	return 0;
}