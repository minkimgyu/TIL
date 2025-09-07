#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int pc[10000 + 5];
vector<pair<int ,int>> connections[100000 + 5];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQ;

const int maxCost = 1000 * 10000 + 5;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int k = 0; k < t; k++)
	{
		int n, d, c;
		cin >> n >> d >> c;

		// connections 초기화
		// 최대로 코스트 설정해주기
		for (int i = 1; i <= n; i++)
		{
			pc[i] = maxCost;
			connections[i].clear();
		}

		for (int i = 0; i < d; i++)
		{
			int a, b, s;
			cin >> a >> b >> s;
			connections[b].push_back({ s, a });
		}

		pQ.push({ 0, c });
		pc[c] = 0;

		while (pQ.empty() == false)
		{
			pair<int, int> top = pQ.top();
			pQ.pop();

			int cost = top.first;
			int currentIndex = top.second;

			//cout << cost << " " << currentIndex << " \n\n";

			for (int i = 0; i < connections[currentIndex].size(); i++)
			{
				int nxtCost = cost + connections[currentIndex][i].first; // 다음 정점으로 이동 시 코스트
				int nxtIdx = connections[currentIndex][i].second;

				//cout << nxtCost << " " << nxtIdx << " \n\n";

				// 만약 기존 코스트 보다 작은 경우 업데이트
				if (pc[nxtIdx] > nxtCost)
				{
					pc[nxtIdx] = nxtCost;
					pQ.push({ nxtCost, nxtIdx });
				}
			}
		}

		int passPcCount = 0;
		int result = 0;

		// 최대 코스트 탐색
		for (int i = 1; i <= n; i++)
		{
			if (pc[i] == maxCost)
			{
				passPcCount++; // 탐색 안 된 pc
			}
			else // 최대 코스트가 아닌 경우만 max 선택
			{
				result = max(result, pc[i]);
			}
		}

		cout << n - passPcCount << " " << result;
		if (k != t - 1) cout << '\n';
	}

	return 0;
}