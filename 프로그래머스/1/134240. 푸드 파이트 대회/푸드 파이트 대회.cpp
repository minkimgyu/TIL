#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    int foodSize = food.size();
    
    for(int i = 1; i < foodSize; i++)
    {
        int item = food[i];
        int itemCount = item / 2;
        
        for(int j = 0; j < itemCount; j++)
        {
            answer.push_back((char)(i + 48));
        }
    }
    
    answer.push_back('0');
    
    for(int i = foodSize - 1; i >= 1; i--)
    {
        int item = food[i];
        int itemCount = item / 2;
        
        for(int j = 0; j < itemCount; j++)
        {
            answer.push_back((char)(i + 48));
        }
    }
    
    return answer;
}