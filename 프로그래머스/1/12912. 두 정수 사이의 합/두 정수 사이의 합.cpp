#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    int maxValue = max(a, b);
    int minValue = min(a, b);
    
    for(int i = minValue; i <= maxValue; i++)
    {
        answer += i;
    }
    return answer;
}