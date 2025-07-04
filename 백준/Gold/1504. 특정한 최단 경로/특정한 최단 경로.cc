#include <iostream>
#include <queue>
using namespace std;

const int maxSize = 800 + 5;
int paths[maxSize][maxSize];

int n, e;

const int maxWeight = 800005 * 3;

int findMinWeight(int start, int end)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQ; // weight, index
	int weights[maxSize];
	for (int i = 1; i <= n; i++) weights[i] = maxWeight;

	pQ.push({ 0, start });
	weights[start] = 0;

	while (pQ.empty() == false)
	{
		pair<int, int> top = pQ.top(); pQ.pop();

		for (int i = 1; i <= n; i++)
		{
			if (paths[top.second][i] == 0) continue;

			if (top.first + paths[top.second][i] < weights[i])
			{
				weights[i] = top.first + paths[top.second][i];
				pQ.push({ weights[i], i });
			}
		}
	}

	return weights[end];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> e;

	for (int i = 0; i < e; i++)
	{
		int start, end, value;
		cin >> start >> end >> value;
		paths[start][end] = value;
		paths[end][start] = value;
	}

	int v1, v2;
	cin >> v1 >> v2;

	// start -> v1 -> v2 -> end
	// start -> v2 -> v1 -> end

	// v1 -> v2는 같으므로

	// 이렇게 5개만 구하면 된다.

	// v1 -> v2
	// start -> v1
	// start -> v2
	// v1 -> end
	// v2 -> end

	int betweenV1ToV2 = findMinWeight(v1, v2);

	int startTov1 = findMinWeight(1, v1);
	int startTov2 = findMinWeight(1, v2);

	int v1ToN = findMinWeight(v1, n);
	int v2ToN = findMinWeight(v2, n);

	int first = startTov1 + betweenV1ToV2 + v2ToN;
	int second = startTov2 + betweenV1ToV2 + v1ToN;

	int result = min(first, second);
	if (result >= maxWeight) cout << -1; // 경로가 없는 경우
	else cout << result;

	return 0;
}