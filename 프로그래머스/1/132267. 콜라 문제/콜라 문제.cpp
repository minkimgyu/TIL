#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 2 -> 1
int recursive(int a, int b, int n)
{
    // n이 a보다 작은 경우 더 이상 나눠질 수 없음
    if(n < a) return 0;
    
    int convertCount = (n / a) * b;
    int leftCount = n % a; // 나머지 개수
    
    return convertCount + recursive(a, b, convertCount + leftCount);
}

int solution(int a, int b, int n) {
    int answer = 0;
    
    answer = recursive(a, b, n);
    return answer;
}