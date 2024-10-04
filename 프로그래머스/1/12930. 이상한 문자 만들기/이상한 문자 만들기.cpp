#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    int gap = 'a' - 'A';
    
    int letterCount = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ')
        {
            letterCount = 0;
            continue;
        }
        
        // cout << letterCount << " ";
        
        if(letterCount % 2 == 0)
        {
            if(s[i] >= 'a') // 소문자의 경우
            {
                s[i] -= gap;
            }
        }
        else
        {
            if(s[i] < 'a') // 대문자의 경우
            {
                 s[i] += gap;
            }
        }
        
        letterCount++;
    }
    
    answer = s;
    
    return answer;
}