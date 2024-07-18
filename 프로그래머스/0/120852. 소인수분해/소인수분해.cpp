#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    for(int i = 2; i <= n; i++)
    {
        if(n % i == 0)
        {
            if(answer.size() == 0)
            {
                answer.push_back(i);
            }
            else
            {
                bool canMod = false;
                for(int j = 0; j < answer.size(); j++)
                {
                    if(i % answer[j] == 0)
                    {
                        canMod = true;
                        break;
                    }
                }
                
                if(canMod == false)
                {
                    answer.push_back(i);
                }
            }
        }
    }
    
    return answer;
}