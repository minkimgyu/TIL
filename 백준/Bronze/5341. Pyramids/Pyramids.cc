#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(1)
    {
        int item;
        cin >> item;
        
        if(item == 0) break;
        
        int result = 0;
        
        for(int i = 1; i <= item; i++)
        {
            result += i;
        }
        
        cout << result;
        cout << '\n';
    }
    
    return 0;
}