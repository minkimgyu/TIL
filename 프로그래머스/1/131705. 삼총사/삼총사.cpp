#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    
    int numberSize = number.size();
    for(int i = 0; i < numberSize; i++)
    {
        for(int j = 0; j < i; j++)
        {
            for(int k = 0; k < j; k++)
            {
                int sum = number[i] + number[j] + number[k];
                if(sum == 0) answer++;
            }
        }
    }
    
    return answer;
}