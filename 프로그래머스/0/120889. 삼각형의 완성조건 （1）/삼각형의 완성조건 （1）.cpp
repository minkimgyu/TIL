#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    
    int maxValue = -1;
    int maxIndex = -1;
    
    int sideSize = sides.size();
    for(int i = 0; i < sideSize; i++)
    {
        if(sides[i] > maxValue)
        {
            maxValue = sides[i];
            maxIndex = i;
        }
    }
    
    int othersSum = 0;
    
    for(int i = 0; i < sideSize; i++)
    {
        if(i == maxIndex) continue;
       
        othersSum += sides[i];
    }
    
    if(othersSum > maxValue)
    {
        answer = 1;
    }
    else
    {
        answer = 2;
    }
    
    return answer;
}