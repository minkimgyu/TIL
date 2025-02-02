#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> pQ;
    
    int workSize = works.size();
    for(int i = 0; i < workSize; i++)
    {
        pQ.push(works[i]);
    }
    
    while(n > 0 && pQ.empty() == false)
    {
        int item = pQ.top();
        pQ.pop();
        
        item--;
        if(item > 0) pQ.push(item);
        n--;
    }
    
    if(pQ.empty() == true)
    {
        answer = 0;
    }
    else
    {
        while(pQ.empty() == false)
        {
            int top = pQ.top();
            answer += top * top;
            pQ.pop();
        }
    }
    
    return answer;
}