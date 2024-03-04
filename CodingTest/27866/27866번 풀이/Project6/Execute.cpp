#include <iostream>
#include <string>
using namespace std;

int main()
{
    int index;
    string st;

    cin >> st;
    cin >> index;

    cout << st[index - 1];
    return 0;
}