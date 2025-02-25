#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, bool> phoneMap;

bool compare(string a, string b)
{
    return a.size() < b.size();
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end(), compare);
    
    for(int i = 0; i < phone_book.size(); i++)
    {
        string number = phone_book[i];
        string tmpNumber;
        for(int j = 0; j < number.size(); j++)
        {
            tmpNumber.push_back(number[j]);
            
            if(phoneMap[tmpNumber] == true)
            {
                answer = false;
                break;
            }
        }
        
        if(answer == false) break;
        else
        {
            phoneMap[number] = true;
        }
    }
    
    return answer;
}