#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i = 1; i <= n; i++)
    {
        int item = i;
        int count = 0;
        for(int j = 1; j <= i; j++)
        {
            if(item % j == 0) count++;
        }
        
        if(count >= 3) answer++;
    }
    
    return answer;
}