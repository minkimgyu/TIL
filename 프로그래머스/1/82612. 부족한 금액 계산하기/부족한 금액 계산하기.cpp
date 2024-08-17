using namespace std;
#include <iostream>

long long solution(int price, int money, int count)
{
    long long answer = -1;

    long long int sum = 0;
    long long int result = 0;
    
    for(int i = 1; i <= count; i++)
    {
        sum = price * i;
        result += sum;
        cout << result << " ";
    }
    
    answer = result - money;
    if(answer < 0) answer = 0;
    
    return answer;
}