#include <string>
#include <vector>

using namespace std;

bool visit[10];

int solution(vector<int> numbers) {
    int answer = -1;
    
    int numberSize = numbers.size();
    for(int i = 0; i < numberSize; i++)
    {
        visit[numbers[i]] = true;
    }
    
    answer = 0;
    
    for(int i = 0; i < 10; i++)
    {
        if(visit[i] == false)
        {
            answer += i;
        }
    }
    
    return answer;
}