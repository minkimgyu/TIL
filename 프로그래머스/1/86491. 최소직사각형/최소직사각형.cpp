#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 명함을 돌려서 항상 가로가 더 길게 만들어준다.

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int maxWidth = 0;
    int maxHeight = 0;
    
    for(int i = 0; i < sizes.size(); i++)
    {
        int width = max(sizes[i][0], sizes[i][1]);
        int height = min(sizes[i][0], sizes[i][1]);
        
        if(maxWidth < width) maxWidth = width;
        if(maxHeight < height) maxHeight = height;
    }
    
    cout << maxWidth << " " << maxHeight;
    answer = maxWidth * maxHeight;
    
    return answer;
}