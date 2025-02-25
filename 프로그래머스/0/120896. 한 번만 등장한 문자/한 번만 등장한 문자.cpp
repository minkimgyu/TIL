#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int arrSize = 26;
int arr[arrSize];

bool compare(char a, char b)
{
    return (int)a < (int)b;
}

string solution(string s) {
    string answer = "";
    
    for(int i = 0; i < s.size(); i++)
    {
        int index = (int)s[i] - 97;
        arr[index] += 1;
    }
    
    for(int i = 0; i < arrSize; i++)
    {
        if(arr[i] == 1)
        {
            char item = i + 97;
            answer.push_back(item);
        }
    }
    
    sort(answer.begin(), answer.end(), compare);
    
    return answer;
}