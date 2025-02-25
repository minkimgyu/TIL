#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    
    for(int i = 0; i < my_string.size(); i++)
    {
        int item = (int)my_string[i];
        if(item >= 97) continue;
        
        answer.push_back(item - 48);
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}