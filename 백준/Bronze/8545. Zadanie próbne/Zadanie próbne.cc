#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    getline(cin, input);
    
    for(int i = input.size() - 1; i >= 0; i--)
    {
        cout<< input[i];
    }

    return 0;
}