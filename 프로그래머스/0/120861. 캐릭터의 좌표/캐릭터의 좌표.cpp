#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;
    
    answer.push_back(0);
    answer.push_back(0);
    
    int xSize = board[0] / 2;
    int ySize = board[1] / 2;
    
    for(int i = 0; i < keyinput.size(); i++)
    {
        if(keyinput[i] == "left")
        {
            if(answer[0] == -xSize) continue;
            
            answer[0] -= 1;
        }
        else if(keyinput[i] == "right")
        {
            if(answer[0] == xSize) continue;
            answer[0] += 1;
        }
        else if(keyinput[i] == "up")
        {
            if(answer[1] == ySize) continue;
            answer[1] += 1;
        }
        else if(keyinput[i] == "down")
        {
            if(answer[1] == -ySize) continue;
            answer[1] -= 1;
        }
    }
    
    return answer;
}