#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    
    for(int i = 0; i < seoul.size(); i++)
    {
        if(seoul[i] == "Kim")
        {
            string front = "김서방은 ";
            string middle = to_string(i);
            string end = "에 있다";
            
            answer = front + middle + end;
            break;
        }
    }
    
    return answer;
}