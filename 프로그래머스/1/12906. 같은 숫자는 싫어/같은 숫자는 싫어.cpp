#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> st;
    
    for(int i = 0; i < arr.size(); i++)
    {
        if(st.empty() == true)
        {
            st.push(arr[i]);
            answer.push_back(arr[i]);
        }
        else
        {
            if(st.top() == arr[i]) continue;
            else 
            {
                st.push(arr[i]);
                answer.push_back(arr[i]);
            }
        }
    }
    
    return answer;
}