#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    answer = 1;
    
    while(1)
    {
        int multi = (6 * answer) % n;
        if(multi > 0) answer += 1;
        else break;
    }
    
    return answer;
}