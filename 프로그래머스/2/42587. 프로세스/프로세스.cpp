#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

// 인덱스, 우선 순위

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    int executeCount = 0;
    list<pair<int, int>> li;
    
    for(int i = 0; i < priorities.size(); i++)
    {
        li.push_back({i, priorities[i]});
    }
    
    while(li.empty() == false)
    {
        pair<int, int> front = li.front();
        
        
        int maxValue = 0;
        for(auto it = li.begin(); it != li.end(); it++)
        {
            if(it->second > maxValue) maxValue = it->second;
        }
        
        // cout << front.second << " " << maxValue << " \n";
        
        if(front.second < maxValue)
        {
            li.pop_front();
            li.push_back(front);
        }
        else
        {
            executeCount++;
            if(front.first == location)
            {
                answer = executeCount;
                break;
            }
            
            li.pop_front();
        }
    }
    
    return answer;
}