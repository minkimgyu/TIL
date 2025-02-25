#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            cout << '*';
        }
        
        if(i != n) cout << '\n';
    }
    
    return 0;
}