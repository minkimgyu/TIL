#include <iostream>
#include <unordered_map>
using namespace std;

long long int n;
int p, q;
unordered_map<long long int, long long int> map1;

long long int dfs(long long int n)
{
	if (map1.find(n) != map1.end()) return map1[n];

	long long int left = n / p;
	long long int right = n / q;

	map1[n] = dfs(left) + dfs(right);
	return map1[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map1[0] = 1;
	cin >> n >> p >> q;

	cout << dfs(n);
	return 0;
}