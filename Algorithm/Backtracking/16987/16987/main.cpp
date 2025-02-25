#include <iostream>
#include <algorithm>
using namespace std;

const int maxSize = 8 + 5;

// 내구도, 무게
pair<int, int> egg[maxSize];

int result = 0;
int n;
int successCount = 0;

void dfs(int currentEggIndex)
{
	// 현재 인덱스가 마지막 인덱스를 넘는다면 return;
	// 현재 인덱스의 계란이 이미 부서진 경우
	if (currentEggIndex == n) 
	{
		result = max(result, successCount); // 마지막으로 개수 업데이트 필요
		return;
	}

	if (egg[currentEggIndex].first <= 0 || successCount == n - 1) // 손에 든 계란이 깨졌거나 깨지지 않은 다른 계란이 없으면 치지 않고 넘어간다.
	{
		dfs(currentEggIndex + 1); // 만약 현재 계란이 깨져있는 경우 다음 계란을 선택한다.
		return; // 리턴 꼭 필요
	}

	for (int i = 0; i < n; i++)
	{
		if (i == currentEggIndex || egg[i].first <= 0) continue; // 같은 계란은 무시, 만약 계란이 부서졌다면 continue;

		egg[i].first -= egg[currentEggIndex].second; // 들고 있는 계란의 무게로 내구도 감소시키기
		egg[currentEggIndex].first -= egg[i].second; // 맞은 계란의 무게로 들고 있는 계란 내구도 감소시키기

		if (egg[currentEggIndex].first <= 0) successCount++;
		if (egg[i].first <= 0) successCount++;

		dfs(currentEggIndex + 1);

		if (egg[currentEggIndex].first <= 0) successCount--;
		if (egg[i].first <= 0) successCount--;

		egg[i].first += egg[currentEggIndex].second; // 백트래킹으로 데이터 다시 복구 필요
		egg[currentEggIndex].first += egg[i].second;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int s, w;
		cin >> s >> w;

		egg[i].first = s;
		egg[i].second = w;
	}
	
	dfs(0);

	cout << result;
	return 0;
}