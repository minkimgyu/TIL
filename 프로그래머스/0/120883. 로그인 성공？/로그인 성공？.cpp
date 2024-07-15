#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "";
    
    bool canClear = false;
    bool halfClear = false;
    
    for(int i = 0; i < db.size(); i++)
    {
        if(id_pw[0] == db[i][0] && id_pw[1] == db[i][1]) 
        {
            canClear = true;
            break;
        }
        
        if(id_pw[0] == db[i][0] && id_pw[1] != db[i][1]) 
        {
            halfClear = true;
        }
    }
    
    if(canClear == true)
    {
        answer = "login";
    }
    else
    {
        if(halfClear == true) answer = "wrong pw";
        else answer = "fail";
    }
    
    return answer;
}