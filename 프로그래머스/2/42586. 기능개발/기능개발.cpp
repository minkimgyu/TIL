#include <string>
#include <vector>
#include <list>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    list<pair<int, int>> li;
    
    for(int i = 0; i < progresses.size(); i++)
    {
        li.push_back({progresses[i], speeds[i]});
    }
    
    while(li.empty() == false)
    {
        int outCount = 0;
        
        while(li.empty() == false && li.front().first >= 100)
        {
            outCount++;
            li.pop_front();
        }
        
        if(outCount > 0) answer.push_back(outCount);
        
        for(auto it = li.begin(); it != li.end(); it++)
        {
            it->first += it->second;
        }
    }
    
    return answer;
}