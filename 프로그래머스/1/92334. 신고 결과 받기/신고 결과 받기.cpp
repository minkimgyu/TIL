#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
// 8시 38분

using namespace std;

map<string, vector<string>> callMap; // 신고 당한 사람, 신고한 사람

map<string, int> callCountMap; // 메일을 받을 사람, 메일 받은 개수

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    map<pair<string, string>, bool> visit;
    
    int reportSize = report.size();
    for(int i = 0; i < reportSize; i++)
    {
        
        string rep = report[i];
        string reportArr[2];
        
        stringstream ss(rep);
        string tocken;
        
        int sliceCount = 0;
        
        while (getline(ss, tocken, ' ')) 
        {
            reportArr[sliceCount] = tocken;
            sliceCount++;
	    }   
        
        // cout << reportArr[0] << " " << reportArr[1] << " ";
        
        if(visit[{reportArr[1], reportArr[0]}] == true) continue;
        visit[{reportArr[1], reportArr[0]}] = true;
        
        callMap[reportArr[1]].push_back(reportArr[0]);
    }
    
    int id_listSize = id_list.size();
    for(int i = 0; i < id_listSize; i++)
    {
        string person = id_list[i];
        vector<string> callPerson = callMap[person];
        
        if(callPerson.size() < k) continue;
        
        int callPersonSize = callPerson.size();
        for(int j = 0; j < callPersonSize; j++)
        {
            callCountMap[callPerson[j]] += 1;
        }
    }
    
    
    
    
    for(int i = 0; i < id_listSize; i++)
    {
        string person = id_list[i];
        
        cout << person << " " << callCountMap[person] << " ";
        
        answer.push_back(callCountMap[person]);
    }
    
    return answer;
}