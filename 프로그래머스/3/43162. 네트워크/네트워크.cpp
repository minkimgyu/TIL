#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

const int linkSize = 200;
int link[linkSize][linkSize];
bool visit[linkSize];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < computers.size(); i++)
    {
        for(int j = 0; j < computers[i].size(); j++)
        {
            link[i][j] = computers[i][j];
        }
    }
    
    // bfs 돌려서 방문한 노드는 visit = true로 바꿔준다.
    queue<int> q;
    for(int i = 0; i < n; i++)
    {
        if(visit[i] == true) continue;
        answer++;
        
        // cout << i << " ";
        q.push(i);
        visit[i] = true;
        
        while(q.empty() == false)
        {
            int front = q.front();
            q.pop();
            
            vector<int> closeComputers;
            for(int j = 0; j < n; j++)
            {
                if(link[front][j] == true) // 연결이 있는 경우
                {
                    closeComputers.push_back(j);
                }
            }
            
            for(int k = 0; k < closeComputers.size(); k++)
            {
                int closeComputer = closeComputers[k];
                if(visit[closeComputer] == true) continue;
                
                q.push(closeComputer);
                visit[closeComputer] = true;
            }
        }
    }
    
    return answer;
}