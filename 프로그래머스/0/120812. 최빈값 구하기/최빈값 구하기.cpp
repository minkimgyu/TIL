#include <string>
#include <vector>

const int arrSize = 1000;
int arr[arrSize];
using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    
    for(int i = 0; i < array.size(); i++)
    {
        arr[array[i]] += 1;
    }
    
    int maxItem = -1;
    int maxCount = -1;
    bool canDouble = false;
    for(int i = 0; i < arrSize; i++)
    {
        if(arr[i] == maxCount)
        {
            canDouble = true;
        }
        else if(arr[i] > maxCount)
        {
            maxCount = arr[i];
            maxItem = i;
            canDouble = false;
        }
    }
    
    if(canDouble == true) answer = -1;
    else answer = maxItem;
    
    return answer;
}