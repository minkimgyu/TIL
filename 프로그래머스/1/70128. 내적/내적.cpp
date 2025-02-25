#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 1234567890;
    
    answer = 0;
    
    int arrSize = a.size();
    for(int i = 0; i < arrSize; i++)
    {
        answer += a[i] * b[i];
    }
    
    return answer;
}