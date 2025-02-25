#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int length = s.size();
    if(length % 2 == 0) // 짝수인 경우다.
    {
        answer.push_back(s[length / 2 - 1]);
        answer.push_back(s[length / 2]);
    }
    else // 홀수인 경우다.
    {
        // 3의 경우 3 / 2 --> 1
        // 5의 경우 5 / 2 --> 2
        
        answer.push_back(s[length / 2]);
    }
    
    return answer;
}