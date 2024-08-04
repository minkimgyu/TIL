#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int maxWidth = 0;
    int maxHeight = 0;
    
    int widthSize = sizes.size();
    for(int i = 0; i < widthSize; i++)
    {
        if(sizes[i][0] < sizes[i][1])
        {
            int width = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = width;
        }
        
        if(maxWidth < sizes[i][0]) maxWidth = sizes[i][0];
        if(maxHeight < sizes[i][1]) maxHeight = sizes[i][1];
    }
    
    answer = maxWidth * maxHeight;
    
    return answer;
}