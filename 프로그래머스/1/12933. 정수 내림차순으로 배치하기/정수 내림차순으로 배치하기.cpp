#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(char a, char b)
{
    return a > b;
}

long long solution(long long n) {
    long long answer = 0;
    
    string item =  to_string(n);
    sort(item.begin(), item.end(), compare);
    
    cout << item;
    
    answer = stoll(item);
    return answer;
}