#include <string>
#include <vector>

using namespace std;

int arr[100001];

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    for(int i = 0; i < section.size(); i++)
    {
        if(arr[section[i]] == true) continue;
        
        answer++;
        for(int j = 0; j < m; j++)
        {
            if(section[i] + j > n) continue;
            arr[section[i] + j] = true;
        }
    }
    
    return answer;
}