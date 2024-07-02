#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    vector<char> items;
    
    for(int i = 0; i < my_string.size(); i++)
    {
        bool canAdd = true;
        
        for(int j = 0; j < items.size(); j++)
        {
            if(items[j] == my_string[i])
            {
                canAdd = false;
                break;
            }
        }
        
        if(canAdd == true)
        {
             answer.push_back(my_string[i]);
            items.push_back(my_string[i]);
        }
    }
    
    return answer;
}