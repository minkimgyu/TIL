#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cout << 1999 << '\n';
    
    for(int i = 0; i < 1000; i++) cout << 1 << " ";
    for(int i = 0; i < 999; i++) cout << 1000 << " ";
    
    return 0;
}