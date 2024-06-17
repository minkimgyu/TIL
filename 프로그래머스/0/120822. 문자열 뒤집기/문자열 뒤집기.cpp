#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    for(int i = my_string.size() - 1; i >= 0; i--)
    {
        answer.push_back(my_string[i]);
    }
    
    return answer;
}