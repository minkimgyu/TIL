#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer;
    
    int max = -1;
    int maxIndex = -1;
    
    int arrSize = array.size();
    for(int i = 0; i < arrSize; i++)
    {
        if(array[i] > max)
        {
            max = array[i];
            maxIndex = i;
        }
    }
    
    answer.push_back(max);
    answer.push_back(maxIndex);
    
    return answer;
}