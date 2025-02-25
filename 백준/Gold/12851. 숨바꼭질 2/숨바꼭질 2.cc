#include <iostream>
using namespace std;
#include <queue>

queue<pair<int, int>> q;
bool visited[100001] = { false };
int n, k, cnt = 0;
int ans;

void bfs(int n, int t) {
	q.push({ n, t });
	while (!q.empty()) {
		int n = q.front().first;
		int t = q.front().second;
		q.pop();
		visited[n] = true;
		if (n == k) {
			if (cnt == 0) {
				ans = t;
				cnt++;
			}
			else if (cnt > 0 && ans == t)
				cnt++;
		}
		int go[3] = { n - 1, n + 1, 2 * n }; // 한 칸 앞, 한 칸 뒤, 두배 점프
		for (int i = 0; i < 3; i++) {
			int nx = go[i];
			if (0 <= nx && nx <= 100000 && !visited[nx]) {
				q.push({ nx, t + 1 });
			}
		}
	}
	return;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> k;
	if (n == k) {
		cout << '0' << '\n' << '1';
	}
	else {
		bfs(n, 0);
		cout << ans << '\n' << cnt;
	}
}