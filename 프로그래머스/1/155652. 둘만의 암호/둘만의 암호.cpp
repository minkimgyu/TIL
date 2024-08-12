#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;



string solution(string s, string skip, int index) {
    string answer = "";
    
    map<char, int> alpha;
    string inputList;
    
    int count = 0;
    
    for(int i = 0; i < 26; i++)
    {
        char item = (char)(i + 97);
        if(skip.find(item) != string::npos) continue;
        
        inputList.push_back(item);
        alpha[item] = count;
        count++;
    }
    
    for(int i = 0; i < s.size(); i++)
    {
        int alphaIndex = alpha[s[i]];
        
        int convertedIndex = (alphaIndex + index) % count;
        answer.push_back(inputList[convertedIndex]);
    }
    
    return answer;
}