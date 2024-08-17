#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i = 0; i < commands.size(); i++)
    {
        vector<int> tmpArr;
        int start = commands[i][0];
        int end = commands[i][1];
        
        int index = commands[i][2];

        for(int j = start - 1; j <= end - 1; j++)
        {
            tmpArr.push_back(array[j]);
        }
        
        sort(tmpArr.begin(), tmpArr.end());
        answer.push_back(tmpArr[index - 1]);
    }
    
    return answer;
}