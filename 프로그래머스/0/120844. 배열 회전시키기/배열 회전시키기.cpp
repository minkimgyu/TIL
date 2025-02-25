#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    vector<int> answer;
    
    if(direction == "right")
    {
        int tmp = numbers[numbers.size() - 1];
        numbers.pop_back();
        
        answer.push_back(tmp);
        for(int i = 0; i < numbers.size(); i++)
        {
            answer.push_back(numbers[i]);
        }
    }
    else
    {
        int tmp = numbers[0];
        
        for(int i = 1; i < numbers.size(); i++)
        {
            answer.push_back(numbers[i]);
        }
        answer.push_back(tmp);
    }
    
    return answer;
}