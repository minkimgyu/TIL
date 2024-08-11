#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    
    map<string, int> newCall;
    for(int i = 0; i < players.size(); i++)
    {
        newCall[players[i]] = i;
    }
    
    for(int j = 0; j < callings.size(); j++)
    {
        int index = newCall[callings[j]];
        if(index == 0) continue;
        
        string beforePlayer = players[index - 1];
        string currentPlayer = players[index];
        
        players[index - 1] = currentPlayer;
        players[index] = beforePlayer;
        
        newCall[beforePlayer] += 1;
        newCall[currentPlayer] -= 1;
    }
    
    return players;
}