#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int have[35];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    int haveCount = n - lost.size();
    
    for(int i = 0; i <= n; i++)
    {
        have[i] = true;
    }
    
    for(int i = 0; i < lost.size(); i++)
    {
        have[lost[i]] = false;
        
        cout << lost[i] << " ";
    }
    
    cout << '\n';
    
    vector<int> mustHave;
    
    for(int i = 0; i < reserve.size(); i++)
    {
        if(have[reserve[i]] == false)
        {
            cout << reserve[i] << " ";
            
            have[reserve[i]] = true;
            haveCount++; // 역으로 가지고 있는 학생의 수를 늘려줘야함
        }
        else
        {
            mustHave.push_back(reserve[i]);
        }
    }
    
    cout << haveCount << " ";
    
    for(int i = 0; i < mustHave.size(); i++)
    {
        int leftValue = mustHave[i] - 1;
        int rightValue = mustHave[i] + 1;
        
        if(1 <= leftValue && leftValue <= n)
        {
            if(have[leftValue] == false)
            {
                have[leftValue] = true;
                haveCount++;
                continue;
            }
        }
        
        if(1 <= rightValue && rightValue <= n)
        {
            if(have[rightValue] == false)
            {
                have[rightValue] = true;
                haveCount++;
            }
        }
    }
    
    answer = haveCount;
    
    return answer;
}