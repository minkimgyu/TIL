#include <iostream>
#include <vector>
using namespace std;

vector<int> p(11, -1);

//int find(int x)
//{
//	while (p[x] != -1)
//	{
//		x = p[x];
//	}
//
//	return x;
//}

int find(int x)
{
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool uni(int u, int v)
{
	int uParent = find(u);
	int vParent = find(v);

	if (uParent == vParent) return false;

	p[vParent] = uParent;
	return true;
}

bool uniByRank(int u, int v)
{
	int uParent = find(u);
	int vParent = find(v);

	if (uParent == vParent) return false;

	if (p[uParent] > p[vParent]) swap(uParent, vParent); // v의 랭크가 더 큰 경우 바꿔준다.

	// 이제 무조건 uParent의 랭크가 v의 랭크보다 같거나 크다.

	if (p[uParent] == p[vParent]) p[uParent]--; // 만약 u와 v의 랭크가 같다면 u의 랭크를 증가시킨다.
	p[vParent] = uParent;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	return 0;
}