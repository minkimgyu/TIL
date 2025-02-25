#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) 
{
    vector<int> answer(numbers.size());
    
    vector<pair<int, int>> st; // value, index --> 끝까지 남아있다면 index에 -1 넣어주기
    
    for(int i = 0; i < numbers.size(); i++)
    {
        if(st.empty() == true)
        {
            st.push_back({numbers[i], i});
        }
        else
        {
            while(st.empty() == false && st.back().first < numbers[i])
            {
                int value = st.back().first;
                int index = st.back().second;
                
                st.pop_back();
                answer[index] = numbers[i];
            }
            
            st.push_back({numbers[i], i});
        }
    }
    
    for(int j = 0; j < st.size(); j++)
    {
        int index = st[j].second;
        answer[index] = -1;
    }
    
    return answer;
}