#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    
    vector<int> items = emergency;
    
    sort(emergency.begin(), emergency.end(), compare);
    
    for(int i = 0; i < items.size(); i++)
    {
        for(int j = 0; j < emergency.size(); j++)
        {
            if(items[i] == emergency[j])
            {
                answer.push_back(j + 1);
            }
        }
    }
    
    return answer;
}