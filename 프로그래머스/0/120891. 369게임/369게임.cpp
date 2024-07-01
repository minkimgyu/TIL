#include <string>
#include <vector>

using namespace std;

int solution(int order) {
    int answer = 0;
    
    int mod = 10;
    int sum = 0;
    
    while(1)
    {
        if(mod > order)
        {
            int addTo = (order % mod) - sum;
            sum += addTo;

            int num = addTo / (mod / 10);
            if(num == 3 || num == 6 || num == 9) answer += 1;
            break;
        }
        
        int addTo = (order % mod) - sum;
        sum += addTo;

        int num = addTo / (mod / 10);
        if(num == 3 || num == 6 || num == 9) answer += 1;

        mod *= 10;
    }
    
    return answer;
}