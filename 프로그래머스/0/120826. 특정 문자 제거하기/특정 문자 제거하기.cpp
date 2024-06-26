#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string letter) {
    string answer = "";
    
    for(int i = 0; i < my_string.size(); i++)
    {
        if((int)my_string[i] == (int)letter[0]) continue;
        
        answer.push_back(my_string[i]);
    }
    
    
    return answer;
}