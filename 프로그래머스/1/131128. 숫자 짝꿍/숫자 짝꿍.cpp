#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int arrSize = 10;
int arr1[arrSize] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int arr2[arrSize] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

vector<int> countArr;

bool compare(int a, int b)
{
    return a > b;
}

string solution(string X, string Y) {
    string answer = "";
    
    for(int i = 0; i < X.size(); i++)
    {
        arr1[X[i] - '0'] += 1;
    }
    
    for(int i = 0; i < Y.size(); i++)
    {
        arr2[Y[i] - '0'] += 1;
    }
    
    bool isAllZero = true;
    
    for(int i = 0; i < arrSize; i++)
    {
        int count = min(arr1[i], arr2[i]);
        if(count == 0) continue;
        
        if(i != 0) isAllZero = false;
        
        for(int j = 0; j < count; j++)
        {
            countArr.push_back(i);
        }
    }
    
    cout << countArr.size();
    
    if(countArr.size() == 0) // 겹치는 수가 없는 경우
    {
        answer.push_back('-');
        answer.push_back('1');
        return answer;
    }
    
    if(isAllZero == true) // 겹치는 수가 있지만 0인 경우
    {
        answer.push_back('0');
        return answer;
    }
    
    sort(countArr.begin(), countArr.end(), compare);
    
    for(int i = 0; i < countArr.size(); i++)
    {
        answer.push_back(countArr[i] + '0');
    }
   
    
    return answer;
}