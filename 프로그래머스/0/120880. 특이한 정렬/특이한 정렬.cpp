#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if(a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    vector<pair<int, int>> items;
    
    for(int i = 0; i < numlist.size(); i++)
    {
        int item = abs(n - numlist[i]);
        items.push_back({ numlist[i], item });
    }
    
    sort(items.begin(), items.end(), compare);
    
    for(int i = 0; i < items.size(); i++)
    {
        answer.push_back(items[i].first);
    }
    
    return answer;
}