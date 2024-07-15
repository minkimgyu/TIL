#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    
    int item1 = numer1 * denom2;
    int item2 = numer2 * denom1;
    
    int up = item1 + item2;
    int down = denom1 * denom2;
    
    while(1)
    {
        bool canDivide = false;
        
        for(int i = 2; i < 1000; i++)
        {
            if((i <= up && i <= down) && (up % i == 0 && down % i == 0))
            {
                up /= i;
                down /= i;
                canDivide = true;
                break;
            }
        }
        
        if(canDivide == false) break;
    }
    
    answer.push_back(up);
    answer.push_back(down);
    
    return answer;
}