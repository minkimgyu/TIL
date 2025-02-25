#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    getline(cin, input);
    
    for(int i = 0; i < input.size(); i++)
    {
        if(input[i] < 'a') // 대문자의 경우
        {
            input[i] = input[i] + ('a' - 'A');
        }
        else
        {
            input[i] = input[i] - ('a' - 'A');
        }
    }
    
    cout << input;

    return 0;
}