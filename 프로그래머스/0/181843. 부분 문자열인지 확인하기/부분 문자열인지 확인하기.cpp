#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string target) {
    int answer = 0;
    
    for(int i = 0; i < my_string.size(); i++)
    {
        bool isCorrect = true;
        
        for(int j = 0; j < target.size(); j++)
        {
            if(i + j >= my_string.size() || my_string[i + j] != target[j])
            {
                isCorrect = false;
                break;
            }
        }
        
        if(isCorrect == true)
        {
            answer = 1;
            break;
        }
    }
    
    return answer;
}