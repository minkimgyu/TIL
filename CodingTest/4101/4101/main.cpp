#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1)
    {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0) break;

        if (n > m) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }

    return 0;
}