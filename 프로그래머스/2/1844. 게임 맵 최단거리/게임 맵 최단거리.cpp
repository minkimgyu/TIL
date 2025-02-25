#include<vector>
#include<queue>
#include<iostream>
using namespace std;

const int offsetSize = 4;
pair<int, int> offset[offsetSize] =
{
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1},
};

const int maxSize = 100;
int visit[maxSize][maxSize]; // r, c

int solution(vector<vector<int>> maps)
{
    int rowSize = maps.size();
    int columnSize = maps[0].size();
    
    int answer = 0;
    
    // 시작과 끝 지점이 이동 불가능한 경로인 경우 리턴
    if(maps[0][0] == 0 || maps[rowSize - 1][columnSize - 1] == 0) return -1;
    
    
    pair<int, int> start = {0, 0};
    queue<pair<int, int>> q;
    q.push(start);
    visit[start.first][start.second] = 1;
    
    while(q.empty() == false)
    {
        pair<int, int> front = q.front();
        q.pop();
        
        // cout << front.first << " " << front.second << "\n";
        int passNodeCount = visit[front.first][front.second];
        
        vector<pair<int, int>> closePoints;
        for(int i = 0; i < offsetSize; i++)
        {
            int r = front.first + offset[i].first;
            int c = front.second + offset[i].second;
            
            if(r < 0 || r >= rowSize || c < 0 || c >= columnSize) continue;
            if(visit[r][c] > 0) continue; // 이미 방문한 지점
            if(maps[r][c] == 0) continue; // 이동 불가능 지점
            
            closePoints.push_back({r, c});
        }
        
        for(int j = 0; j < closePoints.size(); j++)
        {
            // 끝 지점에 도달한 경우
            if(closePoints[j].first == rowSize - 1 && closePoints[j].second == columnSize - 1)
            {
                answer = passNodeCount + 1;
                return answer;
            }
            
            q.push(closePoints[j]);
            visit[closePoints[j].first][closePoints[j].second] = passNodeCount + 1;
        }
    }
    
    answer = -1;
    return answer;
}