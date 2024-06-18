#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    sort(numbers.begin(), numbers.end());
    
    int numSize = numbers.size();
    answer = numbers[numSize - 1] *  numbers[numSize - 2];
    
    return answer;
}