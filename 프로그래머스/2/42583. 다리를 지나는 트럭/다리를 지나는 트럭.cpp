#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

// list<int> trucks;
// list<pair<int, int>> bridge;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    list<int> trucks;
    list<pair<int, int>> bridge;
    int sumOfBridge = 0;
    
    for(int i = 0; i < truck_weights.size(); i++)
    {
        trucks.push_back(truck_weights[i]);
    }
    
    sumOfBridge += trucks.front();
    bridge.push_back({trucks.front(), 0});
    trucks.pop_front();
    answer++;
    
    while(1)
    {
        if(bridge.empty() == false && bridge.front().second >= bridge_length)
        {
            sumOfBridge -= bridge.front().first;
            bridge.pop_front();
        }
        
        if(bridge.empty() && trucks.empty()) break;
        
        // 다리에 트럭을 넣어준다.
        if(trucks.empty() == false && trucks.front() + sumOfBridge <= weight)
        {
            sumOfBridge += trucks.front();
            bridge.push_back({trucks.front(), 0});
            trucks.pop_front();
        }
        
        for(auto it = bridge.begin(); it != bridge.end(); it++)
        {
            it->second += 1;
        }
        
        answer++;
    }
    
    return answer;
}