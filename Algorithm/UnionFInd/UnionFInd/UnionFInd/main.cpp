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

	if (p[uParent] > p[vParent]) swap(uParent, vParent); // v�� ��ũ�� �� ū ��� �ٲ��ش�.

	// ���� ������ uParent�� ��ũ�� v�� ��ũ���� ���ų� ũ��.

	if (p[uParent] == p[vParent]) p[uParent]--; // ���� u�� v�� ��ũ�� ���ٸ� u�� ��ũ�� ������Ų��.
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