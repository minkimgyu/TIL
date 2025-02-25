#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for(int j = 1; j <= number; j++)
    {
        int count = 0;
        
        int sq = sqrt(j);
        for(int i = 1; i <= sq; i++)
        {
            if(j % i == 0) 
            {
                count += 2;
                
                if(j / i == i)
                {
                    count -= 1;
                }
            }
        }
        
        if(count > limit) count = power;
        answer += count;
    }
    
    return answer;
}