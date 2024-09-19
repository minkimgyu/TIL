#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

// dfs 문제
// 탐색에 우선순위를 두고 방문해야한다.
// vector<string, pQ> 이런 식으로 해도 되고 정렬을 사용해도 될 것 같다.

// 항상 ICN에서 출발한다.
// 중복되는 표를 가질 수 있다. 즉 경로가 같은 경우가 여러개 일 수 있다.

// ICN ATL SFO

map<string, vector<string>> paths;
map<pair<string, string>, int> visit;

bool compare(string a, string b)
{
    return a.compare(b) < 0;
}

int maxVisitCount = 0;

bool isClear = false;
vector<string> answer;

vector<string> result;

void dfs(string start, int loopCount)
{
    // cout << start << " " << loopCount << " " << maxVisitCount << " ";
    if(isClear == true) return;
    
    answer.push_back(start);
    if(maxVisitCount == loopCount)
    {
        result = answer;
        isClear = true;
        return;
    }
    
    vector<string> path = paths[start];
    for(int i = 0; i < path.size(); i++)
    {
        if(visit[{start, path[i]}] <= 0) continue;
        
        visit[{start, path[i]}] -= 1;
        
        dfs(path[i], loopCount + 1);
        if(isClear == true) return;
        
        answer.pop_back(); // 뒤에 넣었던 것을 다시 빼준다.
        visit[{start, path[i]}] += 1;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    for(int i = 0; i < tickets.size(); i++)
    {
        paths[tickets[i][0]].push_back(tickets[i][1]);
        
        visit[{tickets[i][0], tickets[i][1]}] += 1; // 1만큼 더해준다.
    }
    
    for(auto it = paths.begin(); it != paths.end(); it++)
    {
        sort(it->second.begin(), it->second.end(), compare);
    }
    
    maxVisitCount = tickets.size(); // 티켓의 개수
    
    dfs("ICN", 0);
    return result;
}