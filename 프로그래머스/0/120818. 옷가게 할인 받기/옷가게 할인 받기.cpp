#include <string>
#include <vector>

using namespace std;

int solution(int price) {
    int answer = 0;
    float discount = 0;
    
    if(price >= 500000)
    {
        discount = price * 0.2f;
    }
    else if(price >= 300000)
    {
        discount = price * 0.1f;
    }
    else if(price >= 100000)
    {
        discount = price * 0.05f;
    }
    
    answer = (int)(price - discount);
    return answer;
}