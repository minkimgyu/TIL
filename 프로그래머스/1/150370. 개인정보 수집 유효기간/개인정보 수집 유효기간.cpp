#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    vector<int> todayToInt;
    
    istringstream ss(today); // today
    string token;
    while(getline(ss, token, '.'))
    {
        todayToInt.push_back(stoi(token));
    }
    
    cout << todayToInt[0] << " " << todayToInt[1] << " " << todayToInt[2] << " ";
    
    
    map<string, int> termsMap; // terms
    for(int i = 0; i < terms.size(); i++)
    {
        vector<string> tmpTerms;
        
        istringstream ss(terms[i]);
        string token;
        while(getline(ss, token, ' '))
        {
            tmpTerms.push_back(token);
        }
        
        termsMap[tmpTerms[0]] = stoi(tmpTerms[1]);
    }
    
    for(int i = 0; i < privacies.size(); i++) // privacies
    {
        vector<string> privacy;
        vector<int> day;
        string token;
        
        istringstream ss(privacies[i]);
        while(getline(ss, token, ' '))
        {
            privacy.push_back(token);
        }
        
        istringstream ss1(privacy[0]);
        while(getline(ss1, token, '.'))
        {
            day.push_back(stoi(token));
        }
        
        
        int dayToAdd = termsMap[privacy[1]] * 28;
        dayToAdd -= 1;
        
        day[2] += dayToAdd;
        
        int monthToAdd = day[2] / 28;
        int leftDay = day[2] % 28;
        
        if(leftDay == 0) 
        {
            monthToAdd -= 1;
            leftDay = 28;
        }
        
        day[2] = leftDay;
        day[1] += monthToAdd;
        
        int yearToAdd = day[1] / 12;
        int leftMonth = day[1] % 12;
        
        if(leftMonth == 0)
        {
            yearToAdd -= 1;
            leftMonth = 12;
        }
        
        day[1] = leftMonth;
        day[0] += yearToAdd;
        
        cout << day[0] << " " << day[1] << " " << day[2] << " ";
        
        
        if(todayToInt[0] < day[0]) continue;
        
        if(todayToInt[0] == day[0] && todayToInt[1] < day[1]) continue;
        
        if(todayToInt[0] == day[0] && todayToInt[1] == day[1] && todayToInt[2] <= day[2]) continue;
        
        
        answer.push_back(i + 1);
    }
    
    return answer;
}