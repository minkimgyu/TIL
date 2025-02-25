#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    for(int i = n; i >= 1; i--)
    {
        if(n % i == 0 && m % i == 0)
        {
            answer.push_back(i);
            break;
        }
    }
    
    for(int i = m; i <= n * m; i++)
    {
        if(i % n == 0 && i % m == 0)
        {
            answer.push_back(i);
            break;
        }
    }
    
    return answer;
}