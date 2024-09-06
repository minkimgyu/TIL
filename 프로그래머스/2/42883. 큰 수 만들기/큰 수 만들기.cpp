#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

stack<int> st;

string solution(string number, int k) {
    string answer;
    int leftCount = number.size() - k;
    
    
    int storedK = k;
    
    for(int i = 0; i < number.size(); i++)
    {
        if(st.empty() == true)
        {
            st.push(number[i] - '0');
        }
        else
        {
            while(st.empty() == false && k > 0 && st.top() < number[i] - '0')
            {
                st.pop();
                k--;
            }
            
            st.push(number[i] - '0');
        }
    }
   
    while(st.empty() == false)
    {
        answer.push_back(st.top() + '0');
        st.pop();
    }
    
    string newAnswer;
    
    cout << answer.size() << " " << leftCount;
    if(answer.size() > leftCount)
    {
        int startIndex = answer.size() - 1;
        int count = 0;
        
        while(count < leftCount)
        {
            newAnswer.push_back(answer[startIndex]);
            startIndex--;
            count++;
        }
    }
    else
    {
        for(int i = answer.size() - 1; i > -1; i--)
        {
            newAnswer.push_back(answer[i]);
        }
    }
    
    return newAnswer;
}