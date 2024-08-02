#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    // 가장 왼쪽 가장 오른쪽 가장 위쪽 가장 아래쪽 좌표를 구하자
    
    int minRow = 51;
    int minCol = 51;
    
    int maxRow = -1;
    int maxCol = -1;

    
    for(int r = 0; r < wallpaper.size(); r++)
    {
        for(int c = 0; c < wallpaper[r].size(); c++)
        {
            char item = wallpaper[r][c];
            if(item == '#')
            {
                if(minRow > r) minRow = r;
                if(minCol > c) minCol = c;
                
                if(maxRow < r + 1) maxRow = r + 1;
                if(maxCol < c + 1) maxCol = c + 1;
            }
        }
    }
    
    answer.push_back(minRow);
    answer.push_back(minCol);
    
    answer.push_back(maxRow);
    answer.push_back(maxCol);
    
    return answer;
}