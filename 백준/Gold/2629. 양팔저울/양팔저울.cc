#include <iostream>
using namespace std;

const int maxWeightCount = 30 + 5;
int weightValue[maxWeightCount];

const int maxBeadWeight = 15005;
bool dp[maxWeightCount][maxBeadWeight];

int n;

void dfs(int weightCount, int beadWeight)
{
	if (weightCount > n || dp[weightCount][beadWeight] == true) return; // n보다 크면 리턴

	dp[weightCount][beadWeight] = true;
	dfs(weightCount + 1, beadWeight + weightValue[weightCount]); // 왼쪽에 넣는 경우
	dfs(weightCount + 1, abs(beadWeight - weightValue[weightCount])) ; // 오른쪽에 넣는 경우
	dfs(weightCount + 1, beadWeight); // 둘 다 넣지 않는 경우
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int weight;
		cin >> weight;

		weightValue[i] = weight;
	}

	int m;
	cin >> m;

	dfs(0, 0);

	for (int i = 0; i < m; i++)
	{
		int beadWeight;
		cin >> beadWeight;

		if (dp[n][beadWeight] == true) cout << "Y";
		else cout << "N";
		
		if (i != m - 1) cout << " ";
	}

	return 0;
}