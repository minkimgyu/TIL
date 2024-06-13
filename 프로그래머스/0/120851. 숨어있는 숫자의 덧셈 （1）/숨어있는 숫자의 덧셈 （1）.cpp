#include <string>
#include <vector>

using namespace std;

int solution(string my_string) 
{
    int answer = 0;
    
    int my_stringSize = my_string.size();
    for(int i = 0; i < my_stringSize; i++)
    {
        if((int)my_string[i] >= 65) continue;
        
        answer += (int)my_string[i] - 48;
    }
    
    return answer;
}