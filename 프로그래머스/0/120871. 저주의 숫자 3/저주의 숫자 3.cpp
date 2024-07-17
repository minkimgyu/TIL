#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> ReturnPoint(int answer)
{
    vector<int> points;
    
    int multi = 10;
    while(1)
    {
        if(multi > answer * 10) break;
        
        int num = answer % multi;
        int point = num / (multi / 10);
        
        points.push_back(point);
        multi *= 10;
    }
    
    return points;
}

int solution(int n) {
    int answer = 0;
    
    for(int i = 1; i <= n; i++)
    {
        answer += 1;
        
        while(1)
        {
            bool canFind = false;
            
            while(1)
            {
                bool canExit = false;
                if(answer % 3 == 0) 
                {
                    answer += 1;
                    canExit = true;
                }

                if(canExit == false) break;
            }
            
            vector<int> points = ReturnPoint(answer);
            for(int j = 0; j < points.size(); j++)
            {
                if(points[j] == 3)
                {
                    answer += 1;
                    canFind = true;
                    break;
                }
            }
            
            if(canFind == false) break;
        }
        
        cout << answer << " ";
    }
    
    return answer;
}