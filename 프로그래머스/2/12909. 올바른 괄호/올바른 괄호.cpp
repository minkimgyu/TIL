#include<string>
#include <iostream>
#include <stack>

using namespace std;

stack<char> st;

bool solution(string s)
{
    bool answer = true;

    for(int i = 0; i < s.size(); i++)
    {
        if(st.empty() == true)
        {
            st.push(s[i]);
        }
        else
        {
            if(st.top() == '(' && s[i] == ')')
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
    }
    
    answer = st.empty();
    return answer;
}