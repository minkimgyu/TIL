#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    int loopCnt = t.size() - p.size();
    int tSize = t.size();
    int pSize = p.size();
    
    unsigned long long int pToInt = stoull(p);
    
    for(int i = 0; i <= tSize - pSize; i++)
    {
        string item = t.substr(i, pSize);
        
        unsigned long long int itemToInt = stoull(item);
        if(pToInt >= itemToInt)
        {
            answer++;
        }
    }
    
    
    return answer;
}