#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cfloat>
using namespace std;

const int maxStageCount = 501;
int currentStage[maxStageCount];

vector<pair<int, float>> result;

bool compare(pair<int, float> a, pair<int, float> b)
{
    if(a.second == b.second)
    {
        return a.first < b.first;
    }
    
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    for(int i = 0; i < stages.size(); i++)
    {
        currentStage[stages[i]] += 1;
    }
    
    int challengeCnt = stages.size();
    
    for(int i = 1; i <= N; i++)
    {
        float ratio;
        
        if(challengeCnt == 0)
        {
            ratio = 0.0f;
        }
        else
        {
            ratio = (float)currentStage[i] / challengeCnt;
        }
        
        result.push_back({i, ratio});
        challengeCnt -= currentStage[i];
    }
    
    sort(result.begin(), result.end(), compare);
    
    for(int i = 0; i < result.size(); i++)
    {
        answer.push_back(result[i].first);
    }
    
    return answer;
}