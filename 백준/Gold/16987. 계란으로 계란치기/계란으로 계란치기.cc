#include <iostream>

using namespace std;

int N; // 계란 개수
int sArr[10]; // 내구도 배열
int wArr[10]; // 무게 배열
int ans; // 최대로 깰 수 있는 계란 수 
int cnt; // 현재 깨져있는 계란의 수

void func(int curEgg) {
	if (curEgg == N + 1) {
		ans = max(ans, cnt);
		return;
	}

	if (sArr[curEgg] <= 0 || cnt == N - 1) {
		func(curEgg + 1);
		return;
	}

	for (int nextEgg = 1; nextEgg <= N; nextEgg++) {
		if (nextEgg == curEgg || sArr[nextEgg] <= 0) continue;

		sArr[curEgg] -= wArr[nextEgg];
		sArr[nextEgg] -= wArr[curEgg];
		if (sArr[curEgg] <= 0) cnt++;
		if (sArr[nextEgg] <= 0) cnt++;

		func(curEgg + 1);

		if (sArr[curEgg] <= 0) cnt--;
		if (sArr[nextEgg] <= 0) cnt--;
		sArr[curEgg] += wArr[nextEgg];
		sArr[nextEgg] += wArr[curEgg];
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> sArr[i] >> wArr[i];
	}

	func(1);

	cout << ans;

	return 0;
}