#include <string>
#include <vector>

using namespace std;

string solution(string rsp) {
    string answer = "";
    
    int rspSize = rsp.size();
    for(int i = 0; i < rspSize; i++)
    {
        switch(rsp[i])
        {
            case '2':
                answer.push_back('0');
                break;
            case '0':
                answer.push_back('5');
                break;
            case '5':
                answer.push_back('2');
                break;
        }
    }
    
    return answer;
}