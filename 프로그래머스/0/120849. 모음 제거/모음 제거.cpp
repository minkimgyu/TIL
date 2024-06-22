#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    int strSize = my_string.size();
    for(int i = 0; i < strSize; i++)
    {
        if(my_string[i] == 'a' || my_string[i] == 'e' || my_string[i] == 'i' || my_string[i] == 'o' || my_string[i] == 'u') continue;
        
        answer.push_back(my_string[i]);
    }
    
    return answer;
}