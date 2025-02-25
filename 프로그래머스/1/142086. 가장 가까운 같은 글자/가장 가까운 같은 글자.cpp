#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    vector<pair<char, int>> stored;
    
    int sSize = s.size();
    for(int i = 0; i < sSize; i++)
    {
        bool canFind = false;
        int storedSize = stored.size();
        for(int j = 0; j < storedSize; j++)
        {
            if(s[i] == stored[j].first)
            {
                int lastIndex = stored[j].second;
                
                stored[j].second = i;
                answer.push_back(i - lastIndex);
                canFind = true;
                break;
            }
        }
        
        if(canFind == false)
        {
            stored.push_back({s[i], i});
            answer.push_back(-1);
        }
    }
    
    return answer;
}