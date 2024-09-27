#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int sum = brown + yellow;
    
    for(int i = 1; i <= sum; i++)
    {
        if(sum % i == 0)
        {
            int row = i; // 세로
            int column = sum / i; // 가로
            
            if(column < row) continue;
            
            int outerCount = row * 2 + column * 2 - 4;
            int innerCount = sum - outerCount;
           
             
            if(outerCount == brown && innerCount == yellow)
            {
                answer.push_back(column);
                answer.push_back(row);
                break;
            }
        }
    }
    
    return answer;
}