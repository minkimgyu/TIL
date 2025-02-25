#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    
    int xLength = 0;
    int yLength = 0;

    for(int i = 0; i < 4; i++)
    {
        int iX = dots[i][0];
        int iY = dots[i][1];
        for(int j = i + 1; j < 4; j++)
        {
            int jX = dots[j][0];
            int jY = dots[j][1];
            
            if(iX == jX) yLength = abs(iY - jY);
            if(iY == jY) xLength = abs(iX - jX);
        }
    }
    
    answer = xLength * yLength;
    
    return answer;
}