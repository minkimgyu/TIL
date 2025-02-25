#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    int n = board.size();
    
    vector<pair<int, int>> offsets = 
    {{1, 0}, {-1, 0}, {0, 1}, {0, -1},
     {1, 1}, {-1, 1}, {1, -1}, {-1, -1},};
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == 1)
            {
                for(int k = 0; k < offsets.size(); k++)
                {
                    int y = i + offsets[k].second;
                    int x = j + offsets[k].first;
                    
                    if(x < 0 || y < 0 || x >= n || y >= n) continue;
                    if(board[y][x] == 1) continue;
                    
                    board[y][x] = 2;
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == 0) answer++;
        }
    }
    
    return answer;
}