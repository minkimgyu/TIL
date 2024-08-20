#include <string>
#include <vector>

using namespace std;

int ReturnModCount(int item)
{
    int result = 0;
    
    for(int i = 1; i <= item; i++)
    {
        if(item % i == 0) result += 1;
    }
    
    return result;
}

int solution(int left, int right) {
    int answer = 0;
    
    for(int i = left; i <= right; i++)
    {
        int modCount = ReturnModCount(i);
        if(modCount % 2 == 0)
        {
            answer += i;
        }
        else
        {
            answer -= i;
        }
    }
    
    return answer;
}