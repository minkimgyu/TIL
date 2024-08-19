#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 123456789;
    answer = 0;
    
    int answerSize = absolutes.size();
    for(int i = 0; i < answerSize; i++)
    {
        if(signs[i] == true)
        {
            cout << absolutes[i] * 1 << " ";
            answer += absolutes[i] * 1;
        }
        else if(signs[i] == false)
        {
            cout << absolutes[i] * -1 << " ";
            answer += absolutes[i] * -1;
        }
    }
    
    return answer;
}