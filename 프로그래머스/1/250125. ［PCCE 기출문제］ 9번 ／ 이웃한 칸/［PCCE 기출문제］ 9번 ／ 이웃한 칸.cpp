#include <string>
#include <vector>

using namespace std;

pair<int, int> offsets[4] =
{
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1},
};

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    string currentColor = board[h][w];
    for(int i = 0; i < 4; i++)
    {
        pair<int, int> offset = offsets[i];
        
        int r = h + offset.first;
        int c = w + offset.second;
        
        int maxR = board.size();
        int maxC = board[0].size();
        if(r < 0 || r >= maxR || c < 0 || c >= maxC) continue;
        
        string closeColor = board[r][c];
        if(currentColor == closeColor)
        {
            answer++;
        }
    }
    
    return answer;
}