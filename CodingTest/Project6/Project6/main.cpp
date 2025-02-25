#include <vector>
#include <unordered_set>
#include <iostream>
#include <functional>
#include <queue>

using namespace std;

vector<int> nodeDistance(int s_nodes, int s_edges, vector<int> s_from, vector<int> s_to) {
    vector<vector<int>> graph(s_nodes);
    vector<bool> visited(s_nodes, false);
    vector<int> distance(s_nodes, -1);

    // 그래프 생성
    for (int i = 0; i < s_edges; ++i) {
        graph[s_from[i]].push_back(s_to[i]);
    }

    // 순환 구조 찾기 (DFS)
    function<bool(int, int)> findCycle = [&](int node, int parent) {
        visited[node] = true;
        for (int neighbor : graph[node]) {
            if (neighbor == parent) continue;
            if (visited[neighbor]) return true; // 순환 발견
            if (findCycle(neighbor, node)) return true;
        }
        visited[node] = false; // 방문 표시 해제
        return false;
    };

    // 임의의 노드에서 시작하여 순환 구조 찾기
    for (int i = 0; i < s_nodes; ++i) {
        if (!visited[i] && findCycle(i, -1)) break;
    }

    // 거리 계산 (BFS)
    queue<int> q;
    for (int node = 0; node < s_nodes; ++node) {
        if (visited[node]) {
            q.push(node);
            distance[node] = 0;
        }
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : graph[node]) {
            if (distance[neighbor] == -1) {
                distance[neighbor] = distance[node] +
                    1;
                q.push(neighbor);
            }
        }
    }

    return distance;
}


int main() {
    int s_nodes = 6;
    int s_edges = 6;
    vector<int> s_from = { 0, 1, 0, 2, 0, 1 };
    vector<int> s_to = { 1, 2, 2, 4, 3, 5 };

    vector<int> result = nodeDistance(s_nodes, s_edges, s_from, s_to);

    // 결과 출력
    for (int dist : result) {
        cout << dist << " ";
    }
    cout << endl;

    return 0;
}