#include <iostream>
using namespace std;

int arr[9];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= 8; i++)
    {
        cin >> arr[i];
    }
    
    
    if((n == 1 && m == 2) || (n == 2 && m == 1))
    {
        cout << "ChongChong";
    }
    else
    {
        cout << "GomGom";
    }
    
    return 0;
}