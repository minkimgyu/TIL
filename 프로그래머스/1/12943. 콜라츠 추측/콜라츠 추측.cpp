#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int num) {
    
    long long int mod = num;
    int answer = 0;
    
    while(mod != 1)
    {
        if(mod % 2 == 0)
        {
            mod /= 2;
        }
        else
        {
            mod = (mod * 3) + 1;
        }
        
        answer++;
        // cout << "answer: " << answer << " ";
        if(answer == 500)
        {
            answer = -1;
            break;
        }
    }
    
    return answer;
}