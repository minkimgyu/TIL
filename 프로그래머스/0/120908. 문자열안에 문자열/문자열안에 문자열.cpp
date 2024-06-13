#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    int answer = 2;
    
    int str2Index = 0;
    int str2Size = str2.size();
    int str1Size = str1.size();
    
    for(int i = 0; i < str1Size; i++)
    {
        if(str1[i] == str2[str2Index])
        {
            str2Index++;
            
            if(str2Index == str2Size)
            {
                answer = 1;
                break;
            }
        }
        else
        {
            str2Index = 0;
        }
    }
    
    return answer;
}