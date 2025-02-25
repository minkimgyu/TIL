#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<int, int> selection;

int solution(vector<int> nums)
{
    int answer = 0;
    
    int maxPickCount = nums.size() / 2;
    
    for(int i = 0; i < nums.size(); i++)
    {
        selection[nums[i]] += 1;
    }
    
    int selectionSize = selection.size();
    
    answer = min(maxPickCount, selectionSize);
    
    return answer;
}