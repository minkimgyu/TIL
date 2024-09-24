#include <string>
#include <vector>
#include <iostream>
using namespace std;

// vector로 stack 구현해보자

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    
    // pair<pair<값, 인덱스>, 횟수>
    vector<pair<pair<int, int>, int>> result;
    
    for(int i = 0; i < prices.size(); i++)
    {
        for(int j = 0; j < result.size(); j++)
        {
            result[j].second += 1;
        }
        
        if(result.empty() == true)
        {
            result.push_back({{prices[i], i}, 0});
        }
        else
        {
            while(result.empty() == false && result.back().first.first > prices[i])
            {
                answer[result.back().first.second] = result.back().second;
                result.pop_back();
            }
            
            result.push_back({{prices[i], i}, 0});
        }
    }
    
    for(int j = 0; j < result.size(); j++)
    {
        answer[result[j].first.second] = result[j].second;
    }
    
    return answer;
}