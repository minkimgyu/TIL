#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    int answer = 0;
    
    int mod = 10;
    int sum = 0;
    int index = 1;
    
    while(1)
    {
        if(mod > num)
        {
            int addTo = num % mod - sum;
            sum += addTo;

            int result = addTo / (mod / 10);
            if(result == k) answer = index;
            break;
        }
        
        int addTo = num % mod - sum;
        sum += addTo;
        
        int result = addTo / (mod / 10);
        if(result == k) answer = index;
        
        index++;
        mod *= 10;
    }
    
    if(answer == 0)
    {
        answer = -1;
    }
    else
    {
        answer = index - answer + 1;
    }
    
    return answer;
}