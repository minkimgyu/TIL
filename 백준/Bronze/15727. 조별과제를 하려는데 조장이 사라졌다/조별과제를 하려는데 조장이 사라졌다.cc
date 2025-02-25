#include <iostream>
using namespace std;

int main()
{
    int divide = 5;
    int num;
    cin >> num;
    
    int divideCnt = num / 5;
    int modCnt = num % 5;
    
    if(modCnt > 0) divideCnt++;
    cout << divideCnt;
    
    return 0;
}