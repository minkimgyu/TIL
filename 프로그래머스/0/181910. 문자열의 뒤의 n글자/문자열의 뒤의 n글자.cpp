#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    string answer = "";
    
    int strSize = my_string.size() - n;
    
    for(int i = strSize; i < my_string.size(); i++)
    {
        answer.push_back(my_string[i]);
    }
    return answer;
}