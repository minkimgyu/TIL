#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    vector<pair<int, bool>> tmpArr;
    
    int minValue = -1;
    int minIndex = -1;
    
    for(int i = 0; i < arr.size(); i++)
    {
        tmpArr.push_back({arr[i], true});
        
        if(i == 0)
        {
            minIndex = i;
            minValue = arr[i];
        }
        else
        {
            if(arr[i] < minValue) 
            {
                minValue = arr[i];
                minIndex = i;
            }
        }
    }
    
    tmpArr[minIndex].second = false;
    
    for(int j = 0; j < tmpArr.size(); j++)
    {
        if(tmpArr[j].second == false) continue;
        answer.push_back(tmpArr[j].first);
    }
    
    if(answer.empty() == true) answer.push_back(-1);
    return answer;
}