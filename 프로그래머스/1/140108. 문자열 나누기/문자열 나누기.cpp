#include <string>
#include <vector>
#include <iostream>
using namespace std;

int count = 1;

void dfs(string s)
{
    // cout << s << " ";
    
    char firstChar = s[0];
    int sameAsFirst = 0;
    int sameAsOther = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == firstChar)
        {
            sameAsFirst++;
        }
        else
        {
            sameAsOther++;
        }
        
        if(sameAsFirst == sameAsOther)
        {
            int first = i + 1;
            int second = s.size() - i;
            
            string convertedS = s.substr(first, second);
            if(convertedS.size() == 0) return;
            
            count++;
            dfs(s.substr(first, second));
            return;
        }
    }
}


int solution(string s) {
    int answer = 0;
    dfs(s);
    answer = count;
    return answer;
}