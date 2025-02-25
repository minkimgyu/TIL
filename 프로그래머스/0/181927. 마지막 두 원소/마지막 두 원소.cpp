#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    
    if(num_list[num_list.size() - 1] > num_list[num_list.size() - 2])
    {
        for(int i = 0; i < num_list.size(); i++)
        {
            answer.push_back(num_list[i]);
        }
        
        answer.push_back(num_list[num_list.size() - 1] - num_list[num_list.size() - 2]);
    }
    else
    {
        for(int i = 0; i < num_list.size(); i++)
        {
            answer.push_back(num_list[i]);
        }
        
        answer.push_back(num_list[num_list.size() - 1] * 2);
    }
    
    return answer;
}