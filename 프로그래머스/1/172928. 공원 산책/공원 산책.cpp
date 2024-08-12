#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    int maxRowCount = park.size();
    int maxColumnCount = park[0].size();
    pair<int, int> pos;
    
    bool findStartPos = false;
    for(int i = 0; i < maxRowCount; i++)
    {
        for(int j = 0; j < maxColumnCount; j++)
        {
            if(park[i][j] == 'S')
            {
                pos = {i, j};
                findStartPos = true;
                break;
            }
        }
        
        if(findStartPos == true) break;
    }
    
    
    for(int i = 0; i < routes.size(); i++)
    {
        char way = routes[i][0];
        int point = routes[i][2] - 48;

        bool canMove = true;
        pair<int, int> newPos = pos;
        for(int j = 0; j < point; j++)
        {
            switch(way)
            {
                case 'E':
                    newPos.second += 1;
                    break;
                case 'W':
                    newPos.second -= 1;
                    break;
                case 'N':
                    newPos.first -= 1;
                    break;
                case 'S':
                    newPos.first += 1;
                    break;
            }
            
            // 위 명령을 수행하면서 만약 범위를 벗어나거나 장애물에 막힌다면 break 해주고 원래 위치로 돌려줌
            
            if(newPos.first < 0 || newPos.first >= maxRowCount || newPos.second < 0 || newPos.second >= maxColumnCount) 
            {
                canMove = false;
                break;
            }
            
            if(park[newPos.first][newPos.second] == 'X') 
            {
                canMove = false;
                break;
            }
        }
        
        if(canMove == true)
        {
            pos = newPos;
        }
    }
    
    answer.push_back(pos.first);
    answer.push_back(pos.second);
    
    return answer;
}