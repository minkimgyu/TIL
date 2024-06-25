#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    
    answer.push_back(0);
    answer.push_back(0);
    
    for(int i = 0; i < num_list.size(); i++)
    {
        if(num_list[i] % 2 == 0) answer[0] += 1;
        else answer[1] += 1;
    }
    
    return answer;
}