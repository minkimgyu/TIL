#include <string>
#include <vector>
#include <map>
using namespace std;

// 31 10 45 1 6 19
// 31 0 0 1 25 44

// 31 10 45 1 6 19
// 31 10 45 1 25 44

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    // 최고 순위 -> 맞는 수 + 0의 수
    // 최저 순위 -> 맞는 수
    
    map<int, int> rank;
    rank[6] = 1;
    rank[5] = 2;
    rank[4] = 3;
    rank[3] = 4;
    rank[2] = 5;
    rank[1] = 6;
    rank[0] = 6;
    
    map<int, bool> lottoCorrect;
    for(int i = 0; i < win_nums.size(); i++)
    {
        lottoCorrect[win_nums[i]] = true;
    }
    
    int correctCount = 0;
    int zeroCount = 0;
    for(int i = 0; i < lottos.size(); i++)
    {
        if(lottos[i] == 0)
        {
            zeroCount++;
        }
        else if(lottoCorrect[lottos[i]] == true)
        {
            correctCount++;
        }
    }
    
    answer.push_back(rank[zeroCount + correctCount]);
    answer.push_back(rank[correctCount]);
    
    return answer;
}