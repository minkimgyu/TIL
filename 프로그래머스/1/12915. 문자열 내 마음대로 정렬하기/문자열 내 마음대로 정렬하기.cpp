#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int num = 0;

bool compare(string a, string b)
{
    if(a[num] == b[num])
    {
        return a.compare(b) < 0;
    }
    else
    {
        return a[num] < b[num];
    }
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    num = n;
    
    sort(strings.begin(), strings.end(), compare);
    answer = strings;
    return answer;
}