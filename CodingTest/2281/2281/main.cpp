#include <iostream>
#include <cstring>//memset
#include <algorithm>//min
using namespace std;

int n, m;
int Name[1001];
int dp[1001][1001];

int DP(int name, int len) 
{//len은 뒤의 빈칸 포함한 길이
	if (name >= n)
		return 0;
	int& res = dp[name][len];
	//이미 구한 값이면
	if (res != -1) {
		return dp[name][len];
	}
	//한 칸 내려서 쓰는 경우
	res = (m - len + 1) * (m - len + 1) + DP(name + 1, Name[name] + 1);

	//같은 줄에 쓰는 경우
	if (len + Name[name] <= m)
		res = min(res, DP(name + 1, len + Name[name] + 1));
	return res;
}

int main() 
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> Name[i];
	}

	memset(dp, -1, sizeof(dp));
	cout << DP(0, 0) << '\n';
	return 0;
}