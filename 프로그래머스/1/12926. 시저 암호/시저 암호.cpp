#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ')
        {
            answer.push_back(' ');
            continue;
        }
        
        if(s[i] < 'a') // 대문자의 경우
        {
            int gap = (s[i] - 'A' + n) % 26;
            answer.push_back('A' + gap);
        }
        else // 소문자의 경우
        {
            int gap = (s[i] - 'a' + n) % 26;
            answer.push_back('a' + gap);
        }
    }
    
    return answer;
}