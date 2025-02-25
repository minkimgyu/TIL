#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, vector<pair<int, int>>> genreMap;
map<string, int> genreSumMap;

bool compare(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

bool compare2(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    for(int i = 0; i < genres.size(); i++)
    {
        genreMap[genres[i]].push_back({i, plays[i]});
        
        genreSumMap[genres[i]] += plays[i];
    }
    
    vector<pair<string, int>> genreOrder;
    
    for(auto it = genreSumMap.begin(); it != genreSumMap.end(); it++)
    {
        genreOrder.push_back({it->first, it->second});
    }
    
    sort(genreOrder.begin(), genreOrder.end(), compare);
    
    
    for(int j = 0; j < genreOrder.size(); j++)
    {
        vector<pair<int, int>> genreArr = genreMap[genreOrder[j].first];
        sort(genreArr.begin(), genreArr.end(), compare2);
        
        for(int k = 0; k < genreArr.size(); k++)
        {
            if(k >= 2) break;
            
            answer.push_back(genreArr[k].first);
        }
    }
    
    return answer;
}