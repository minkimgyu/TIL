#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    int pCount = 0;
    int yCount = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'p' || s[i] == 'P')
        {
            pCount++;
        }
        else if(s[i] == 'y' || s[i] == 'Y')
        {
            yCount++;
        }
    }

    if(pCount == yCount) answer = true;
    else answer = false;
    return answer;
}