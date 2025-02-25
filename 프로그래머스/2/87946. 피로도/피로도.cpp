#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int maxVisitCount = 0;

const int maxDungeons = 8;
bool visit[maxDungeons];
int arr[maxDungeons];

void dfs(int loopCount, int k, vector<vector<int>> dungeons)
{
    if(loopCount == dungeons.size())
    {
        int tired = k;
        int visitCount = 0;
        for(int i = 0; i < loopCount; i++)
        {
            vector<int> dungeonValue = dungeons[arr[i]];
            
            if(tired >= dungeonValue[0])
            {
                tired -= dungeonValue[1];
                visitCount++;
            }
            else
            {
                break;
            }
        }
        
        maxVisitCount = max(maxVisitCount, visitCount);
        return;
    }
    else
    {
        for(int i = 0; i < dungeons.size(); i++)
        {
            if(visit[i] == true) continue;
            visit[i] = true;
            
            arr[loopCount] = i;
            dfs(loopCount + 1, k, dungeons);
            
            visit[i] = false;
        }
    }
}


int solution(int k, vector<vector<int>> dungeons) {
    dfs(0, k, dungeons);
    return maxVisitCount;
}