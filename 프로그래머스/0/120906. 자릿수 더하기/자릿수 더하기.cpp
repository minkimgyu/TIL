#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int mod = 10;
    while(1)
    {
        if(mod > n)
        {
            answer += ((n % mod) - answer) / (mod / 10);
            break;
        }
        
        answer += ((n % mod) - answer) / (mod / 10);
        mod *= 10;
    }
    
    return answer;
}