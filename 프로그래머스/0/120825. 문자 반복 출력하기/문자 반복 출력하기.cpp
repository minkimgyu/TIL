#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    string answer = "";
    
    int strSize = my_string.size();
    for(int i = 0; i < strSize; i++)
    {
        for(int j = 0; j < n; j++)
        {
            answer.push_back(my_string[i]);
        }
    }
    
    return answer;
}