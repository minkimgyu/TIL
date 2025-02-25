#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> numbers, int k) {
    int answer = 0;
    
    int numberSize = numbers.size();

    for(int i = 0; i < k - 1; i++)
    {
        answer += 2;
        answer %= numberSize;
        cout << answer;
    }
    
    return numbers[answer];
}