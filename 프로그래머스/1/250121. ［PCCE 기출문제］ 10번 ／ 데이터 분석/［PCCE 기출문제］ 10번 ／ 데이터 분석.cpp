#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> extIndex;
string sortBy;

bool compare(vector<int> a, vector<int> b)
{
    return a[extIndex[sortBy]] < b[extIndex[sortBy]];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    sortBy = sort_by;
    
    extIndex["code"] = 0;
    extIndex["date"] = 1;
    extIndex["maximum"] = 2;
    extIndex["remain"] = 3;
    
    for(int i = 0; i < data.size(); i++)
    {
        vector<int> oneData = data[i];
        if(oneData[extIndex[ext]] < val_ext)
        {
            answer.push_back(oneData);
        }
    }
    
    sort(answer.begin(), answer.end(), compare);
    
    return answer;
}