#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> numlist) {
    vector<int> answer;
    
    int numSize = numlist.size();
    
    for(int i = 0; i < numSize; i++)
    {
        if(numlist[i] % n != 0) continue;
        answer.push_back(numlist[i]);
    }
    
    return answer;
}