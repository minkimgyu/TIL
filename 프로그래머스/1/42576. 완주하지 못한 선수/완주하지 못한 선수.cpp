#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string, int> participantMap;
    
    for(int i = 0; i < participant.size(); i++)
    {
        participantMap[participant[i]] += 1;
    }
    
    for(int i = 0; i < completion.size(); i++)
    {
        participantMap[completion[i]] -= 1;
    }
    
    for(auto iter = participantMap.begin(); iter != participantMap.end(); iter++)
    {
        // cout << iter->first << " " << iter->second << " ";
        if(iter->second > 0)
        {
            answer = iter->first;
        }
    }
    
    return answer;
}