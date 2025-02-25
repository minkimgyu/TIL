#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int dp[500][500] { 0 };

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    // 인덱스가 같거나 하나 큰 경우를 선택해야한다.
    // 높이가 1 이상 500 이하이므로 가장 마지막 층은 원소 개수가 500개이다.
    
    dp[0][0] = triangle[0][0];
    
    int triangleHeight = triangle.size();
    for(int i = 0; i < triangleHeight - 1; i++) // 마지막 층은 연산하면 안 됨
    {
        int triangleWidth = triangle[i].size();
        for(int j = 0; j < triangleWidth; j++)
        {
            if(max(dp[i + 1][j], triangle[i + 1][j] + dp[i][j]) == triangle[i + 1][j] + dp[i][j])
            {
                dp[i + 1][j] = triangle[i + 1][j] + dp[i][j];
                
                if(answer < dp[i + 1][j]) 
                {
                    answer = dp[i + 1][j];
                    
                }
            }
            
            if(max(dp[i + 1][j + 1], triangle[i + 1][j + 1] + dp[i][j]) == triangle[i + 1][j + 1] + dp[i][j])
            {
                dp[i + 1][j + 1] = triangle[i + 1][j + 1] + dp[i][j];
                
                if(answer < dp[i + 1][j + 1])
                {
                     answer = dp[i + 1][j + 1];
                }
            }
            
            
            
            
        }
    }
    
    return answer;
}