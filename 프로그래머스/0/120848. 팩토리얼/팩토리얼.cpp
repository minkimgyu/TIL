#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int fac = 1;
    int index = 1;
    while(1)
    {
        fac *= index;
        
        if(fac > n)
        {
            index -= 1;
            answer = index;
            break;
        }
        
        index++;
    }
    
    return answer;
}