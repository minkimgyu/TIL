#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 6 5 3 1 0
//     ※

bool compare(int a, int b)
{
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), compare);
    
    int citationsSize = citations.size();
    for(int i = 0; i < citationsSize; i++)
    {
        int leftCount = citationsSize - i + 1;
        if(i + 1 >= citations[i])
        {
            return max(citations[i], i);
        }
    }
    
    return citations.size();
}