#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(int x) {
    bool answer = true;
    
    // 92
    // 9, 2
    
    int tmp = x;
    int sum = 0;
    
    while(tmp > 0)
    {
        sum += tmp % 10;
        tmp /= 10;
        
        // cout << tmp << " " << sum << "\n";
    }
    
    // cout << sum;
    
    if(x % sum == 0) return true;
    else return false;
}