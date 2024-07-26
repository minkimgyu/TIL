#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    int nameSize = name.size();
    
    for(int i = 0; i < photo.size(); i++)
    {
        int result = 0;
        for(int j = 0; j < photo[i].size(); j++)
        {
            for(int k = 0; k < nameSize; k++)
            {
                if(photo[i][j] == name[k])
                {
                    result += yearning[k];
                    break;
                }
            }
        }
        
        answer.push_back(result);
    }
    
    return answer;
}