#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, int> clothesMap;

const int maxSize = 30;
int arr[maxSize];
int clothesArr[maxSize];

int answer = 0;

void dfs(int count, int maxCount)
{
    int multiply = 1;
    for(int j = 0; j < count; j++)
    {
        multiply *= clothesArr[arr[j]];
        //cout << clothesArr[arr[j]] << " ";
    }
    //cout << '\n';

    if(count != 0) answer += multiply;
    
    
    if(count == maxCount)
    {
        return;
    }
    else
    {
        for(int i = 0; i < maxCount; i++)
        {
            if(count > 0 && arr[count - 1] >= i) continue;
            
            arr[count] = i;
            dfs(count + 1, maxCount);
        }
    }
}


int solution(vector<vector<string>> clothes) {
    
    for(int i = 0; i < clothes.size(); i++)
    {
        clothesMap[clothes[i][1]] += 1;
    }
    
    int arrCount = 0;
    for(auto it = clothesMap.begin(); it != clothesMap.end(); it++)
    {
        clothesArr[arrCount] = it->second;
        arrCount++;
    }
    
    if(arrCount == 30)
    {
        answer = 1073741823;
    }
    else
    {
        dfs(0, arrCount);
    }
    
    return answer;
}