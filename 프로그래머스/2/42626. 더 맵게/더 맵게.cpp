#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pQ;
    
    for(int i = 0; i < scoville.size(); i++)
    {
        pQ.push(scoville[i]);
    }
    
    while(pQ.size() >= 2 && pQ.top() < K)
    {
        int item1 = pQ.top();
        // cout << item1 << " ";
        pQ.pop();
        
        int item2 = pQ.top();
        // cout << item2 << " ";
        pQ.pop();
        
        int add = item1 + (item2 * 2);
        pQ.push(add);
        answer++;
    }
    
    if(pQ.top() < K) return -1; // 사이즈가 1이고 최소값이 7보다 작은 경우
    else return answer;
}