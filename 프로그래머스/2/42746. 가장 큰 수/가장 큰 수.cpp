#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 이 방법은 100,000 루프를 돌려야 하기 때문에
// signal: segmentation fault (core dumped) 에러가 나온다

//bool compare(string a, string b)
//{
//    int maxStringSize = max(a.size(), b.size());
//    int aIndex, bIndex = 0;
//    
//    int aSize = a.size();
//    int bSize = b.size();
//    
//    for(int i = 0; i < maxStringSize; i++)
//    {
//        aIndex = bIndex = i;
//        if(aSize <= aIndex) aIndex = aSize - 1;
//        if(bSize <= bIndex) bIndex = bSize - 1;
//        
//        if(a[aIndex] == b[bIndex]) continue;
//        
//        return a[aIndex] > b[bIndex];
//    }
//    
//    return true;
//}

// 그래서 아래 방법으로 해야한다.
bool compare(string a, string b)
{
    return (a + b).compare(b + a) > 0;
}

// a = 6
// b = 10

// 6 + 10 --> 610
// 10 + 6 --> 106

vector<string> numStringArr;

string solution(vector<int> numbers) {
    string answer = "";
    
    bool isAllZero = true;
    
    for(int i = 0; i < numbers.size(); i++)
    {
        if(numbers[i] != 0) isAllZero = false;
        string number = to_string(numbers[i]);
        numStringArr.push_back(number);
    }
    
    if(isAllZero == true) return "0";
    sort(numStringArr.begin(), numStringArr.end(), compare);
    
    for(int k = 0; k < numStringArr.size(); k++)
    {
        for(int z = 0; z < numStringArr[k].size(); z++)
        {
            answer.push_back(numStringArr[k][z]);
        }
    }
    
    return answer;
}