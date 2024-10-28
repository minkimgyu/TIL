#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    pair<int, int> leftTop = {50, 50};
    pair<int, int> rightBottom = {0, 0};
    
    for(int i = 0; i < wallpaper.size(); i++)
    {
        for(int j = 0; j < wallpaper[i].size(); j++)
        {
            if(wallpaper[i][j] == '#')
            {
                leftTop.first = min(leftTop.first, i);
                leftTop.second = min(leftTop.second, j);
                
                rightBottom.first = max(rightBottom.first, i + 1);
                rightBottom.second = max(rightBottom.second, j + 1);
            }
        }
    }
    
    answer.push_back(leftTop.first);
    answer.push_back(leftTop.second);
    
    answer.push_back(rightBottom.first);
    answer.push_back(rightBottom.second);
    
    return answer;
}