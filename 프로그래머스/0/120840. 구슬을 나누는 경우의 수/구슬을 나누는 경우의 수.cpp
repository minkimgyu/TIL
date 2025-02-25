#include <string>
#include <vector>

using namespace std;

// 5 c 2
// 5 c 3

int solution(int balls, int share) {
    float divid = (float)balls / 2.0f;
    if(share > divid) share = balls - share;
    
    __int128 answer = 0;
    
    __int128 totalBalls = 1;
    for(int i = 1; i <= balls; i++) 
        totalBalls *= i;
    
    __int128 totalShare = 1;
    for(int i = 1; i <= share; i++) 
        totalShare *= i;
    
    __int128 totalMinus = 1;
    for(int i = 1; i <= balls - share; i++) 
        totalMinus *= i;
    
    answer = totalBalls / (totalMinus * totalShare);
    
    return answer;
}