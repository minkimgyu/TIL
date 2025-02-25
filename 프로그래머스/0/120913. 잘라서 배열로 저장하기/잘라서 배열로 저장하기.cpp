#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    
    int strSize = my_str.size();
    
    int cnt = strSize / n;
    int left = strSize % n;
    
    int startIndex = 0;
    
    for(int i = 0; i < cnt; i++)
    {
        string str;
        
        for(int j = startIndex; j < startIndex + n; j++)
        {
            str.push_back(my_str[j]);
        }
        
        answer.push_back(str);
        startIndex += n;
    }
    
    if(left > 0)
    {
        string str;
        
        for(int i = startIndex; i < startIndex + left; i++)
        {
            str.push_back(my_str[i]);
        }

        answer.push_back(str);
    }
    
    return answer;
}