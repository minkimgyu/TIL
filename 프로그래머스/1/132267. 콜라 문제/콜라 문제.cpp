#include <string>
#include <vector>

using namespace std;

int recur(int a, int b, int count)
{
    if (count < a) return 0;
    
    int divide = count / a;
    int mod = count % a;
    
    int getBottleCount = divide * b;
    
    return getBottleCount + recur(a, b, getBottleCount + mod);
}

int solution(int a, int b, int n) {
    int answer = 0;
    
    answer = recur(a, b, n);
    
    return answer;
}