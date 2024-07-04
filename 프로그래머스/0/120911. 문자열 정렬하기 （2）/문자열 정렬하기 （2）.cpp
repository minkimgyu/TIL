#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(char a, char b)
{
    return (int)a < (int)b;
}

string solution(string my_string) {
    string answer = "";
    
    transform(my_string.begin(), my_string.end(), my_string.begin(), ::tolower);
    sort(my_string.begin(), my_string.end(), compare); 
    
    return my_string;
}