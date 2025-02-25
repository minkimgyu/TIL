#include <string>
#include <vector>
#include <iostream>
using namespace std;

int recur(int coupon)
{
    if(coupon < 10)
    {
        coupon /= 10;
        return coupon;
    }
    
    int additiveCount = coupon / 10;
    int leftCount = coupon % 10;
        
    coupon = additiveCount + leftCount;
    return additiveCount + recur(coupon);
}

int solution(int chicken) {
    int answer = -1;
    answer = recur(chicken);
    
    return answer;
}