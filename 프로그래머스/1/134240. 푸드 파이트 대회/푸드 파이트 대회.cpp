#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    vector<int> input;
    
    int foodSize = food.size();
    for(int i = 1; i < foodSize; i++)
    {
        int foodCount = food[i] / 2;
        for(int j = 0; j < foodCount; j++)
        {
            input.push_back(i);
        }
    }
    
    for(int i = 0; i < input.size(); i++)
    {
        answer.push_back(input[i] + '0');
    }
    
    answer.push_back('0');
    
    for(int i = input.size() - 1; i > -1; i--)
    {
        answer.push_back(input[i] + '0');
    }
    
    return answer;
}