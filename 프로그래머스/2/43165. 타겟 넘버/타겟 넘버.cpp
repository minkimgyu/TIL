#include <string>
#include <vector>

using namespace std;

const int arrSize = 20;
int arr[arrSize];

const int frontArrSize = 2;
int frontArr[frontArrSize] = {1, -1};

int result = 0;

void dfs(int count, int target, vector<int> numbers)
{
    if(count == numbers.size())
    {
        int sum = 0;
        for(int i = 0; i < count; i++)
        {
            sum += numbers[i] * arr[i];
        }
        
        if(sum == target) result++;
    }
    else
    {
        for(int i = 0; i < frontArrSize; i++)
        {
            arr[count] = frontArr[i];
            dfs(count + 1, target, numbers);
        }
    }
}

int solution(vector<int> numbers, int target) {
    dfs(0, target, numbers);
    return result;
}