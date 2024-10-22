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
            
            // 예시와 달리 i가 citations[i]보다 더 클 수 있고 이 때문에 최대값을 구해서 리턴해야한다.
            return max(citations[i], i);
        }
    }
}