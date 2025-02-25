#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int num1, int num2) {
    string answer = "";
    
    char item1 = my_string[num1];
    char item2 = my_string[num2];
    
    my_string[num1] = item2;
    my_string[num2] = item1;
    
    answer = my_string;
    
    return answer;
}