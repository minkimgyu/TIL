#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> items;
    
    int scoreSize = score.size();
    for(int i = 0; i < scoreSize; i++)
    {
        items.push_back(score[i]);
        sort(items.begin(), items.end(), compare);
        
        int itemSize = items.size();
        if(itemSize < k)
        {
            int back = items.back();
            answer.push_back(back);
        }
        else
        {
            answer.push_back(items[k - 1]);
        }
    }
    
    return answer;
}