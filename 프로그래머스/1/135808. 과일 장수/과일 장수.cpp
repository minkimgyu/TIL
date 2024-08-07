#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(), score.end(), compare);
    
    int scoreSize = score.size();
    
    for(int i = -1; i < scoreSize; i += m)
    {
        if(i == -1) continue;
        answer += score[i] * m;
    }
    
    return answer;
}