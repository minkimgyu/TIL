#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    int card1Index = 0;
    int card2Index = 0;
    bool canClear = true;    
    
    for(int i = 0; i < goal.size(); i++)
    {
        string goalItem = goal[i];
        
        if(goalItem == cards1[card1Index]) card1Index++;
        else if(goalItem == cards2[card2Index]) card2Index++;
        else
        {
            canClear = false;
            break;
        }
    }
    
    if(canClear == true) answer = "Yes";
    else answer = "No";
    
    return answer;
}