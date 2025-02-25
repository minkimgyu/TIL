#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int solution(vector<int> array, int n) {
    int answer = 0;
    
    sort(array.begin(), array.end(), compare);
    
    int index = 0;
    int min = 10000;
    for(int i = 0; i < array.size(); i++)
    {
        int item = array[i] - n;
        item = abs(item);
        if(min >= item)
        {
            min = item;
            index = i;
        }
    }
    
    answer = array[index];
    return answer;
}