#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        long long int a, b;
        cin >> a >> b;
        
        long long int result = a + b;
        cout << result;
        if( i != n - 1) cout << '\n';
    }
    

    return 0;
}