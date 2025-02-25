#include <string>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

const int numCount = 10;
string num[numCount] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int solution(string s) {
    int answer = 0;
    int sSize = s.size();
    
    for(int i = 0; i < numCount; i++)
    {
        string numString = num[i];
        int index = 0;
        while(index < sSize && s.find(numString, index) != string::npos)
        {
            index = s.find(numString, index);
            s.erase(index, numString.size());
            
            string intToNumber;
            intToNumber.push_back(i + '0');
            
            s.insert(index, intToNumber);
            index += 1;
        }
    }
    
    answer = stoi(s);
    cout << answer;
    return answer;
}