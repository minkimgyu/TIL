#include <string>
#include <vector>

using namespace std;

int solution(int slice, int n) {
    int answer = 0;
    
    int cnt = n / slice;
    int mod = n % slice;
    
    if(mod > 0) cnt += 1;
    
    answer = cnt;
    
    return answer;
}