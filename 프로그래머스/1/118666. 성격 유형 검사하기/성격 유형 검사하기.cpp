#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<char, int> surveyData;

void SolveOneProblem(string survey, int choice)
{
    switch(choice)
    {
        case 1:
            surveyData[survey[0]] += 3;
            break;
        case 2:
            surveyData[survey[0]] += 2;
            break;
        case 3:
            surveyData[survey[0]] += 1;
            break;
            
        case 4:
            break;
            
        case 5:
            surveyData[survey[1]] += 1;
            break;
        case 6:
            surveyData[survey[1]] += 2;
            break;
        case 7:
            surveyData[survey[1]] += 3;
            break;
    }
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    for(int i = 0; i < survey.size(); i++)
    {
        SolveOneProblem(survey[i], choices[i]);
    }
    
    if(surveyData['R'] >= surveyData['T'])
    {
        answer.push_back('R');
    }
    else
    {
        answer.push_back('T');
    }
    
    if(surveyData['C'] >= surveyData['F'])
    {
        answer.push_back('C');
    }
    else
    {
        answer.push_back('F');
    }
    
    if(surveyData['J'] >= surveyData['M'])
    {
        answer.push_back('J');
    }
    else
    {
        answer.push_back('M');
    }
    
    if(surveyData['A'] >= surveyData['N'])
    {
        answer.push_back('A');
    }
    else
    {
        answer.push_back('N');
    }
    
    return answer;
}