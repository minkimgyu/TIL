#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int start, end;
	cin >> start >> end;

	vector<int> list;
	vector<bool> visit(end + 1, true);

	// 중요!
	visit[1] = false;
	visit[2] = true;
	// 문제의 범위가 1이상이라서 1, 2도 체크해야 한다.

	for (int i = 2; i * i <= end; i++)
	{
		if (visit[i] == false) continue;
		for (int j = i * i; j <= end; j += i) // i의 배수이므로 i씩 더해줘야함
		{
			visit[j] = false;
		}
	}

	for (int i = start; i <= end; i++)
	{
		if (visit[i] == true)
		{
			cout << i << '\n';
		}
	}

	return 0;
}