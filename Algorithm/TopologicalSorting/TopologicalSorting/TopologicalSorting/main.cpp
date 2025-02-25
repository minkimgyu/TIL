#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxSize = 10;
vector<int> adj[maxSize]; // 근접한 정점 정리
int indeg[maxSize]; // indegree 정리

int n;

queue<int> qu;
vector<int> result;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	// 우선 indeg가 0인 것을 queue에 넣어준다.
	for (int i = 1; i <= n; i++)
	{
		if (indeg[i] == 0) qu.push(i);
	}

	// while문 안에서 모든 정점을 계산해준다. 
	// --> while문은 최대 정점 개수만큼 돌아가고 내부의 for문은 최대 간선 개수 만큼만 돌아가기 때문에 시간복잡도는 O(V + E)다.
	while (qu.empty() == false)
	{
		int front = qu.front(); qu.pop();
		result.push_back(front);

		for (int nxt : adj[front])
		{
			indeg[nxt] -= 1;
			if(indeg[nxt] == 0) qu.push(nxt);
		}
	}

	if (result.size() != n) cout << "사이클이 존재함";
	else 
	{
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i];
			if (i != result.size() - 1) cout << " ";
		}
	}

	return 0;
}