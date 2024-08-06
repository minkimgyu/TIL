#include <string>
#include <vector>

using namespace std;

const int itemSize = 201;
bool items[itemSize];

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    int numberSize = numbers.size();
    for(int i = 0; i < numberSize; i++)
    {
        for(int j = i + 1; j < numberSize; j++)
        {
           items[numbers[i] + numbers[j]] = true;
        }
    }
    
    for(int i = 0; i < itemSize; i++)
    {
        if(items[i] == true) answer.push_back(i);
    }
    
    return answer;
}