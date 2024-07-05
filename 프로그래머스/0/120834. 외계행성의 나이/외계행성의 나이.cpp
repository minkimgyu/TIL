#include <string>
#include <vector>

using namespace std;

string solution(int age) {
    string answer = "";
    
    int mod = 10;
    int sum = 0;
    
    vector<char> items;
    
    while(1)
    {
        if(mod > age)
        {
            int add = (age % mod) - sum;
            sum += add;

            int value = add / (mod / 10) + 97;
            char alpha = (char)value;
            
            items.push_back(alpha);
            break;
        }
        
        int add = (age % mod) - sum;
        sum += add;

        int value = (add / (mod / 10)) + 97;
        char alpha = (char)value;
        
        items.push_back(alpha);
        mod *= 10;
    }
    
    while(items.size() != 0)
    {
        int size = items.size();
        answer.push_back(items[size - 1]);
        
        items.pop_back();
    }
    
    return answer;
}