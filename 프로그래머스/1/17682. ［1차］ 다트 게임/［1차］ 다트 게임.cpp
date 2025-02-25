#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    
    vector<int> sum;
    int dartResultSize = dartResult.size();
    
    int pastIndex = 0;
    
    for(int i = 0; i < dartResult.size(); i++)
    {
        
        if('A' <= dartResult[i] && dartResult[i] <= 'Z')
        {
            char area = dartResult[i];
            
            string score;
            for(int j = pastIndex; j < i; j++)
            {
                score.push_back(dartResult[j]);
            }
            
            int currentScore = stoi(score);
            int resultScore = 1;
            switch(area)
            {
                case 'S':
                    resultScore *= currentScore;
                    break;
                case 'D':
                    resultScore *= currentScore;
                    resultScore *= currentScore;
                    break;
                case 'T':
                    resultScore *= currentScore;
                    resultScore *= currentScore;
                    resultScore *= currentScore;
                    break;
            }
            
            sum.push_back(resultScore);
            pastIndex = i + 1;
        }
        else if(dartResult[i] == '*' || dartResult[i] == '#')
        {
            // 앞선 값도 있다면 같이 처리해주기
            int sumSize = sum.size();
            switch(dartResult[i])
            {
                case '*':
                    if(sumSize == 1)
                    {
                        sum[0] *= 2;
                    }
                    else if(sumSize > 1)
                    {
                        sum[sumSize - 1] *= 2;
                        sum[sumSize - 2] *= 2;
                    }
                    break;
                case '#':
                    sum[sumSize - 1] *= -1;
                    break;
            }
            
            // pastIndex 처리해주기
            pastIndex = i + 1;
        }
    }
    
    for(int i = 0; i < sum.size(); i++)
    {
        cout << sum[i] << " ";
        answer += sum[i];
    }
    
    return answer;
}