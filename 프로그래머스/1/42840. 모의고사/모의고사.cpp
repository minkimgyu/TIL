#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int oneMod = 5;
int oneArr[5] = {1, 2, 3, 4, 5};

int twoMod = 8;
int twoArr[8] = {2, 1, 2, 3, 2, 4, 2, 5};

int threeMod = 10;
int threeArr[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

bool compare(pair<int, int> a, pair<int, int> b)
{
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    // 1번의 경우 1, 2, 3, 4, 5, ||| 1, 2, 3, 4, 5,
    // 2번의 경우 2, 1, 2, 3, 2, 4, 2, 5, |||  2, 1, 2, 3, 2, 4, 2, 5
    // 3번의 경우 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ||| 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...
    
    pair<int, int> correctCnt[3] = {{0, 1}, {0, 2}, {0, 3}};
    
    for(int i = 0; i < answers.size(); i++)
    {
        if(answers[i] == oneArr[i % oneMod]) correctCnt[0].first++;
        if(answers[i] == twoArr[i % twoMod]) correctCnt[1].first++;
        if(answers[i] == threeArr[i % threeMod]) correctCnt[2].first++;
    }
    
    cout << correctCnt[0].first << " " << correctCnt[1].first << " " << correctCnt[2].first;
    
    sort(correctCnt, correctCnt + 3, compare);
    

    if(correctCnt[0].first == correctCnt[1].first && correctCnt[1].first == correctCnt[2].first)
    {
        answer.push_back(correctCnt[0].second);
        answer.push_back(correctCnt[1].second);
        answer.push_back(correctCnt[2].second);
    }
    else if(correctCnt[0].first == correctCnt[1].first)
    {
        answer.push_back(correctCnt[0].second);
        answer.push_back(correctCnt[1].second);
    }
    else
    {
        answer.push_back(correctCnt[0].second);
    }
    
    return answer;
}